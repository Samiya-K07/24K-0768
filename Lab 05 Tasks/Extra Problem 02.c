#include<stdio.h>

int main () {

int attendance;
float assignment, exam, total;

printf("Enter your attendance weightage: ");
scanf("%d", &attendance);

printf("Enter your assignement weightage: ");
scanf("%f", &assignment);

printf("Enter your exam weightage: ");
scanf("%f", &exam);

total = assignment + exam;

if (attendance >= 50)
{
    if (total >= 80)
    {
        printf("Your final grade for the subject is A");
    }
    
    else if (total >= 70)
    {
        printf("Your final grade for the subject is B");
    }
    
    else if (total >= 50)
    {
        printf("Your final grade for the subject is C");
    }

    else
    {
        printf("Your final grade for the subject is F!!");
    }
}

else
{
   printf("Since you do not have the minimum attendance, your final grade for the subject is F!!");
}

    return 0;
}