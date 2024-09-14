/*Name: Samiya Khan (24K-0768)
 *File: Q1.c
 *Date: 8 Sept 24
 Task 01: Write a C program to check whether a number is multiple of 3 or not
 */

#include<stdio.h>

int main () { 
    
    //Variable to store the users' input (initialization)
    int n; 

    //Prompt the user for a number
    printf("Enter a number: ");
    scanf("%d", &n);

    //Two scenarios- n is a multiple of 3 and n is not a multiple of 3
    if(n%3 == 0) //Condition
    {printf("%d is a multiple of 3 \n", n);} //Display this in the case the condition is true
    
    else //If the condition fails i.e. n%3 =! 0
    {printf("%d is not a multiple of 3 \n", n); //Display this otherwise
    return 0;}

    //End the code
    return 0;
}