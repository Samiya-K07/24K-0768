#include<stdio.h>

int main () {

int n, count;

printf("Enter a number: ");
scanf("%d", &n);

count = 0;

while (n > 0)
{
    n = n&(n-1);
    count = count + 1;
}

printf ("The number of 1's in your number are: %d\n", count);

return 0;
}