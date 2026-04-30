#include<stdio.h>

int main(){
    int rows,cols,i,j,k;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    printf("Enter number of columns:");
    scanf("%d",&cols);
    int a[rows][cols],b[rows][cols],c[rows][cols],d[rows][cols];
    
    // Asking for input for first matrix elements
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("Enter value of a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    // Asking for input for second matrix elements
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("Enter value of b[%d][%d]:",i,j);
            scanf("%d",&b[i][j]);
        }
    }

    // adding two matrices
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // multiplication of two matrices
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            d[i][j] = 0;
            for(k=0;k<cols;k++){
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // displaying the addition matrix
    printf("Resultant Addition matrix.....\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    // displaying the multiplication matrix
    printf("Resultant Multiplication matrix....\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}