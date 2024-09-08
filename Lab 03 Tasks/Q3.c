#include<stdio.h>

/* Take Tax Rate and Salary before paying tax from the user. 
Calculate Tax that needs to be paid and then the Salary after paying tax. */

int main () {
    float tax_rate, salary_before_tax, salary_after_tax, tax_paid;

    //Prompt the user for input
    printf("Enter Tax Rate: ");
    scanf("%f", &tax_rate);

    printf("Enter Salary before paying tax: ");
    scanf("%f", &salary_before_tax);

    tax_paid = tax_rate/100*salary_before_tax;
    salary_after_tax = salary_before_tax-tax_paid;

    //Displays the Tax that needs to be paid
    printf("Tax that needs to be paid is: %f \n", tax_paid);
    
    //Displays the Salary after paying tax
    printf("Salary after paying tax is: %f \n", salary_after_tax);

    return 0;
}