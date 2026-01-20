#include <stdio.h>

int main() {
    int matrix[4][4];
    int sparse[20][3];   // Maximum possible non-zero elements
    int i, j, k = 1;

    printf("Enter elements of 4x4 matrix:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Original Matrix(row, col):\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d\t ", matrix[i][j]);
        }
        printf("\n");
    }

    sparse[0][0] = 4; // number of rows
    sparse[0][1] = 4; // number of columns
    sparse[0][2]= 0; // number of non-zero elements
    // Count non-zero elements and store in sparse matrix
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=matrix[i][j];
                sparse[0][2]++;
                k++;
            }
        }
    }

    // Display sparse matrix
    printf("\nSparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= sparse[0][2]; i++) {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
    return 0;
}