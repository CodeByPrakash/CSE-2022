#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;
    int temp[100];


    while(i <= m && j <= r) {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }


    while(i <= m)
        temp[k++] = a[i++];


    while(j <= r)
        temp[k++] = a[j++];


    k = 0;
    for(i = l; i <= r; i++)
        a[i] = temp[k++];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = 6, i;

    printf("Original Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    mergeSort(a, 0, n - 1);

    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    return 0;
}

