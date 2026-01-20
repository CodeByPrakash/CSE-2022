#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE];
int front =-1, rear=-1;

void enqueue(int x) {
	if(rear == SIZE-1)
		printf("Overflow");
	else {
		if(front == -1) {
			front = 0;	
		}
		queue[++rear] = x;
	}
}

void dequeue() {
	if(front == -1 || front > rear) {
		printf("Underflow");
	}
	else {
	 queue[front++];
	}
}

void display() {
	int i;
	if (front == -1) {
		printf("Underflow");
	}
	else {
		printf("Queue: ");
		for(i=front; i <= rear; i++) {
			printf("%d ", queue[i]);
		}
		printf("\n");
	}
}

int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	dequeue();
	display();
	return 0;
}
