#include <stdio.h>

#define METER_TO_KM 0.001  


void conversion(float m) 
{
    static int count = 0;  
    count++; 

    float km = m * METER_TO_KM;
    
    printf("Conversion: %.2f meters = %.2f kilometers\n", m, km);
    printf("This function has been called %d times!!\n", count);
}

int main() {
    
    float m;
    char choice;
    printf("Conversion factor: 1 meter = %.3f kilometers\n\n", METER_TO_KM);

    do {
        
        printf("Enter the distance in meters: ");
        scanf("%f", &m);

        conversion(m);  

        printf("Do you want to convert another distance? (Y/N): ");
        scanf(" %c", &choice);  

    } while (choice == 'Y' || choice == 'y');

    printf("Exiting program......\n");
    return 0;
}
