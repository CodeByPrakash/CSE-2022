#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node* root, int x) {
    if(root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* delete(struct node* root, int x) {
    if(root == NULL) return root;

    if(x < root->data)
        root->left = delete(root->left, x);
    else if(x > root->data)
        root->right = delete(root->right, x);
    else {
        if(root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    root = delete(root, 20);
    printf("After delete, Inorder: ");
    inorder(root);
    return 0;
}

