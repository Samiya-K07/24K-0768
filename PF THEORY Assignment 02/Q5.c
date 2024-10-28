#include <stdio.h>

int main () {

int count; 

printf("Enter the number of values in your array: "); 
scanf("%d", &count); 

int values[count]; 

for (int i = 0; i < count; i++)
{
    printf("Enter a value: "); 
    scanf("%d", &values[i]);

    if (values[i] < 0)
    {
        printf("Invalid number!! Enter a number greater than 0!!\n"); 
        return 0; 
    } 
}

printf("\nHorizontal Histogram:\n"); 

for (int i = 0; i < count; i++)
{
    for (int j = 0; j < values[i]; j++)
    {
        printf("*"); 
    }
    
printf("\n");
}

int max = values[0]; //we can also equate max to the -sum of the entire array and then compare

for (int i = 0; i < count; i++)
{
    if (max < values[i])
    {
        max = values[i]; 
    }    
}

printf("\nVertical Histogram:\n");
for (int i = max; i > 0; i--)
{
    for (int j = 0; j < count; j++)
    {
        if (values[j] < i)
        {
            printf("  ");
        }

        else 
        {
            printf("* "); 
        } 
    } 

    printf("\n");
}

    return 0;
}