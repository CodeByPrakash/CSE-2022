#include<stdio.h>
int LinearSearch(int Arr[], int n, int key){
    if(n==0){
        return -1;
    }
    if(Arr[n-1]==key){
        return n-1;
    }
    return LinearSearch(Arr, n-1, key);
}

int main(){
    int n, result, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int Arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &Arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    result = LinearSearch(Arr, n, key);
    if(result == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index: %d\n", result);
    }
}