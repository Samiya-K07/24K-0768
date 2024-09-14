/*Name: Samiya Khan (24K-0768)
 *File: Q4.c
 *Date: 14 Sept 24
 Task 04: Checking the cost of the item and applying discount accordinly. Lastly, displaying the actual amount, saved amount and the amount after discount.
 */

#include<stdio.h>

int main() {//Initialization

float actual_amount, saved_amount, amount_after_discount;

//Prompt the user for input
printf("Enter the actual amount of the items bought: ");
scanf("%f", &actual_amount);

//Five different scenarios
if (actual_amount>= 500 && actual_amount<=2000) //1st Condition
{saved_amount = actual_amount*0.05;
printf("Your saved amount after discount is: %f \n", saved_amount); //Display saved amount after required calculation
    
amount_after_discount = actual_amount-saved_amount;
printf("Your amount after discount is: %f \n", amount_after_discount);} //Display amount after discount after required calculation

    else if (actual_amount>2000 && actual_amount<=4000) //2nd Condition
    {saved_amount = actual_amount*0.1;
    printf("Your saved amount after discount is: %f \n", saved_amount); //Display saved amounnt after calcuation

    amount_after_discount = actual_amount-saved_amount;
    printf("Your amount after discount is: %f \n", amount_after_discount);} //Display amount after discount after required calculation

        else if (actual_amount>4000 && actual_amount<=6000) //3rd Condition
        {saved_amount = actual_amount*0.2;
        printf("Your saved amount after discount is: %f \n", saved_amount); //Display saved amount after required calculation

        amount_after_discount = actual_amount-saved_amount;
        printf("Your amount after discount is: %f \n", amount_after_discount);} //Display amount after discount after required calculation

            else if (actual_amount>6000) //4th Condition
            {saved_amount = actual_amount*0.35;
            printf("Your saved amount after discount is: %f \n", saved_amount); //Display saved amount after required calculation
            
            amount_after_discount = actual_amount-saved_amount;
            printf("Your amount after discount is: %f \n", amount_after_discount);} //Display amount after discount after required calculation

                else if (actual_amount<500) //5th Condition
                {printf("You are not eligible for discount!! \n"); //Display given msg
                return 0;}

//End the code
return 0;}
    


