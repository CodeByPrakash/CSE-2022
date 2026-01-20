/* Program 13: Menu-driven stack using array */
#include <stdio.h>
#define MAX 100

int stack[MAX], top=-1;

void push(int x){
    if(top==MAX-1) printf("Stack overflow\n");
    else stack[++top]=x;
}

int pop(){
    if(top==-1){ printf("Stack underflow\n"); return -1; }
    return stack[top--];
}

void display(){
    int i;
    if(top==-1){ printf("Stack empty\n"); return; }
    printf("Stack: ");
    for(i=top;i>=0;i--) printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    int ch,x;
    do{
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter value: "); scanf("%d",&x); push(x);
        } else if(ch==2){
            x=pop(); if(x!=-1) printf("Popped %d\n",x);
        } else if(ch==3){
            display();
        }
    }while(ch!=4);
    return 0;
}

