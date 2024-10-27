//Printing odd numbers in a decreasing manner and in a certain pattern (starting from a user entered number) so that nested loops are implemented 

#include<stdio.h>

int main () {

int start, num, min_odd_number, line = 1; //declaration and initialization

//9
//9 7
//9 7 5
//9 7 5 3
//9 7 5 3 1

printf("Enter the starting odd number: "); //prompt the user for input
scanf("%d", &start); 

if (start % 2 == 0) //since we are printing odd numbers here starting from a number the user enters it cannot be an even number
{
    printf("Invalid!! Enter an odd number!!\n"); 
    return 0; 
}

min_odd_number = start; //initializing it before loop so that the loop works

while (min_odd_number > 0) //outer loop to make sure the minimum odd number printed is 1
{
    num = start; //start will always remain 9 (example)

    for (int i = 0; i < line; i++) //the number of elements printed in each line is equal to that line number
    {
        printf("%d ", num); //printing the number
        num = num - 2; //subtracting the value for the next number to be printed
    }

    printf("\n"); //enter next line
    line++; //incrementing lines so one more element is printed now
    min_odd_number = num; //updating the value of the variable after each loop so that negative numbers are not printed and only until the minimum odd number: 1 
}
   
    return 0;
}