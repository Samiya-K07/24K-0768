/*Name: Samiya Khan (24K-0768)
 *File: Q5.c
 *Date: 14 Sept 24
 Task 05: Write a program in C to calculate and print the electricity bill of a given customer
 */

#include<stdio.h>

int main () {

int customer_id, units_consumed; //Initialization
float amount_charges, surcharge_amount, net_amount; //Initialization

    printf("Enter customer ID: "); //Prompt the user for customer id
    scanf("%d", &customer_id); 
    
    printf("Enter the number of units consumed: "); //Prompt the user for units consumed
    scanf("%d", &units_consumed);

    if (units_consumed>=1 && units_consumed<=199) //First Condition
    {amount_charges = units_consumed*16.20;
    //Print the ID
    printf("Customer ID: %d\n", customer_id);
    
    //Print the amount charges if true
    printf("Amount Charges @Rs16.20 per unit: %.2f \n", amount_charges);} 


    else if (units_consumed>=200 && units_consumed<300) //Else second condition
    {amount_charges = units_consumed*20.10;
    //Print the ID
    printf("Customer ID: %d\n", customer_id);

    //Print the amount charges if true
    printf("Amount Charges @Rs20.10 per unit: %.2f \n", amount_charges);} 
        
        else if (units_consumed>=300 && units_consumed<500) //Else third condition
        {amount_charges = units_consumed*27.10;
        //Print the ID
        printf("Customer ID: %d\n", customer_id);
        
        //Print the amount charges if true
        printf("Amount Charges @Rs27.10 per unit: %.2f \n", amount_charges);} 
        
            else if (units_consumed>=500) //Else fourth condition
            {amount_charges = units_consumed*35.90;
             //Print the ID
            printf("Customer ID: %d\n", customer_id);
        
            //Print the amount charges if true
            printf("Amount Charges @Rs.35.90 per unit: %.2f \n", amount_charges); 
                
                if (amount_charges>18000) //Check another condition within this case
                {surcharge_amount = amount_charges*0.15;
                printf("Surcharge Amount: %.2f \n", surcharge_amount); //Print surcharge amount
                
                net_amount = amount_charges + surcharge_amount; //and net amount charged if true
                printf("Net Amount Paid by the customer: %.2f \n", net_amount);} //End the condition if false
                
                else {return 0;} //End the condition if false
            return 0;    
            }

return 0;    
}  
}
