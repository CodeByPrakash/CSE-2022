/* Program 4: Check sparse matrix */
#include <stdio.h>
int main() {
    int a[10][10],m,n,i,j,zero=0,nonzero=0;
    printf("Enter rows and cols: ");
    scanf("%d%d",&m,&n);
    printf("Enter matrix elements:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0) zero++;
            else nonzero++;
        }
    if(zero > nonzero)
        printf("Matrix is sparse\n");
    else
        printf("Matrix is not sparse\n");
    return 0;
}

