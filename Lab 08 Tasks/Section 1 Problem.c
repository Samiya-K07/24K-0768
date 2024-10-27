//Printing a triangle star pattern

#include<stdio.h>

int main () {

int no_of_spaces = 3; //declare and initialize a variable to print the number of spaces

for (int i = 1; i <= 4; i++) //since the number of lines are the outer loops
{
    for (int k = 1; k <= no_of_spaces; k++) //separate loop for spaces 
    {
        printf(" ");
    }

    no_of_spaces = no_of_spaces - 1; //decrement the variable so that in the next line 2 spaces are printed and then 1 and then 0 
    
    for (int j = 1; j <= i; j++) //separate loop to print the number of stars from 1 to 2 to 3 and then 4
    {
        printf("* "); 
    }


    printf("\n");
}