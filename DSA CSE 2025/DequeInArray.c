/* Program 16: Deque using array (simple version) */
#include <stdio.h>
#define MAX 10

int dq[MAX];
int front=-1,rear=-1;

void insertFront(int x){
    if((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Deque overflow\n");
    else{
        if(front==-1){ front=rear=0; }
        else if(front==0) front=MAX-1;
        else front--;
        dq[front]=x;
    }
}

void insertRear(int x){
    if((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Deque overflow\n");
    else{
        if(front==-1){ front=rear=0; }
        else if(rear==MAX-1) rear=0;
        else rear++;
        dq[rear]=x;
    }
}

void deleteFront(){
    if(front==-1) printf("Deque underflow\n");
    else{
        printf("Deleted from front: %d\n",dq[front]);
        if(front==rear) front=rear=-1;
        else if(front==MAX-1) front=0;
        else front++;
    }
}

void deleteRear(){
    if(rear==-1) printf("Deque underflow\n");
    else{
        printf("Deleted from rear: %d\n",dq[rear]);
        if(front==rear) front=rear=-1;
        else if(rear==0) rear=MAX-1;
        else rear--;
    }
}

void display(){
    int i;
    if(front==-1){ printf("Deque empty\n"); return; }
    printf("Deque: ");
    i=front;
    while(1){
        printf("%d ",dq[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
    }
    printf("\nfront=%d rear=%d\n",front,rear);
}

int main(){
    int ch,x;
    do{
        printf("\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){ printf("Enter value: "); scanf("%d",&x); insertFront(x); }
        else if(ch==2){ printf("Enter value: "); scanf("%d",&x); insertRear(x); }
        else if(ch==3) deleteFront();
        else if(ch==4) deleteRear();
        else if(ch==5) display();
    }while(ch!=6);
    return 0;
}

