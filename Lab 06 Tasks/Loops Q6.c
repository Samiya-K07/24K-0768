/*Create a C program to calculate the following series using loop statements
1, 2, 2, 4, 8, 32, 256, 8192, 2097152 */

#include<stdio.h>

int main () {

int n, i, j, ans; //Declaring the variables

n = 1; //Initializing the variable

printf ("1, 2, "); //Displaying the first two numbers of the series

for (i = 1, j = 2 ; n < 8 ; n++) //Initialization, Stopping condition and Incrementing the variable n so the loop isnt infinite 
{
    ans = i * j; //Calculating product/ans
    i = j; //Initializing the i and j variables in each loop
    j = ans;
    printf ("%d, ", ans); //Displaying the ans calculated
}

    return 0;
}