#include<stdio.h>
#include<string.h>

void reverse(char arr[], int start, int end)
{
    int n = strlen(arr);
    
    if (start >= end)
    {
        return;
    }
    
    else 
    {
        char rev=arr[start];
        arr[start]=arr[end];
        arr[end]=rev;
    }
    
    reverse(arr, start+1, end-1);
}

int main() {
    
    char arr[100];
    int start, end;
    
    printf("Enter your words: ");
    scanf("%s", arr);
    
    int n = strlen(arr);
    
    reverse(arr, 0, n-1);
    printf("Your reversed word is: %s \n", arr);
    
    return 0;
}

