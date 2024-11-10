/*Write a function that checks if a given number is even or odd*/

#include<stdio.h>

void even_or_odd(int num);

int main () {

int num; 

printf("Enter a number: "); 
scanf("%d", &num);

even_or_odd(num);

    return 0; 
}

void even_or_odd(int num)
{
    //if and else statements to account for whether the number is prime or not
    if(num % 2 == 0)
    {
        printf("%d is even!!\n", num);
    }

    else
    {
        printf("%d is odd!!\n", num);
    }
}