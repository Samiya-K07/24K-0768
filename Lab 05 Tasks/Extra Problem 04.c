#include<stdio.h>

int main () {

int age, income, credit_score;

printf("Enter your age: ");
scanf("%d", &age);

printf("Enter your income: ");
scanf("%d", &income);

printf("Enter your credit score: ");
scanf("%d", &credit_score);

if (age >= 18 && income >= 100000 && credit_score >= 620)
    {
    printf("You are eligible for a loan!!\n");
    }

    else if (age >= 18 && income >= 100000)
    {
        printf("You do not meet the credit score criteria for a loan!!\n");
    }

        else if (age >= 18 && credit_score >= 620)
        {
            printf("You do not meet the income criteria for a loan!!\n");
        }

            else if (income >= 100000 && credit_score >= 620)
            {
                printf("You do not meet the age criteria for a loan!!\n");
            }

else
{
    printf("You do not meet the age, income nor the credit score criteria for a loan!!\n");
}

return 0;

}