/* Program 12: Array of student structures */
#include <stdio.h>

struct student {
    char name[50];
    int roll;
    int m1,m2,m3;
};

int main(){
    struct student s[5];
    int i;
    printf("Enter details for 5 students (name roll m1 m2 m3):\n");
    for(i=0;i<5;i++)
        scanf("%s%d%d%d%d",s[i].name,&s[i].roll,&s[i].m1,&s[i].m2,&s[i].m3);

    printf("\nStudent details:\n");
    for(i=0;i<5;i++)
        printf("Name:%s Roll:%d Marks:%d %d %d\n",
               s[i].name,s[i].roll,s[i].m1,s[i].m2,s[i].m3);
    return 0;
}

