#include <stdio.h>
#include <stdlib.h>

void multiply(int **array1, int **array2, int **result, int a, int b, int c) 
{
    for (int i = 0; i < a; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < b; k++) 
            {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
}

void printMatrix(int **matrix, int rows, int columns)
 {
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        
        printf("\n");
    }
}

int main() {
    
    int a, b, c;

    printf("Enter rows and columns of the first matrix (m x n):\n");
    printf("Rows (m): ");
    scanf("%d", &a);

    printf("Columns (n): ");
    scanf("%d", &b);

    printf("Enter the number of columns for the second matrix (p): ");
    scanf("%d", &c);

    int **array1 = (int **)malloc(a * sizeof(int *));
    int **array2 = (int **)malloc(b * sizeof(int *));
    int **result = (int **)malloc(a * sizeof(int *));
    
    if (!array1 || !array2 || !result) 
    {
        printf("Memory Allocation failed!! Exiting....\n");
        return 1;
    }

    for (int i = 0; i < a; i++) 
    {
        array1[i] = (int *)malloc(b * sizeof(int));
        
        if (!array1[i]) 
        {
            printf("Memory Allocation failed!! Exiting....\n");
            return 1;
        }
    }

    for (int i = 0; i < b; i++) 
    {
        array2[i] = (int *)malloc(c * sizeof(int));
        
        if (!array2[i]) 
        {
            printf("Memory Allocation failed!! Exiting....\n");
            return 1;
        }
    }

    for (int i = 0; i < a; i++) 
    {
        result[i] = (int *)malloc(c * sizeof(int));
        
        if (!result[i]) 
        {
            printf("Memory Allocation failed!! Exiting....\n");
            return 1;
        }
    }

    printf("Enter elements of the first matrix (m x n):\n");
    for (int i = 0; i < a; i++) 
    {
        for (int j = 0; j < b; j++) 
        {
            scanf("%d", &array1[i][j]);
        }
    }

    printf("Enter elements of the second matrix (n x p):\n");
    for (int i = 0; i < b; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            scanf("%d", &array2[i][j]);
        }
    }

    multiply(array1, array2, result, a, b, c);

    printf("Resultant matrix (m x p):\n");
    printMatrix(result, a, c);

    for (int i = 0; i < a; i++) 
    {
        free(array1[i]);
        free(result[i]);
    }
    
    for (int i = 0; i < b; i++) 
    {
        free(array2[i]);
    }

    free(array1);
    free(array2);
    free(result);

    return 0;
}