/*Create a function that returns the maximum and minimum element in an integer array. Use this
function in the main program to find the maximum and minimum from an array entered by the
user*/

#include<stdio.h>

//function declaration
int max (int arr[], int size); 
int min (int arr[], int size); 

int main () {

int arr[10]; //declaring the array

printf("Enter elements of your array:\n"); //prompt the user for array input
for (int i = 0; i < 10; i++)
{
    scanf("%d", &arr[i]);
    
}

printf("You array is: "); //displaying the entire array 
for (int i = 0; i < 10; i++)
{
    printf("%d ", arr[i]); 
}

//function call
int maximum = max(arr, 10); //declaring and initializing two different variables with the value that the function is going to return to main
int minimum = min(arr, 10); 

printf("\nMax element: %d\n", maximum); //printing the max element of the array
printf("Min element: %d\n", minimum); //printing the min element 

    return 0; 
}

//function definition

int max(int arr[], int size) 
{
    int max = arr[0]; //declaring and initializing the variable with the first element of the array in order to compare it with the next one and so on...

    for (int i = 0; i < size; i++) //for loop to traverse through the array
    {
        if (max < arr[i]) //comparing the max (first element) with the first element of the array and does this for all the other elements too when i is incremented
        {
            max = arr[i]; //if condition is true then set the value of max to the greater of the two 
        }
    }

    return max; //returning the value of the max element in the array to main 

}

//same functionalities as the previous function, with the only difference being in the condition since we need to return the value of the min element in the array to main
int min(int arr[], int size)
{
    int min = arr[0]; 

    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i]; 
        }
    }
    
    return min; 
}