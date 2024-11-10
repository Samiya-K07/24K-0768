/*Write a program that initializes a 2D character array with a list of words. Then, take a
word as input from the user and check if it exists in the array. Display "Found" if it’s there,
otherwise display "Not Found"*/

#include<stdio.h>
#include<string.h>

int main () {

char word[50];
int count = 0; 

char array[6][50] = {"apples", "oranges", "bananas", "lemons"}; 

printf("Enter the word you need to check: ");
scanf("%s", word); 

for (int i = 0; i < 6; i++)
{
    if (strcmp(array[i], word) == 0) //using condition in loop to compare
    {
        count++;
        break; 
    }
}

if (count == 0)
{
    printf("FOUND!!\n");
}

else 
{
    printf("NOT FOUND!!\n"); 
}

    return 0; 
}