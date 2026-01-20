/* Program 22: Evaluate postfix expression */
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX],top=-1;
void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int main(){
    char post[100];
    int i,a,b,res;
    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s",post);
    for(i=0;post[i]!='\0';i++){
        if(isdigit(post[i])){
            push(post[i]-'0');
        } else{
            b=pop();
            a=pop();
            switch(post[i]){
                case '+': res=a+b; break;
                case '-': res=a-b; break;
                case '*': res=a*b; break;
                case '/': res=a/b; break;
                default: res=0;
            }
            push(res);
        }
    }
    printf("Result = %d\n",pop());
    return 0;
}

