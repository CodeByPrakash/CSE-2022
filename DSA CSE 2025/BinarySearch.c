#include<stdio.h>

void main(){
    int i, j , n, key, mid, low, high, position, found = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array Sorrted in ascending order\n");
    for(i=0; i< n-1; i++){
        for(j=0; j < n-1; j++) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    mid = (low + (high - low) / 2);
    while(low <= high){
        if(arr[mid] == key){
            position = mid;
            found = 1;
            printf("Element found at index: %d\n", position);
            printf("Position is %d in 1 based indexing\n", position + 1);
            break;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        mid = (low + (high - low) / 2);
    }
    if(found == -1){
        printf("Element not found in the array\n");
    }
}