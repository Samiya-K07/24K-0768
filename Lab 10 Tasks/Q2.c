#include <stdio.h>

void PercentageCalculator(int num)
{
    float percent;
    for (int i = 1; i <= 100; i++)
    {
        percent = num * (i/100.0);
        printf("%d Percent = %.2f\n", i, percent);
    }
}

int main() {
    
int num;
printf("Enter a value to find the percentage: ");
scanf("%d", &num);
PercentageCalculator(num);
    
    return 0;
}