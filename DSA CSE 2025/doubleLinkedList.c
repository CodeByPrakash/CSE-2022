#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->prev = n->next = NULL;
    return n;
}

void insertAtBeginning(Node** head, int data) {
    Node* n = createNode(data);
    if (*head) 
	{ 
		n->next = *head; 
		(*head)->prev = n; 
	}
    *head = n;
}

void insertAtEnd(Node** head, int data) {
    Node* n = createNode(data);
    if (!*head) 
	{ 
		*head = n; 
		return; 
	}
    Node* t = *head;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

void insertInEmptyList(Node** head, int data) {
    Node* t = *head;
	if(t=NULL)
	{
		t->data = data;
    	t->prev = NULL;
    	t->next = NULL;
    	t = t->next;
	}
	else
	{
		printf("Linked List Is Not Empty");
	}
}


void deleteRelativeTo(Node** head, int key, int after) {
    Node* t = *head;
    while (t && t->data != key) 
		t = t->next;
    if (!t) 
	{ 
		printf("Key %d not found.\n", key); 
		return; 
	}
    Node* del = after ? t->next : t->prev;
    if (!del) 
	{ 
		printf("No node to delete %s %d.\n", after ? "after" : "before", key); 
		return; 
	}
    if (del->prev) 
	del->prev->next = del->next;
    else *head = del->next;
    if (del->next) 
	del->next->prev = del->prev;
    free(del);
}


void display(Node* head) {
	if(head != NULL)
	{
		while (head) 
		{
			printf("[ %d --> %d ]", head->data, head->next);
			head = head->next; 
		}
    	printf("\n");
	}
	else
	{
		printf("\n:( Linked List Is Empty.\n");
	}
    
}

void deleteData(Node** head, int key) {
	Node* t = *head;
	while (t && t->data != key)
	{
		t = t->next;
	}
	if (!t) 
	{ 
		printf("Key %d not found.\n", key); 
		return; 
	}
    Node* delt = t;
    if (!delt) 
	{ 
		printf("No node to delete %d.\n", key); 
		return; 
	}
	else
	{
		if(delt->prev == NULL && delt->next != NULL)
		{
			*head = delt->next;
			free(delt);
			return;
		}
		else if (delt->next == NULL && delt->prev == NULL)
		{
			*head = NULL;
			free(delt);
			return;
		}
		else if(delt->next == NULL && delt->prev != NULL)
		{
			delt->prev->next = NULL;
			free(delt);
			return;
		}
		delt->prev->next = delt->next;
		delt->next->prev = delt->prev;
		free(delt);	
	}
	return;
}

int main() {
    Node* head = NULL;
    int ch, data, key, item, after;
    do {
        printf("\n1.Insert At Begin \n2.Insert At End \n3.Insert Into The Empty List. \n4.Delete \n5.Delete Relavant To(After/Before) \n6.Display \n0.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
				printf("Data: "); 
				scanf("%d", &data); 
				insertAtBeginning(&head, data);
				break;
            case 2: 
				printf("Data: "); 
				scanf("%d", &data); 
				insertAtEnd(&head, data); 
				break;
            case 3: 
				printf("Data: "); 
				scanf("%d", &data);
                insertInEmptyList(&head, data); 
				break;
			case 4:
            	printf("Data To Delete: "); 
				scanf("%d", &key);
            	deleteData(&head, key);
            	break;
            case 5: 
				printf("Data: "); 
				scanf("%d", &key);
                printf("After(1)/Before(0): "); 
				scanf("%d", &after);
                deleteRelativeTo(&head, key, after); break;
            case 6: 
				display(head); 
				break;
        }
    } while (ch != 0);
    return 0;
}
