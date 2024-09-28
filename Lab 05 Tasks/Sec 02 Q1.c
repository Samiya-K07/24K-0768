#include<stdio.h>

int main() {

int num;

printf("Enter a number: ");
scanf("%d", &num);

if (num % 3==0 && num % 5==0)
    {printf("%d is divisible by both 3 and 5 \n", num);}

    else if (num%3==0 && num%5!=0)
        {printf("%d is divisble by only 3 \n",  num);}

        else if (num%3!=0 && num%5==0)
        {printf("%d is divisible by only 5 \n", num);}

            else 
            {printf("%d is not divisble by neither 3 nor 5 \n", num);}

    return 0;
}