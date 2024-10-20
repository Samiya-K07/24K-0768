/*Finding the largest and smallest value in an array*/

#include<stdio.h>

int main () {

int size, temp, sum = 0; //Declaring and initializing variables

printf("Enter size of array: "); //Prompting user for input (size of array so that we can declare array using that value)
scanf("%d", &size);

int arr[size]; //Declaring the array

for (int i = 0; i < size; i++) //For loop to ask the user for input until the last value (which is going to fill size-1 index; the last index)
{
    printf("Enter a value: "); //Prompt the user for array input
    scanf("%d", &arr[i]);
}

for (int i = 0; i < size; i++) //Another for loop to calculate the sum of all elements in the array
{
    if (arr[i] < 0) //Taking into account the case where an element of the array is a negative number
    {
        temp = arr[i] * -1; 
        sum = sum + temp; 
    }
    
    else 
    {
        sum = sum + arr[i]; 
    }
}

int max = sum * -1; //Variable max has the smallest value stored than all the elements of the array whereas min has the largest value stored than all the elements in the array
int min = sum; 

for (int i = 0; i < size; i++)
{
    if (max < arr[i]) //Comparing each element of the array with the next one (traversing through the array) for max value
    {
        max = arr[i]; 
    }   
}

for (int i = 0; i < size; i++) 
{
    if (min > arr[i]) //Comparing each element of the array with the next one (traversing through the array) for min value
    {
        min = arr[i]; 
    }  
}

printf("Minimum Number: %d\n", min); //Displayijng the maximum number
printf("Maximum Number: %d\n", max); //Displaying the minimum number

    return 0; 
}