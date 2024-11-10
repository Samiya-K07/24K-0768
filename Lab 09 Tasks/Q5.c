/*Create a function that reverses a given string and returns the reversed string. Use this function
in the main program to display the reversed string entered by the user*/

#include<stdio.h>
#include<string.h>

void reversed_string(char* string); 

int main () {

char string = "Samiya Khan"; 

reversed_string(string); //calling function
printf("Reversed string: %s\n", string); //displaying the reversed string in the main function

    return 0; 
}

void reversed_string(char* string)
{
    int length = strlen(string); 
    char reverse[100]; 

    int j; 
    for (int i = length - 1, j = 0; string[i] != '\0'; i--, j++)
    {
        reverse[j] = string[i]; //storing the reverse in a temporary array called reverse
    }

    reverse[j] = '\0'; 

    strcpy(string, reverse); //copying the reversed string in the original string
    return;
}
