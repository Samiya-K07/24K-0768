#include <stdio.h>

int Move1(int match_sticks);

int main () {
   
    int match_sticks;

    printf("Enter the number of matchsticks: ");
    scanf("%d", &match_sticks);

    
    int result = Move1(match_sticks);

    if (result == -1) 
    {
        printf("It iss impossible for A to be able to win!!\n");
    } 
    
    else 
    {
        printf("A should pick %d matchstick(s) on the first turn to be able to win!!\n", result);
    }

    return 0;
}

int Move1(int match_sticks) 
{
    if (match_sticks % 5 == 0) 
    {
        return -1; 
    }

   
    return match_sticks % 5;
}
