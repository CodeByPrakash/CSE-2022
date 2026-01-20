/* Program 24: Menu-driven BST */
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insertNode(struct node* root,int x){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=x; root->left=root->right=NULL;
    } else if(x<root->data)
        root->left=insertNode(root->left,x);
    else
        root->right=insertNode(root->right,x);
    return root;
}

struct node* minNode(struct node* root){
    while(root && root->left!=NULL) root=root->left;
    return root;
}

struct node* deleteNode(struct node* root,int key){
    if(root==NULL) return root;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            struct node* t=root->right;
            free(root); return t;
        }else if(root->right==NULL){
            struct node* t=root->left;
            free(root); return t;
        }else{
            struct node* t=minNode(root->right);
            root->data=t->data;
            root->right=deleteNode(root->right,t->data);
        }
    }
    return root;
}

void inorder(struct node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void displayTree(struct node* root,int space){
    int i;
    if(root==NULL) return;
    space+=5;
    displayTree(root->right,space);
    printf("\n");
    for(i=5;i<space;i++) printf(" ");
    printf("%d",root->data);
    displayTree(root->left,space);
}

int main(){
    struct node* root=NULL;
    int ch,x;
    do{
        printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Display visually\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){ printf("Enter value: "); scanf("%d",&x); root=insertNode(root,x); }
        else if(ch==2){ printf("Enter value to delete: "); scanf("%d",&x); root=deleteNode(root,x); }
        else if(ch==3){ printf("Inorder: "); inorder(root); printf("\n"); }
        else if(ch==4){ displayTree(root,0); printf("\n"); }
    }while(ch!=5);
    return 0;
}

