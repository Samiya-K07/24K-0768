/*Name: Samiya Khan (24K-0768)
 *File: Q6.c
 *Date: 14 Sept 24
 Task 06: Given a positive integer denoting n, print lowercase English words corresponding to the numbers e.g. (one for 1, two for 2)
 However, if n>9 print greater then 9
 */

#include<stdio.h>

int main () {

int n; //Initialization

printf("Enter a positive number: "); //Prompt the user for input
scanf("%d", &n);

switch (n) //Switch case to determine the number and print it's word equivalent
{
case 1:
    printf("%d is one \n", n);
    break;

case 2:
    printf("%d is two \n", n);
    break;

case 3:
    printf("%d is three \n", n);
    break;

case 4:
    printf("%d is four \n", n);
    break;

case 5:
    printf("%d is five \n", n);
    break;

case 6:
    printf("%d is six \n", n);
    break;

case 7:
    printf("%d is seven \n", n);
    break;

case 8:
    printf("%d is eight \n", n);
    break;

case 9:
    printf("%d is nine \n", n);
    break;

default:
    printf("%d is greater than 9 \n", n);
    break;
}

return 0;
}