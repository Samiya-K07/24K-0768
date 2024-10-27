//Creating a 3D Array representing 2 pages of a 3x3 matrix. Initialize it and then find the sum of all the elements on each page

#include<stdio.h>

int main () {

int sum_page_1 = 0, sum_page_2 = 0; //declaration

int a[2][3][3] = {{{12,22,23},{14,15,16},{37,38,39}},{{10,20,30},{40,50,60},{70,80,18}}}; 

printf("\nYour matrix is:\n"); //displaying the 3D-Array first
for (int i = 0; i < 2; i++) //for loop for displaying each of the 2 2D-Array in the 3D-Array
{
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("%d ", a[i][j][k]); 
        }
        
        printf("\n");
    }
    
    printf("\n");
}

for (int i = 0; i < 3; i++) //for loop to find out the sum on each page (of each 2D-Array) SEPARATELY
{
    for (int j = 0; j < 3; j++)
    {
        
        sum_page_1 = sum_page_1 + a[0][i][j]; //calculating sum of the first 2D-Array (hence the index 0)
        sum_page_2 = sum_page_2 + a[1][i][j]; //calculating sum of the second 2D-Array (hence the index 1)
    
    }
}

printf("SUM on the first page: %d\n", sum_page_1); //displaying the sum on first page
printf("SUM on the second page: %d\n", sum_page_2); //displaying the sum on second page

    return 0; 
}