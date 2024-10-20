/*Finding if any number is repeated in an array and if it is then display that number as output*/

#include<stdio.h>

int main () {

int size; //Declaring variable

printf("Enter size of array: "); //Prompting user for input (size of array so that we can declare array using that value)
scanf("%d", &size);

int arr[size]; //Declaring the array

for (int i = 0; i < size; i++) //For loop to ask the user for input until the last value (which is going to fill size-1 index; the last index)
{
    
    printf("Enter a value: "); //Prompt the user for array input
    scanf("%d", &arr[i]);

    if (arr[i] < 0)
    {
        printf("Invalid!! Enter a value greater than or equal to 0\n"); //Since this logic has its limitations and that is: no negative number can be present in the array
        return 0; 
    }
    
}
  
int count[9999] = {0}; //Declaring another array to find duplicate values in the array and setting all the values in the count array to 0 

for(int i = 0; i < size; i++) //For loop to increment the value of the count index (corresponding to the value of arr[i]) from 0 so that we can determine that what value of arr[i] is repeating since the incremented value for that count index will be greater than 1 
    {
        count[arr[i]]++;
    }
    
for(int i = 0; i < 9999; i++) //For loop to determine if the incremented value is greater than 1
    {
        if(count[i] > 1)
        {
            printf("Number %d occurs in an array more than once\n", i); //Make sure it is i not count[i] since the count index is what coresponds to the value of arr[i]
        }
    }

    return 0; 
}
