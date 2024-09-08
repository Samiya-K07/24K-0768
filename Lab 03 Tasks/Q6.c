#include<stdio.h>

int main () {
float slope, a, b;

    //Display the two points
    printf("The first point is: (5.0,4.0) \n");
    printf("The second point is: (3.0,2.0) \n");

    //Use the two points to calculate Slope
    a = 2.0-4.0;
    b = 3.0-5.0;
    slope = a/b;
    //Displays the Slope
    printf("The slope for the following points is: %.3f \n", slope);
 
    return 0;
}