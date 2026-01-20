/* Program 11: struct school and 3 display methods */
#include <stdio.h>

struct school {
    char name[50];
    int roll;
};

void displayByValue(struct school s){
    printf("By value: Name=%s Roll=%d\n",s.name,s.roll);
}

void displayByPointer(struct school *ps){
    printf("By pointer: Name=%s Roll=%d\n",ps->name,ps->roll);
}

int main(){
    struct school s1;
    printf("Enter name and roll: ");
    scanf("%s%d",s1.name,&s1.roll);

    /* 1. Using struct variable directly */
    printf("Direct: Name=%s Roll=%d\n",s1.name,s1.roll);

    /* 2. Function with struct parameter */
    displayByValue(s1);

    /* 3. Function with pointer to struct */
    displayByPointer(&s1);

    return 0;
}

