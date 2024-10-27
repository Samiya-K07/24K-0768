//Given a matrix, find its saddle points

#include<stdio.h>

int main () {

int min, column_index, current_row, max, i = 0, count = 0; //declaration and initialization

// 0 1 2

// 7 4 5   0
// 9 2 6   1
// 1 3 8   2

int arr[3][3] = {{7,4,5},{9,2,6},{1,3,8}}; 

for (int i = 0; i < 3; i++) //incrementing regardless of the condition being true since we need to calculate this for each row and column of the array 
{
    min = arr[i][0]; //first element of every row
    column_index = 0; //incase the first element of said row is the smallest element in its row

    for (int j = 0; j < 3; j++) //columns are incrementing while for each row the value of i is same
    {
       if (min > arr[i][j]) //where i is constant
       {
            min = arr[i][j]; 
            column_index = j; 
       }
    }

    //now the smallest value in a row of a 2D-Array is stored along with its column index
    //to find the largest element in a column, the row will be incremented from the current value of i to row-1
    //we need to see if the max element in the column is equal to the value stored in the min variable
    //if it is then we are going to print that value as a saddle point and then continue this for every row's min element and its corresponding column to see if it qualifies as a saddle point
    
    max = min; 

    for (int k = 0; k < 3; k++) //k is the row number related to a specific column
    {
        if (max < arr[k][column_index]) //column number is constant
        {
            max = arr[k][column_index]; 
        }
    }
    
    if (min == max) //condition to check if it is indeed a saddle point
    {
        printf("%d is a saddle point!! The co-ordinates are (%d,%d)\n", min, i, column_index); 
        count++; 
    }
}

if (count == 0) //condition in the case where there are no saddle points
{
    printf("There are no saddle point(s) in the matrix!!\n"); 
}


    return 0; 
}