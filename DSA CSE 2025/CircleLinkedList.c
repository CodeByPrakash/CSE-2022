#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if((rear + 1) % SIZE == front) {
        printf("Queue Overflow (Circular)\n");
    }
    else {
        if(front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        cq[rear] = x;
        printf("Inserted %d\n", x);
    }
}

void dequeue() {
    if(front == -1) {
        printf("Queue Underflow (Circular)\n");
    }
    else {
        printf("Deleted %d\n", cq[front]);
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if(front == -1) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Circular Queue: ");
        int i = front;
        while(i != rear) {
            printf("%d ", cq[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d ", cq[rear]);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    display();

    enqueue(50);
    display();

    enqueue(60);
    return 0;
}

