/* Write a program to print the following series: 1, 2, 3, 5, 8, 13 */

#include<stdio.h>

int main () {

int n, i, j, sum; //Declaring the variables

n = 1; //Initialiing the variable

printf ("1, 2, "); //Displaying the first two numbers of the series

for (i = 1, j = 2 ; n < 5 ; n++) //Initialization, Stopping condition and Incrementing the variable n so the loop isn't infinite 
{
    sum = i + j; //Calculating sum
    i = j; //Initializing the i and j variables in each loop
    j = sum;
    printf ("%d, ", sum); //Displaying the sum calculated
}

    return 0;
}