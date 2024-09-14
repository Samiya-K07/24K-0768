/*Name: Samiya Khan (24K-0768)
 *File: Q3.c
 *Date: 8 Sept 24
 Task 03: Ask the user to input a character from the user and check whether the given character is a small alphabet, capital alphabet, digit, or special character.
 */

#include<stdio.h>

int main () {

char userinput;

printf("Enter a character of your choice: ");
scanf(" %c", &userinput);

if (userinput>='0' && userinput<='9')
{printf("%c is a digit \n", userinput);}

    else if (userinput>='a' && userinput<='z')
    {printf("%c is a small alphabet \n", userinput);}

        else if (userinput>='A' && userinput<='Z')
        {printf("%c is a capital alphabet \n", userinput);}

            else
            {printf("%c is a special character \n", userinput);
            return 0;}

return 0;
}