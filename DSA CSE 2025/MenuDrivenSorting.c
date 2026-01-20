/* Program 25: Menu-driven sorting techniques */
#include <stdio.h>

void bubble(int a[],int n){
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}
}

void selection(int a[],int n){
    int i,j,min,t;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        t=a[i]; a[i]=a[min]; a[min]=t;
    }
}

void insertion(int a[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=a[i]; j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
}

void merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0,temp[100];
    while(i<=m && j<=r){
        if(a[i]<a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    k=0;
    for(i=l;i<=r;i++) a[i]=temp[k++];
}
void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(int a[],int low,int high){
    int pivot=a[high],i=low-1,j,t;
    for(j=low;j<high;j++){
        if(a[j]<=pivot){
            i++; t=a[i];a[i]=a[j];a[j]=t;
        }
    }
    t=a[i+1];a[i+1]=a[high];a[high]=t;
    return i+1;
}
void quickSort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

void printArray(int a[],int n){
    int i;
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int a[100],b[100],n,i,ch;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    do{
        for(i=0;i<n;i++) b[i]=a[i]; /* copy original each time */
        printf("\n1.Bubble\n2.Selection\n3.Merge\n4.Insertion\n5.Quick\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){ bubble(b,n); printArray(b,n); }
        else if(ch==2){ selection(b,n); printArray(b,n); }
        else if(ch==3){ mergeSort(b,0,n-1); printArray(b,n); }
        else if(ch==4){ insertion(b,n); printArray(b,n); }
        else if(ch==5){ quickSort(b,0,n-1); printArray(b,n); }
    }while(ch!=6);
    return 0;
}

