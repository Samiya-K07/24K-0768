#include<stdio.h>
#include<stdlib.h>

int sumofarray(int n, int arr[])
{
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    
    return sum;
}

int main() {
    
    int n, result;
    printf("Enter the size of your array:\n");
    scanf("%d", &n);
    
    int *arr=(int *)calloc(n, sizeof(int));
    
    if (arr ==  NULL)
    {
        printf("Memory Allocation failed!! Exiting....\n");
        return 1;
    }
    
    printf("Enter the elements of your array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
   
    printf("Your array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    result=sumofarray(n,arr);
    
    printf("The sum of all the elements in this array is: %d \n", result);
    free(arr);
    
    return 0;
}
