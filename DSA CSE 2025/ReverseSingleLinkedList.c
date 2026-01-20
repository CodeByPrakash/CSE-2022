#include<stdlib.h>
#include<stdio.h>
struct Node {
    int data;
    struct Node* link;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->link = NULL;
    if(head == NULL) {
        head = NewNode;
    }
    else {
        struct Node* temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = NewNode;
    }
    return head;
}

struct Node* RevesedList() {
    struct Node* prev = NULL;
    struct Node* temp = head;
    while(temp != NULL) {
        struct Node* reverse = temp->link;
        temp->link = prev;
        prev = temp;
        temp = reverse;
    }
    head = prev;
    return head;
}

void Display(){
    struct Node* temp = head;
    printf("Single Linked List:\n");
    while(temp != NULL){
        printf("| %p <- %d -> %p | ", temp, temp->data, temp->link);
        printf("\n");
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);
    createNode(50);
    printf("Original List:\n");
    Display();
    RevesedList();
    printf("Reversed List:\n");
    Display();
    return 0;
}