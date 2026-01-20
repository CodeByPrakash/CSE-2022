/* Program 10: Array using pointer, display via function */
#include <stdio.h>

void display(int *p,int n){
    int i;
    printf("Array elements: ");
    for(i=0;i<n;i++)
        printf("%d ",*(p+i));
    printf("\n");
}

int main(){
    int n,i;
    int a[100];
    int *p;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    p = a; /* pointer to array */
    display(p,n);
    return 0;
}