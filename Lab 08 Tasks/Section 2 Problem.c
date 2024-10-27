//Printing transpose of a matrix (by first storing it in another matrix and printing that matrix)

#include<stdio.h>

int main () {

int rows, columns; //declaration

printf("Enter no. of rows of your matrix: "); //prompt the user for input (rows and columns both)
scanf("%d", &rows); 

printf("Enter no. of columns of your matrix: "); 
scanf("%d", &columns); 

int arr[rows][columns]; //declare the array based on the user input

printf("Enter the elements of your matrix:\n"); //prompt the user for input of the elements of the matrix

for (int i = 0; i < rows; i++)
{
    for ( int j = 0; j < columns; j++) 
    {
        scanf("%d", &arr[i][j]); 

    }   
}

printf("\nYour matrix is:\n"); //displaying the matrix to the user first before displaying the transpose

for (int i = 0; i < rows; i++)
{
    for ( int j = 0; j < columns; j++) 
    {
        printf("%d ", arr[i][j]); 

    } 

    printf("\n"); 
}

int transpose[columns][rows]; //declaring another array/matrix which is the transpose

for (int i = 0; i < columns; i++) //in the outer loop; columns are incrementing
{
    for (int j = 0; j < rows; j++) //in the inner loop; rows are incrementing
    {
       transpose[i][j] = arr[j][i]; //since rows are incrementing in the inner loop and arr[rows][columns] and the rows are associated with j; now it is arr[j][i] which always gives the correct answer (can do a dry run)
    }
}

printf("\nThe transpose of your matrix is:\n"); //displaying the transpose of the matrix

for (int i = 0; i < columns; i++) 
{
    for (int j = 0; j < rows; j++) 
    {
        printf("%d ", transpose[i][j]); 
    }
    
    printf("\n"); 
}

    return 0;
}