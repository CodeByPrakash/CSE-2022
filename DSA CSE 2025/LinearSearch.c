#include<stdio.h>
int main() {
    int size, i, key, position, found = -1;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i=0; i< size; i++) {
        if(arr[i] == key) {
            position = i;
            found = 1;
            printf("Element found at index: %d\n", position);
            printf("Postion is %d in 1 based indexing\n", position + 1);
            break;
        }
    }
    if (found == -1)
    {
        printf("Element not found\n");
    }
    
}