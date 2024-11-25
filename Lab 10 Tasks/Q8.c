#include <stdio.h>

int LinearSearch(int arr[], int size, int target, int index) 
{
    if (index >= size) 
    {
        return -1;
    }

    if (arr[index] == target) 
    {
        return index;
    }

    return LinearSearch(arr, size, target, index + 1);
}

int main() {
    
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, result;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = linearSearch(arr, size, target, 0);

    if (result != -1) 
    {
        printf("Element %d found at index %d!!\n", target, result);
    } 
    
    else 
    {
        printf("Element %d not found in the array!!\n", target);
    }

    return 0;
}
