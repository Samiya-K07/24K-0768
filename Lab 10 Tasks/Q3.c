#include<stdio.h>
#define MAXTEMP 40

void temp_check(float temp)
{
    static int count=0;
    
    if (temp > MAXTEMP)
    {
        count++;
        printf("Temperature exceeds the maximum limit of %d°C!!\n",MAXTEMP);
    }
    
    else 
    {
        printf("Temprature is within the allowable limit!!\n");
    }
    
    printf("The temperature exceed the limit %d times!!\n", count);
}

int main() {
    
    float temp;
    char choice;
    
    printf("Maximum allowable temperature is: %d°C\n", MAXTEMP);
    
    do 
    {
    printf("Enter a reading for temperature: \n");
    scanf("%f", &temp);
    
    temp_check(temp);
    
    printf("Do you want to enter another reading?\n");
    scanf(" %c", &choice);
    }
    while (choice=='Y' || choice=='y');

    return 0;
}
