#include <stdio.h>

void RecursivePrinting(int array[], int n)
{
    if (n == 0)
    {
        return;
    }
    
    printf("%d,", array[0]);
    RecursivePrinting(array + 1, n-1);
}

int main() {
    
    int n;
    
    printf("Enter the total number of elements in an array: ");
    scanf("%d", &n);
    printf("\n");
    
    int array[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter element[%d]: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("\nYour array: {");
    
    RecursivePrinting(array, n);
    printf("}");
    
    return 0;
}