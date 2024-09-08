#include<stdio.h>

/*Finding out total fuel consumption on a journey
Finding out total fuel cost on the journey
Single trip distance and fuel cost on the way and backward are given
Ask the user for input on fuel effeciency that is km/litre a car can travel */

int main (){
    float fuel_efficiency, total_distance, a, b;
    total_distance = 1207*2;
    
    //Prompt the user for input
    printf("Enter the car's fuel efficiency: ");
    scanf("%f", &fuel_efficiency);

    //Check if the fuel efficiency is within the valid range
    if (fuel_efficiency > 0) {
        
        //In the case it is within valid range then displays total fuel consumed   
        printf ("Total fuel consumed for the total distance is: %f \n", total_distance/fuel_efficiency);

        //Assigning values to calculate total fuel costs
        b = 1207/fuel_efficiency*118;
        a = 1207/fuel_efficiency*123;
        
        //Displays total fuel cost
        printf("Total fuel cost for the total distance is: %f \n", a + b);
    
    } else {
    //In the case the condition fails to be true the following msg displays
    printf("Error: The fuel efficiency must be greater than zero.");
    //End the condition
    return 0; 
    }
//End
return 0;   
}