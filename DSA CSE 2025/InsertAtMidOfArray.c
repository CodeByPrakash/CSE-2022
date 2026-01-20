#include<stdio.h>

void main() {
    int n, mid, i, data;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n+1]; // +1 to accommodate the new element
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mid = n / 2; // Find the middle index
    printf("Enter the element to insert at the middle: ");
    scanf("%d", &data);
    // Shift elements to the right from mid index
    for(i = n; i > mid; i--) {
        arr[i] = arr[i - 1];
    }
    arr[mid] = data; // Insert the new element at mid index
    printf("Array after insertion at the middle:\n");
    for(i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}