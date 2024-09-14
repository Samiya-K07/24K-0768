/*Name: Samiya Khan (24K-0768)
 *File: Q2.c
 *Date: 8 Sept 24
 Task 02: Create a calculator asking for operator (+ or – or * or /) and then performs calculation according to the user input using switch statement.
 */

#include<stdio.h>

int main () {
    
int num1, num2; //Variable to store the users' input (initialization)
char operator;

printf("Enter first number: "); //Prompt the user for a number
scanf("%d", &num1);

printf("Enter second number: "); //Prompt the user for another number
scanf("%d", &num2);

printf("Enter an operator from (+, -, *, /): "); //Prompt the user for an operator
scanf(" %c", &operator);

switch (operator) //Switch case to determine the operator and perform calculation
{
case '+':
    printf("The answer is: %d \n", num1+num2);
    break;

case '-':
    if (num1>num2)
    {printf("The answer is: %d \n", num1-num2);}
    else
    {printf("The answer is: %d \n", num2-num1);}
     break;

case '*':
    printf("The answer is: %d \n", num1*num2);
    break;

case '/':
    if (num1>num2)
    {printf("The answer is: %d \n", num1/num2);}
    else
    {printf("The answer is: %d \n", num2/num1);}
     break;

default: //In the case that all cases fail i.e when operator is not valid
    printf("Input Error!! Please enter a valid operator (+, -, *, /) \n");
break;
}

//End the code
return 0;
}
