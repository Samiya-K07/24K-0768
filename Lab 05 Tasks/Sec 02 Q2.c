#include<stdio.h>

int main() {

int age;
char citizenship_status;

printf("Enter your age: ");
scanf("%d", &age);

printf("Are you a citizen? (y for yes and n for no): "); 
scanf(" %c", &citizenship_status);

if (age>=18 && citizenship_status =='y')
    {printf("You are eligible to vote. \n");}

    else if (age>=18 && citizenship_status == 'n')
        {printf("You are not eligible to vote. Citizenship status missing! \n");}

        else if (age<=18 && citizenship_status == 'y')
        {printf("You are not eligible to vote. Age is below the requirement! \n");}
        
            else
            {printf("You are not eligible to vote. You do not meet either of the requirements! \n");}
        
    return 0;
}