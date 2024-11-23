#include<stdio.h>
#include<string.h>


struct flight {
   int flight_num;
   char destination[100];
   char dept[100];
   int date;
   int seats;
};

void booking(struct flight Flight)
{
    if(Flight.seats==0){
        printf("Sorry no seats available!!\n");
    }
    
    else 
    {
        Flight.seats--;
        printf("Seat confirmed!!\n");
    }
}
void displaydestination(struct flight Flight)
{
printf("Flight number: %d\n", Flight.flight_num);
printf("Departure city: %s\n", Flight.dept);
printf("Destination City: %s\n", Flight.destination);
printf("Number of available seats: %d\n", Flight.seats);
}

int main() {
    
    int choice; 
    printf("Welcome!\n");
    printf("1.Display Flight Details.\n");
    printf("2.Book a Seat\n");
    printf("3.Exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    
    struct flight Flight={240768, "Islamabad", "Karachi", 240881, 50};
    
    switch (choice)
    {
        case 1:
        displaydestination(Flight);
        break;
        
        case 2: 
        booking(Flight);
        break;
        
        case 3:
        return 0;
        
        default:
        printf("Invalid Choice!!\n");
    }
    
    return 0;
}
