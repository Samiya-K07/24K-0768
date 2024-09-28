#include<stdio.h>

int main () {

int a, b, c, diff_1, diff_2, diff_3;


printf("Enter first number: ");
scanf("%d", &a);

printf("Enter second number: ");
scanf("%d", &b);

printf("Enter third number: ");
scanf("%d", &c);

diff_1 = a - b;
diff_2 = a - c;
diff_3 = b - c; 

if (diff_1 > 0)
{
    if (diff_2 > 0)
    {
        printf("The greatest number is: %d\n", a);
    }
    
    else
    {
        printf("The greatest number is: %d\n", c);
    }
}

else if (diff_3 > 0)
{
    printf("The greatest number is: %d\n", b);
}

else 
{
    printf("The greatest number is: %d\n", c);
} 

return 0;
}