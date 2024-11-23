#include <stdio.h>

void BubbleSort(int array[], int n)
{
    if (n == 1)
    {
        return;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i+1]){
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
    
    BubbleSort(array, n-1);
}

int main() {
    
    int n;
    
    printf("Enter The Total Number of Elements In An Array: ");
    scanf("%d", &n);
    printf("\n");
    
    int array[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element[%d]: ", i+1);
        scanf("%d", &array[i]);
    }
    
    printf("\nBefore Buble Sort Array is: {");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", array[i]);
    }
    printf("}");
    
    printf("\nAfter Bubble Sort Array is: {");
    BubbleSort(array, n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d,", array[i]);
    }
    
    printf("}");
   
    return 0;
}