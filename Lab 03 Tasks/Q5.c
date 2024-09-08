#include<stdio.h>

int main (){
float Principal, Rate_of_Interest, Time_Period, Simple_Interest;

//Prompt the user for inputs as well displaying a msg for the range for said inputs
printf("Enter the Principal Amount (between 100Rs and 1000000Rs): ");
scanf("%f", &Principal);

printf("Enter the Rate of Interest (between 5 percent and 10 percent): ");
scanf("%f", &Rate_of_Interest);

printf("Enter the Time Period (between 1 year and 10 years): ");
scanf("%f", &Time_Period);

//Calculate Simple Interest
Simple_Interest = Principal*Time_Period*Rate_of_Interest/100;
//Displays Simple Interest
printf("The Simple Interest is: %f \n", Simple_Interest);

return 0;
}