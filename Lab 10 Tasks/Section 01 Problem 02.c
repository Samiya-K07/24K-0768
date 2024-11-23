#include <stdio.h>

int DigitsSum(int num)
{
    if (num == 0)
    {
        return 0;
    }
    
    return (num%10) + DigitsSum(num/10);

}
int main() {
    
    int num, result;
    
    printf("Enter the number you want to find the sum of: ");
    scanf("%d", &num);
    
    result = DigitsSum(num);
    printf("Sum of digits: %d\n", result);
    
    return 0;
}