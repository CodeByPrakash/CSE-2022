#include<stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* link;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->link = NULL;
	
	if(head == NULL) {
		head = newNode;
	}
	else{
		struct Node* temp = head;
		while(temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = newNode;
	}
	

}
struct Node* InsertAtBegin(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->link = head;
	head = newNode;
	return head;
}

struct Node* InsertAtPosition(int data, int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = data;
    newNode->link = NULL;

    // Insert at head
    if(position == 0){
        newNode->link = head;
        head = newNode;
        return head;
    }

    // Traverse to position-1
    struct Node* temp = head;
    for(int i = 0; i < position-1; i++){
        if(temp == NULL){
            printf("Position out of bounds\n");
            free(newNode);
            return head;
        }
        temp = temp->link;
    }

    if(temp == NULL){
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }

    // Insert new node
    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}

void DeleteAtEnd() {
    if(head == NULL) {
        printf("The List is empty\n");
        return;
    }

    // If only one node
    if(head->link == NULL) {
        free(head);
        head = NULL;
        return;
    }

    // More than one node
    struct Node* temp = head;
    while(temp->link->link != NULL) {
        temp = temp->link;
    }
	printf("Deleted element is: %d\n", temp->link->data);
    free(temp->link);
    temp->link = NULL;
}

void display(){
	printf("\n");
	struct Node* temp = head;
	while(temp != NULL) {
		printf("%d -> %p\n", temp->data, temp->link);
		temp = temp->link;
	}
}
int main() {
	int data;
	createNode(10);
	createNode(20);
	createNode(30);
	display();
	InsertAtPosition(25, 2);
	display();
	return 0;
}