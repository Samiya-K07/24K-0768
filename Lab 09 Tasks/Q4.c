/*Write a C program with a user-defined function calculate to perform basic arithmetic operations
such as addition, subtraction, multiplication, and division. The program should take two
numbers and an operation choice as input, and then use the function to perform the operation*/

#include<stdio.h>

void calculation (int num1, int num2, char operator); 

int main () {

int num1, num2;
char operator; 

printf("Enter first number: ");
scanf("%d", &num1);

printf("Enter second number: ");
scanf("%d", &num2);

printf("Enter an operator (+, -, *, /): ");
scanf(" %c", &operator);

calculation(num1, num2, operator); 
    return 0; 
}


void calculation (int num1, int num2, char operator)
{
    //use of switch cases to give different outputs for different inputs
    switch (operator)
    {
    
    case '+':
        
        printf("%d + %d = %d\n", num1, num2, (num1+num2));
        break;

    case '-':
        
        printf("%d - %d = %d\n", num1, num2, (num1-num2));
        break;

    case '*':
        
        printf("%d x %d = %d\n", num1, num2, (num1*num2));
        break;
    
    case '/':
        
        printf("%d / %d = %d\n", num1, num2, (num1/num2));
        break;   
        
    default:

        printf("Invalid operator!! Please select one of the valid operators!!\n");
        break;
    
    }
}