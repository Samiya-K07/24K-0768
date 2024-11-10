/*Write a program that takes a destination string and a source string as input. Then, take
an integer n as input and append only the first n characters of the source string to the
destination. Print the new concatenated string*/

#include<stdio.h>
#include<string.h>

int main () {

char destination_string[200];//the string to which we are going to append the first n characters from the source string needs to have a greater size
char source_string[100];  
char temporary_string[100]; 

printf("Enter the destination string: ");
scanf("%s", destination_string); 

printf("Enter the source string: "); 
scanf("%s", source_string);

int n; 
printf("Enter an integer: "); 
scanf("%d", &n); 

for (int i = 0; i < n; i++)
{
    temporary_string[i] = source_string[i]; //making a temporary string and then using that to concatenate the first n characters from the source string to the destination string
}

temporary_string[n] = '\0'; 

strcat(destination_string, temporary_string); 

printf("The new concatenated string is: %s\n", destination_string); 

    return 0; 
}