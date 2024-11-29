#include <stdio.h>

int main () {

int min, second_min, temp, values, sum = 0; 

printf("Enter the number of values you want in your array: "); 
scanf("%d", &values);

int arr[values]; 

for (int i = 0; i < values; i++)
{   
    printf("Enter a value: ");
    scanf("%d", &arr[i]); 

    if (arr[i] > 9999)
    {
        printf("Invalid value!! Enter a value <9999\n");
        return 0; 
    }
}

for (int i = 0; i < values; i++)
{   
    if (arr[i] < 0)
    {
        temp = arr[i] * -1;
        sum = sum + temp;  
    }
    
    else 
    {
        sum = sum + arr[i]; 
    }   
}

min = sum; 

for (int i = 0; i < values; i++)
{
    if (min > arr[i])
    {   
        second_min = min;
        min = arr[i]; 
       //we need to handle the case where the number (which in this case is 4) is lower than the second lowest number but higher than the lowest number
    }

    else 
    {
        if (arr[i] > min && arr[i] < second_min)
        {
            second_min = arr[i]; 
        }
    }   
}

printf("The second lowest number is: %d\n", second_min); 

    return 0; 
}
