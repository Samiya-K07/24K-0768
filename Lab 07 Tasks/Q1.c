/*Taking user input array and then printing sum of all elements*/

#include<stdio.h>

int main () {

int size, sum = 0; //Declaring and initializing variables

printf("Enter size of array: "); //Prompting user for input (size of array so that we can declare array using that value)
scanf("%d", &size);

int arr[size]; //Declaring the array

for (int i = 0; i < size; i++) //For loop to ask the user for input until the last value (which is going to fill size-1 index; the last index)
{
    printf("Enter a value: "); //Prompt the user for array input
    scanf("%d", &arr[i]);
}

for (int i = 0; i < size; i++)
{
    sum = sum + arr[i]; //Another for loop to calculate the sum of all elements in the array
}

printf("Sum: %d\n", sum); //Displaying the sum


    return 0;
}
