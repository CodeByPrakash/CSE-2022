/* Program 17: Menu-driven singly linked list (insert + delete) */
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insertBeg(int x){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=x; n->next=head;
    head=n;
}
void insertEnd(int x){
    struct node *n=(struct node*)malloc(sizeof(struct node)),*t;
    n->data=x; n->next=NULL;
    if(head==NULL) head=n;
    else{
        t=head; while(t->next!=NULL) t=t->next;
        t->next=n;
    }
}
void deleteBeg(){
    struct node *t;
    if(head==NULL){ printf("List empty\n"); return; }
    t=head; head=head->next;
    printf("Deleted %d\n",t->data);
    free(t);
}
void deleteEnd(){
    struct node *t=head,*prev=NULL;
    if(head==NULL){ printf("List empty\n"); return; }
    if(head->next==NULL){
        printf("Deleted %d\n",head->data);
        free(head); head=NULL; return;
    }
    while(t->next!=NULL){ prev=t; t=t->next; }
    prev->next=NULL;
    printf("Deleted %d\n",t->data);
    free(t);
}
void display(){
    struct node *t=head;
    if(t==NULL){ printf("List empty\n"); return; }
    printf("List: ");
    while(t!=NULL){ printf("%d ",t->data); t=t->next; }
    printf("\n");
}

int main(){
    int ch,x;
    do{
        printf("\n1.Insert begin\n2.Insert end\n3.Delete begin\n4.Delete end\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){ printf("Enter value: "); scanf("%d",&x); insertBeg(x); }
        else if(ch==2){ printf("Enter value: "); scanf("%d",&x); insertEnd(x); }
        else if(ch==3) deleteBeg();
        else if(ch==4) deleteEnd();
        else if(ch==5) display();
    }while(ch!=6);
    return 0;
}

