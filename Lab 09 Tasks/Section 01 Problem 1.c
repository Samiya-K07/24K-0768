/*Write a C function that takes two numbers as input and returns their product*/

#include<stdio.h>

int product (int a, int b); 

int main () {

    int a;
    int b; 

    printf("Enter first number: "); 
    scanf("%d", &a); 


    printf("Enter second number: "); 
    scanf("%d", &b); 

    //storing the value returned from the function to the main in the result variable
    int result = product(a, b); 

    printf("%d x %d = %d\n", a, b, result);
    return 0; 
}

int product (int a, int b)
{
    return (a*b); 
}