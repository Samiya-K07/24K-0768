//Printing all the prime numbers in a given range

#include<stdio.h>

int main () {

int start, end, count; //declaration

printf("Enter the starting number: "); //prompt the user for starting number of the range
scanf("%d", &start);

printf("Enter the ending number: "); //prompt the user for ending number of the range
scanf("%d", &end);

if (start <= 0)
{
    printf("Invalid! Enter a number greater than and equal to 1!\n"); //since -ve numbers are neither prime nor composite 
    return 0; 
}

printf("\nPrime Numbers:\n"); 

for (int num = start; num <= end; num++) //checking all numbers in the range one at a time
{   
    if ((num == 0) || (num == 1))
    {
        continue; //since 0 and 1 are neither prime nor composite and usually ranges start from these numbers; we skip them here by moving onto the next iteration instead of adding these numbers in the condition for -ve numbers above
    }
    
    count = 0; //reset the value for count otherwise it will fail to perform its function as it will keep on adding up

    for (int i = 2; i < num; i++) //for each number check if it is prime or composite
    {
        if (num % i == 0) //if the num is divisible by even one other number it fails to be prime. if the remainder is not zero the loop will not enter the if statement instead just increment the value of i
        {
            count++;   
            break; //proceeds to the next number since the current number is not prime by exiting the loop  
        }  
    }

    if (count == 0) //this ensure prime numbers including 2 (since 2 (i) is not < 2 hence count remains 0) are printed
    {
        printf("%d ", num); 
    }    
}

    return 0; 
}