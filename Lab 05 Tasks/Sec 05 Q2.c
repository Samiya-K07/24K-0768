#include<stdio.h>

int main () {

int num, sum, remainder, b;

b = num;
sum = 0;
printf("Enter a positive number: ");
scanf("%d", &num);

while (b != 0)
{
    remainder = num%10;
    b = num/10;
    sum = remainder+sum; 
    num = b;
}
printf("Sum is: %d \n", sum);

    return 0;
}