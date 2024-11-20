/*Create a program that accepts a 2D array of strings (e.g., 5 words with a max length of 20
characters each). Determines if each word (row) is a palindrome. Outputs “Palindrome” or “Not
Palindrome” for each word. A palindrome is a word that reads the same forward and backward.
For example: "madam", "racecar", "level", "radar"*/

#include<stdio.h>
#include<string.h>

void palindrome(char array[][20], int n); 

int main () {

int n; 
printf("Enter the number of words: "); //prompt the user for input (the number of rows)
scanf("%d", &n); 
getchar(); //removing the leftover character

char array[n][20]; //declaring and initializing the array

for (int i = 0; i < n; i++)
{
    printf("Word %d: ", (i+1)); 
    fgets(array[i], 20, stdin);
    
    array[i][strcspn(array[i], "\n")] = '\0';  //removing the next line character because of fgets
}

printf("\n"); 

palindrome(array, n); //calling the function

    return 0; 
}

void palindrome(char array[][20], int n) 
{
    for (int i = 0; i < n; i++)
    {
        int length = strlen(array[i]);
        int count = 0; 

        for (int j = 0, k = length - 1; j < k; j++, k--)
        {
            if (array[i][j] != array[i][k]) //if the condition fails to be true even one time then it is not palindrome
            {
                count++; 
                break; 
            }   
        }
        
        if (count == 0) //since we incremented count in the case condition was not true hence if count is 0 then the word is a palindrome
        {
            printf("Word %d: %s = PALINDROME!!\n", (i+1), array[i]); 
        }
        
        else
        {
            printf("Word %d: %s = NOT PALINDROME!!\n", (i+1), array[i]); 
        }
    }   
}
