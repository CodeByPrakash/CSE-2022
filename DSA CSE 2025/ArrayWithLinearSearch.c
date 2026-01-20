/* Program 6: Array with add, delete, search using linear search */
#include <stdio.h>
int main() {
    int a[100],n,i,ch,val,pos,found;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    do {
        printf("\n1.Add\n2.Delete(by value)\n3.Search(linear)\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1) {
            if(n==100) printf("Array full\n");
            else {
                printf("Enter value to add: ");
                scanf("%d",&val);
                a[n++]=val;
            }
        } else if(ch==2) {
            printf("Enter value to delete: ");
            scanf("%d",&val);
            found=0;
            for(i=0;i<n;i++)
                if(a[i]==val) { pos=i; found=1; break; }
            if(!found) printf("Not found\n");
            else {
                for(i=pos;i<n-1;i++) a[i]=a[i+1];
                n--;
                printf("Deleted %d from position %d\n",val,pos);
            }
        } else if(ch==3) {
            printf("Enter value to search: ");
            scanf("%d",&val);
            found=0;
            for(i=0;i<n;i++)
                if(a[i]==val) { printf("Found %d at position %d\n",val,i); found=1; break; }
            if(!found) printf("Not found\n");
        } else if(ch==4) {
            printf("Array: ");
            for(i=0;i<n;i++) printf("%d ",a[i]);
            printf("\n");
        }
    } while(ch!=5);
    return 0;
}

