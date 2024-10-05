/* Create a C program to calculate the following series using loop statements
65536, 32768, 10922, 2730, 546, 91, 13, 1, 0 */

#include<stdio.h>

int main () {

int n, i, j, quotient; //Declaring the variables

j = 65536; //Initializing because we need to print it separately first

printf ("%d, ", j); //Displays j 

for (n = 1, i = 2; n < 7; n++, i++) //Initialization variable n and i, Stopping condition and Incrementing the variable n so the loop isnt infinite and incrementing the i variable so that we get the correct series
{
    quotient = j / i; //Calculating the quotient
    j = quotient; //Initializing j variable in each loop
    
    printf ("%d, ", quotient); //Displaying the quotient

}

printf ("1, 0"); //Displaying the last two numbers of the series since they do not follow the pattern the other numbers dos

    return 0;
}