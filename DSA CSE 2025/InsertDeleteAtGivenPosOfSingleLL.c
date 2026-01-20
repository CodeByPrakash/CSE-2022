#include<stdlib.h>
#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = NULL;
    if(head == NULL) {
        head = NewNode;
    }
    else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
    return head;
}
struct Node* InsertAtPosition(int data, int position) {
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = NULL;
    if(position == 0) {
        NewNode->next = head;
        head = NewNode;
        return head;
    }
    struct Node* temp = head;
    for(int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of bounds\n");
        free(NewNode);
        return head;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
    return head;
}
struct Node* DeleteAtPosition(int position) {
    if(head == NULL) {
        printf("List is empty, nothing to delete\n");
        return head;
    }
    struct Node* temp = head;
    if(position == 0) {
        head = head->next;
        free(temp);
        return head;
    }
    for(int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return head;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}
void Display(){
    struct Node* temp = head;
    printf("Single Linked List:\n");
    while(temp != NULL){
        printf("| %p <- %d -> %p | ", temp, temp->data, temp->next);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);
    createNode(50);
    printf("Original List:\n");
    Display();
    InsertAtPosition(25, 2);
    printf("List after inserting 25 at position 2:\n");
    Display();
    DeleteAtPosition(4);
    printf("List after deleting element at position 4:\n");
    Display();
}