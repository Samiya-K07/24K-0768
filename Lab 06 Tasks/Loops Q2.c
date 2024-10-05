/* Write a program to check whether a given number is a multiple digit number or not*/

#include<stdio.h>

int main (){

int num, quotient, i; //Declaring the variables

printf ("Enter a num: "); //Prompt the user for input
scanf ("%d", &num);

i = 0; //Initialize i

    while (quotient != 0) //Stopping condition
    {
        quotient = num/10; //Calculating the quotient since single digit numbers get the quotient 0 when divided by 10 once
        
        num = quotient; //Initializing the num variable in each loop 
        
		i = i+1; //Incrementing by one
    }

        if (i == 1) //Setting the condition to differentiate the digits in the number
        {
            printf ("%d is a single digit number\n", num);
        }

        else
        {
            printf ("%d is a multiple digit number\n", num); //Displays on the computer if condition is not true
        }

    return  0;
}