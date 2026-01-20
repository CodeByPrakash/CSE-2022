#include <stdio.h>

void insertion(int a[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    int a[] = {9,5,1,4,3};
    int n = 5, i;
    insertion(a,n);

    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

