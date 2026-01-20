#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

PolyNode* createNode(int coeff, int exp) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

PolyNode* insertSorted(PolyNode* head, int coeff, int exp) {
    if (coeff == 0) return head; 

    PolyNode* newNode = createNode(coeff, exp);

    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    PolyNode* current = head;
    PolyNode* prev = NULL;

    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        free(newNode);
        if (current->coeff == 0) {

            if (prev)
                prev->next = current->next;
            else
                head = current->next;
            free(current);
        }
        return head;
    }


    newNode->next = current;
    if (prev)
        prev->next = newNode;
    else
        head = newNode;

    return head;
}


PolyNode* inputPolynomial() {
    int n, coeff, exp, i=0;
    PolyNode* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
	 {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        head = insertSorted(head, coeff, exp);
    }

    return head;
}

PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;

    while (poly1 != NULL) {
        result = insertSorted(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertSorted(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(PolyNode* head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    while (head != NULL) {
    	if(head->exp > 0)
    	{
    		printf("%dx^%d", head->coeff, head->exp);
		}
        else
        {
        	printf("%d", head->coeff);
		}
        head = head->next;
        if (head != NULL && head->coeff >= 0)
            printf(" + ");
    }
    printf("\n");
}

void freePolynomial(PolyNode* head) {
    PolyNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
	int choice=1;
	while (choice != 0)
	{
			printf("--- POLYNOMIAL ADDITION ---\n");
			printf("Enter first polynomial -\n");
		    PolyNode* poly1 = inputPolynomial();
		
		    printf("\nEnter second polynomial -\n");
		    PolyNode* poly2 = inputPolynomial();
		
		    PolyNode* sum = addPolynomials(poly1, poly2);
		
		    printf("\nFirst Polynomial: ");
		    displayPolynomial(poly1);
		    printf("Second Polynomial: ");
		    displayPolynomial(poly2);
		    printf("Sum Polynomial: ");
		    displayPolynomial(sum);
		
		
		    freePolynomial(poly1);
		    freePolynomial(poly2);
		    freePolynomial(sum);
		    
		    printf("\nWish To Continue (Start/End)(1/0): ");
			scanf("%d", &choice);
	}
    return 0;
}
