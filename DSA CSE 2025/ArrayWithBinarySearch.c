/* Program 7: Array + add + delete + binary search */
#include <stdio.h>

void bubbleSort(int a[],int n){
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}
}

int binarySearch(int a[],int n,int key){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==key) return mid;
        else if(key<a[mid]) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main() {
    int a[100],n,i,ch,val,pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    bubbleSort(a,n);

    do{
        printf("\n1.Add\n2.Delete(by value)\n3.Search(binary)\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){
            if(n==100) printf("Array full\n");
            else{
                printf("Enter value to add: ");
                scanf("%d",&val);
                a[n++]=val;
                bubbleSort(a,n);
            }
        } else if(ch==2){
            printf("Enter value to delete: ");
            scanf("%d",&val);
            pos = binarySearch(a,n,val);
            if(pos==-1) printf("Not found\n");
            else{
                for(i=pos;i<n-1;i++) a[i]=a[i+1];
                n--;
                printf("Deleted %d\n",val);
            }
        } else if(ch==3){
            printf("Enter value to search: ");
            scanf("%d",&val);
            pos=binarySearch(a,n,val);
            if(pos==-1) printf("Not found\n");
            else printf("Found %d at position %d\n",val,pos);
        } else if(ch==4){
            printf("Array: ");
            for(i=0;i<n;i++) printf("%d ",a[i]);
            printf("\n");
        }
    }while(ch!=5);
    return 0;
}

