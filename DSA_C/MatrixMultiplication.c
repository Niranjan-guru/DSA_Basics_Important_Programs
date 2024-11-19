#include <stdio.h>
#include <stdlib.h>

int main(){

    int rows1,rows2,cols1,cols2;
    int i,j,k;
    printf("Enter the number of rows and columns of the 1st matrix A: ");
    scanf("%d %d",&rows1,&cols1);
    int** matrixA = (int**)malloc(rows1*sizeof(int*));
    for(i=0;i<rows1;i++){
        matrixA[i] = (int*)malloc(cols1*sizeof(int));
    }
    printf("Enter the values of the matrix: ");
    for(i=0;i<rows1;i++){
        for(j=0;j<cols1;j++){
            printf("A[%d][%d]",i,j);
            scanf("%d",&matrixA[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the 2nd matrix B: ");
    scanf("%d %d",&rows2,&cols2);
    if(cols1 != rows2){
        free(matrixA);
        for(i=0;i<rows1;i++){
            free(matrixA[i]);
        }
        printf("Matrix Multiplication not possible\n");
        return 0;
    }

    int** matrixB = (int**)malloc(rows2*sizeof(int*));
    for(i=0;i<rows2;i++){
        matrixB[i] = (int*)malloc(cols2*sizeof(int));
    }
    printf("Enter the values of the matrix: ");
    for(i=0;i<rows2;i++){
        for(j=0;j<cols2;j++){
            printf("B[%d][%d]",i,j);
            scanf("%d",&matrixB[i][j]);
        }
    }
    int** resMatrixC = (int**)calloc(rows2,sizeof(int*));
    for(i=0;i<rows2;i++){
        resMatrixC[i] = (int*)calloc(cols1,sizeof(int));
    }

    for(i=0;i<rows2;i++){
        for(j=0;j<cols1;j++){
            for(k=0;k<cols1;k++){
                resMatrixC[i][j] += matrixA[i][k]*matrixB[k][j];
            }
        }
    }
    printf("The Resultant Matrix is: \n");
    for(i=0;i<rows2;i++){
        for(j=0;j<cols1;j++){
            printf("%d ",resMatrixC[i][j]);
        }
        printf("\n");
    }
    return 0;
}