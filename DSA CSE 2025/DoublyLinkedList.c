#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    if(head == NULL) {
        head = NewNode;
    }
    else {
        struct Node* temp = head;
        while(temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = NewNode;
        NewNode->left = temp;
    }
    return head;
}
struct Node* DeleteAtEnd() {
    struct Node* temp = head;
    if(head == NULL) {
        printf("List is empty, nothing to delete\n");
        return head;
    }
    else
    {
        while(temp->right != NULL) {
            temp = temp->right;
        }
        if(temp->left != NULL) {
            temp->left->right = NULL;
        }
        else {
            head = NULL; // List had only one node
        }
        free(temp);
        return head;
    }
}
void Display(){
    struct Node* temp = head;
    printf("Doubly Linked List in forward direction:\n");
    while(temp != NULL){
        printf("| %p <- %d -> %p | ", temp->left, temp->data, temp->right);
        printf("\n");
        temp = temp->right;
    }
    printf("\n");
}

int main() {
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);
    Display();
    DeleteAtEnd();
    Display();
    return 0;
}