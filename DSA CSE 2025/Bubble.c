#include <stdio.h>

void bubble(int a[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}

int main() {
    int a[] = {5,4,3,2,1};
    int n = 5;
    bubble(a,n);
    int i;

    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

