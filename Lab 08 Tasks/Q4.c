//Multiplication of two given 3x3 matrices 

#include<stdio.h>

int main () {

// 1 2 3
// 4 5 6
// 7 8 9

int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; //declaring and initializing the 1st array

// 10 11 12 
// 13 14 15
// 16 17 18

int b[3][3] = {{10,11,12},{13,14,15},{16,17,18}}; //declaring and initializing the second array

int resultant[3][3]; 
int limit = 3; //column number for a[][] and row number for b[][]



for (int i = 0; i < 3; i++) //multiplication
{
    for (int j = 0; j < 3; j++)
    {
        //ith row of a[][] and jth column of b[][]
        //(a[i][0], a[i][1], a[i][2]........)*(b[0][j], b[1][j], b[2][j]) 

        resultant[i][j] = 0; //need to reset it before matrix multiplication; after i/j are incremented so the answer does not keep on adding up
        for (int k = 0; k < limit; k++)
        {
            resultant[i][j] = (resultant[i][j])+(a[i][k]*b[k][j]); 
        }
                
    }  
}

printf("\nYour resultant matrix is:\n"); //printing the resultant matrix

for (int i = 0; i < 3; i++)
{
    for ( int j = 0; j < 3; j++) 
    {
        printf("%d ", resultant[i][j]); 

    } 

    printf("\n"); 
}

    return 0; 
}