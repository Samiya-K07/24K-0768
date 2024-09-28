#include<stdio.h>

int main () {

int a, b, result;

printf("Enter a: ");
scanf("%d", &a);

printf("Enter b: ");
scanf("%d", &b);

a = a ^ b; //result of a XOR b stored in a
b = a ^ b; //a (result) XOR b stored in b and now b == a hence values swapped
a = a ^ b; //since b == a then b XOR a (result) stored in a and now a == b hence values swapped

printf ("a = %d\n", a);
printf ("b = %d\n", b);


return 0;
}