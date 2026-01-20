/* Program 14: Menu-driven queue using array */
#include <stdio.h>
#define MAX 100

int q[MAX];
int front=-1,rear=-1;

void insert(int x){
    if(rear==MAX-1) printf("Queue overflow\n");
    else {
        if(front==-1) front=0;
        q[++rear]=x;
    }
}

int delet(){
    int x;
    if(front==-1 || front>rear){ printf("Queue underflow\n"); return -1; }
    x=q[front++];
    if(front>rear) front=rear=-1;
    return x;
}

void display(){
    int i;
    if(front==-1){ printf("Queue empty\n"); return; }
    printf("Queue: ");
    for(i=front;i<=rear;i++) printf("%d ",q[i]);
    printf("\n");
}

int main(){
    int ch,x;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){ printf("Enter value: "); scanf("%d",&x); insert(x); }
        else if(ch==2){ x=delet(); if(x!=-1) printf("Deleted %d\n",x); }
        else if(ch==3) display();
    }while(ch!=4);
    return 0;
}

