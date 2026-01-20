/* Program 2: Insert element into array */
#include <stdio.h>
int main() {
    int a[100], n, i, pos, val;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter position (0 to %d): ",n);
    scanf("%d",&pos);
    printf("Enter value to insert: ");
    scanf("%d",&val);

    if(pos<0 || pos>n) {
        printf("Invalid position\n");
        return 0;
    }

    for(i=n;i>pos;i--)
        a[i]=a[i-1];
    a[pos]=val;
    n++;

    printf("Array after insertion:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

