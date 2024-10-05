/* Which loop system would be better for user input. Justify your answer by creating a program
that takes a value and adds it to a variable and prints it repeatedly until the user enters a zero
value */

/* Using a while loop is better to use than a for loop since because the loop's stopping condition is dependent on user input.
Since we want the result to be printed always until the user enters 0. We do not know in advance how many times we need to print */


#include <stdio.h>

int main () {

int n, a, sum; //Declaring the variables  

a = 4; //Initializing the variable to be added
n = 1; //Intiializing the variable for while loop condition

while (n != 0) //Stopping condition
{
    printf ("Enter a number: "); //Prompt the user for input
    scanf ("%d", &n); 

    sum = n + a; //Calculating sum

    if (sum !=  a) //Condition since if sum == a then that means n == 0 and we need to stop the program then 
    {   
        printf ("%d\n", sum); //Displays the sum if condition is true
    }

    else
    {
        printf ("Program has ended\n"); //Displays the msg if not true
    }
    
}
    
    return 0;
}


