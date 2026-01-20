/* Program 15: Circular queue using array */
#include <stdio.h>
#define MAX 5

int cq[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    if((rear+1)%MAX == front) printf("Circular Queue overflow\n");
    else{
        if(front==-1) front=0;
        rear=(rear+1)%MAX;
        cq[rear]=x;
        printf("Enqueued %d\n",x);
    }
}

void dequeue(){
    if(front==-1) printf("Circular Queue underflow\n");
    else{
        printf("Dequeued %d\n",cq[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1)%MAX;
    }
}

void display(){
    int i;
    if(front==-1){ printf("Queue empty\n"); return; }
    printf("Circular Queue: ");
    i=front;
    while(1){
        printf("%d ",cq[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
    }
    printf("\nfront=%d rear=%d\n",front,rear);
}

int main(){
    int ch,x;
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){ printf("Enter value: "); scanf("%d",&x); enqueue(x); }
        else if(ch==2) dequeue();
        else if(ch==3) display();
    }while(ch!=4);
    return 0;
}

