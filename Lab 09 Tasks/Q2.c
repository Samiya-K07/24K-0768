/*Create a C program that swaps the values of two integers using a user-defined function,
swapIntegers. The user inputs two integer values, and the program uses the function to swap
them. It should perform the swap and display the updated values*/

#include<stdio.h>

void swapIntegers (int a, int b);

int main () {

int a, b;

printf("Enter a: ");
scanf("%d", &a);

printf("Enter b: ");
scanf("%d", &b);

swapIntegers(a, b);

    return 0;
}

void swapIntegers (int a, int b)
{
    a = a ^ b; //result of a XOR b stored in a
    b = a ^ b; //a (result) XOR b stored in b and now b == a hence values swapped
    a = a ^ b; //since b == a then b XOR a (result) stored in a and now a == b hence values swapped

    printf("\n");
    printf ("a = %d\n", a);
    printf ("b = %d\n", b);
}