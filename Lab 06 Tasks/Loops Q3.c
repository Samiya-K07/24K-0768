/* Using the above program integrate the number if it is a prime or composite number */

#include<stdio.h>

int main () {
 
int n, i; //Declaring the variables

i = 2; //Initializing to 2 so that the num is not divided by 1

printf ("Enter a number: "); //Prompt the user for input
scanf ("%d", &n);

if (n < 4) //Condition since if this condition is not added 2 will be shown as a composite number as 2 % i == 0
{
    printf ("%d is a prime number\n", n);
}

else
{
    while (i < n) //Stopping Condition
    {
        if ( n % i != 0) //Condition to check whether prime number or composite
        
        {
            i = i +1;
        }
        
        else
        {
            printf ("%d is a composite number\n", n); //Displays on the computer incase condition is not true
            return 0;
        }
        
    }

   printf ("%d is a prime number\n", n); //Displays on the computer when loop ends

   return 0; 
}



    return 0;
}