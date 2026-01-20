#include<stdio.h>
int RecursiveBinarySearch(int Arr[], int low, int high, int key){
    int mid = (low+(high-low)/2);
    if(low > high){
        return -1;
    }
    if(Arr[mid] == key){
        return mid;
    }
    else if(Arr[mid] > key){
        return RecursiveBinarySearch(Arr, low, mid-1, key);
    }
    else{
        return RecursiveBinarySearch(Arr, mid+1, high, key);
    }
}
int main() {
    int n, result, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int Arr[n];
    printf("Enter %d sorted elements:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &Arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    result = RecursiveBinarySearch(Arr, 0, n-1, key);
    if(result == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index: %d\n", result);
        printf("Position is %d in 1 based indexing\n", result + 1);
    }
}