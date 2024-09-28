#include <stdio.h>

int main() {

int num1, num2;

printf("Enter first number: ");
scanf("%d", &num1);

printf("Enter second number: ");
scanf("%d", &num2);

num1 > num2 ? printf("%d is maximum of the two numbers \n", num1) : printf("%d is  maximum of the two numbers \n", num2);

    return 0;
}