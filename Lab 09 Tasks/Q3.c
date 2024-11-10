/*Implement a function that checks if a given integer is a prime number. Use this function in the
main program to check if numbers entered by the user are prime*/

#include<stdio.h>

void prime_or_not (int num, int count); 

int main () {

int num, count = 0; 

printf("Enter a number: "); 
scanf("%d", &num); 

//conditions to account for certain inputs
if (num < 0)
{
    printf("Invalid!! Enter a number greater than 0!!\n"); 
    return 0;
}

if ((num == 0) || (num == 1))
{
    printf("%d is neither prime nor composite!!\n", num);
    return 0;
}
    

prime_or_not (num, count); 

    return 0; 
}

void prime_or_not (int num, int count)
{   

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) //since if number divisible by even one other number, it fails to be prime
        {
            count++; 
            break; 
        } 
    }

    //using the count variable to check if the number is prime or composite
    if (count == 0)
    {
        printf("%d is prime!!\n", num); 
    }

    else
    {
        printf("%d is composite!!\n", num);
    }
    
}