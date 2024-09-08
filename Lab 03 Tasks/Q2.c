#include<stdio.h>

/* Setting values to two variables each and then swapping the values for the respective variables*/

int main () {
    int a, b;
    
    //Prompt the user for input
    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    //Displays the now switched values of the two variables
    printf("a is: %d \n", a*b/a);

    printf("b is: %d \n", b*a/b);
    
    return 0;
}