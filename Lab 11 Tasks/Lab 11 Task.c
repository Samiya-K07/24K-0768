//Take the following structures and create functions that perform CRUD (create, read, update delete) operations in a file or multiple files depending on the need based on your understanding. Add a comment that exlpains your choice.
//suppose that you have to store data for 5 players with at least 3 bowlers. The rest will be N/A.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PLAYERS 5
#define ALL_PLAYERS_FILE "all_players.txt"

typedef struct
{
    char name[20];
    char team[20];
} player;

typedef struct
{
    char type[10]; //seemer, pacer, spinner// N/A
    char arm[5]; //left or right
    player ply;
} bowl;

typedef struct
{
    char type[10]; //top order, middle order, lower order
    char handed[8]; //lefty or righty
    bowl ply2;
} bat;

typedef struct 
{
    char player_name[20];
    char player_team[20];
    char batter_1[10];
    char batter_2[8];
    char bowler_1[10];
    char bowler_2[5];
} player_details;


//First, lets add a menu and deal with the options of creating (or writing) and reading in a file for a user 
//Secondly, deal with the options of updating and deleting a specific record in a file for a user 
//All of this will happen in a single line where each player detail for each player will be in a single line
//If this works I can try implementing a similar code but this time make three different files according to the player type (batter, bowler, or an all-rounder)
//Need to create array of struct bat with MAX_PLAYERS as array size since we need all details for exactly five players
//We use the create function to write the player details for all 5 players and the file is going to be overwritten everytime
//We use the read function and make sure that in the case that no file is created we create and write the player details for 5 players first 
//We use the update function and the entire record of a certain player is updated according to the user
//We use the delete function and the entire record of a certain player is deleted according to the user
//I use the delete function in such a way that after deleting the records are shifted one index up and the user is able to say how many more records of players can be written and can use the update function to add that information to the file instead of creating it from scratch

void StoreInfo(bat all_players[]);
void Create(bat all_players[]);
void Read(bat all_players[], player_details details[]);
void Update(bat all_players[], player_details details[]);
void Delete(bat all_players[], player_details details[]);

int main() {

bat all_players[MAX_PLAYERS]; 
player_details details[MAX_PLAYERS];

    int option;
    while (1)
    {
        printf("MENU\n");
        printf("1. Create records for five players\n");
        printf("2. Read all records\n");
        printf("3. Update a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit the program\n\n");
        printf("Enter your option: ");
        scanf("%d", &option); 
        getchar();

        switch (option)
        {
        case 1:
            
            //can later use if and else conditions to ask user how many players do they want to add the details for and if it exceeds MAX_PLAYERS then show a warning msg asking if they still want to proceed (since if they do then we call the same function but the details stored for players will be obviously less than the user demanded)
            StoreInfo(all_players); 
            break;
    
        case 2:

            Read(all_players, details);
            break;

        case 3:

            Update(all_players, details);
            printf("\n");
            break;

        case 4:

            Delete(all_players, details);
            break;

        default:
            printf("Invalid option!! Choose a valid option!!\n");
            break;
        }        
        
    }

    return 0;
}

void StoreInfo(bat all_players[])
{   
    int option;
    for (int i = 0; i < MAX_PLAYERS; i++)
    {   
        printf("\n\nEnter player %d name: ", (i+1));
        fgets(all_players[i].ply2.ply.name, sizeof(all_players[i].ply2.ply.name), stdin); 
        all_players[i].ply2.ply.name[strcspn(all_players[i].ply2.ply.name, "\n")] = '\0';    

        printf("Enter team name: ", (i+1));
        fgets(all_players[i].ply2.ply.team, sizeof(all_players[i].ply2.ply.team), stdin);
        all_players[i].ply2.ply.team[strcspn(all_players[i].ply2.ply.team, "\n")] = '\0';

        printf("\nIs the player \n(1) Batter\n(2) Bowler\n(3) Both\n");
        printf("\nEnter your option: "); 
        scanf("%d", &option); 

        getchar();
        
        while (option != 1 && option != 2 && option != 3)
        {
            printf("Invalid option!!\n");
            printf("\nIs the player \n(1) Batter\n(2) Bowler\n(3) Both\n");
            printf("\nEnter your option: "); 
            scanf("%d", &option); 
            getchar();
        }
        
        if (option == 1 || option == 3)
        {
            printf("Enter the batter type (top/middle/lower order): ");
            fgets(all_players[i].type, sizeof(all_players[i].type), stdin); 
            all_players[i].type[strcspn(all_players[i].type, "\n")] = '\0'; 

            printf("Enter the batter handedness (lefty/righty): ");
            fgets(all_players[i].handed, sizeof(all_players[i].handed), stdin); 
            all_players[i].handed[strcspn(all_players[i].handed, "\n")] = '\0'; 
        }
        
        else
        {
            strcpy(all_players[i].type, "N/A");
            strcpy(all_players[i].handed, "N/A"); 
        }

        if (option == 2 || option == 3)
        {
            printf("Enter the bowler type (seemer/pacer/spinner): ");
            fgets(all_players[i].ply2.type, sizeof(all_players[i].ply2.type), stdin); 
            all_players[i].ply2.type[strcspn(all_players[i].ply2.type, "\n")] = '\0'; 

            printf("Enter the bowler arm (left/right): ");
            fgets(all_players[i].ply2.arm, sizeof(all_players[i].ply2.arm), stdin); 
            all_players[i].ply2.arm[strcspn(all_players[i].ply2.arm, "\n")] = '\0'; 
        }
        
        else
        {
            strcpy(all_players[i].ply2.type, "N/A");
            strcpy(all_players[i].ply2.arm, "N/A"); 
        }

    }
    
    Create(all_players);
}

void Create(bat all_players[])
{
    FILE *fptr = fopen(ALL_PLAYERS_FILE, "w");

    if (fptr == NULL) 
    {
    printf("Error opening file for writing\n");
    return; 
    }

    for (int i = 0; i < MAX_PLAYERS; i++)
    {        
        fprintf(fptr, "%s\n%s\n%s\n%s\n%s\n%s\n", all_players[i].ply2.ply.name, all_players[i].ply2.ply.team, all_players[i].type, all_players[i].handed, all_players[i].ply2.type, all_players[i].ply2.arm); 
        //the order is such that player name, player team, batter type, batter handedness, bowler type, bowler arm
    }

    fclose(fptr); 
}

void Read(bat all_players[], player_details details[]) 
{   
    char option;
    FILE *fptr = fopen(ALL_PLAYERS_FILE, "r");

    if (fptr == NULL) //this will only work one time i.e. when the file does not exist in the system
    {
        printf("The file you are looking for does not exist!! Do you wish to create a file of 5 players first and then read? Y for yes and N for no: ");
        scanf(" %c", &option);
        getchar();

        if (option == 'Y')
        {
            StoreInfo(all_players); 
            Read(all_players, details); 
        }

        else if (option == 'N')
        {   
            printf("Taking you back to the MENU........\n");
            return; 
        }
    }

    else
    {   
        //there are total five players
        //for each players the order goes like:
        //Name
        //Team
        //Batter status1
        //Batter status2
        //Bowler status1
        //Bowler status2

        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            fgets(details[i].player_name, sizeof(details[i].player_name), fptr); //transfering data from files to structures
            details[i].player_name[strcspn(details[i].player_name, "\n")] = '\0'; 

            fgets(details[i].player_team, sizeof(details[i].player_team), fptr); //transfering data from files to structures
            details[i].player_team[strcspn(details[i].player_team, "\n")] = '\0'; 

            fgets(details[i].batter_1, sizeof(details[i].batter_1), fptr); //transfering data from files to structures
            details[i].batter_1[strcspn(details[i].batter_1, "\n")] = '\0'; 
            
            fgets(details[i].batter_2, sizeof(details[i].batter_2), fptr); //transfering data from files to structures
            details[i].batter_2[strcspn(details[i].batter_2, "\n")] = '\0';

            fgets(details[i].bowler_1, sizeof(details[i].bowler_1), fptr); //transfering data from files to structures
            details[i].bowler_1[strcspn(details[i].bowler_1, "\n")] = '\0'; 

            fgets(details[i].bowler_2, sizeof(details[i].bowler_2), fptr); //transfering data from files to structures
            details[i].bowler_2[strcspn(details[i].bowler_2, "\n")] = '\0'; 
        }   

        printf("\n");
        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            printf("\nPlayer %d\n__________________\n\nName: %s\nTeam: %s\nBatter type: %s\nBatter handedness: %s\nBowler type: %s\nBowler arm: %s\n", (i+1), details[i].player_name, details[i].player_team, details[i].batter_1, details[i].batter_2, details[i].bowler_1, details[i].bowler_2);
        }
        
        printf("\n");
    }
}

void Update(bat all_players[], player_details details[])
{   
    int player_index; 
    Read(all_players, details); 

    printf("\nEnter the player index (1-5) to be updated: ");
    scanf("%d", &player_index);
    getchar();

    while (player_index < 1 || player_index > MAX_PLAYERS)
    {
        printf("\nInvalid option!!");
        printf("\nEnter the player index (1-5) to be updated: ");
        scanf("%d", &player_index);
        getchar();
    }

    player_index--; 
    printf("\nUpdating details for Player %d\n\n", (player_index+1));
    
    //the only limitation here is that the entire record of a players is going to be asked again not a particular information of a record
    printf("Enter new name: "); 
    fgets(details[player_index].player_name, sizeof(details[player_index].player_name), stdin);
    details[player_index].player_name[strcspn(details[player_index].player_name, "\n")] = '\0';
    
    printf("Enter new team: ");
    fgets(details[player_index].player_team, sizeof(details[player_index].player_team), stdin);
    details[player_index].player_team[strcspn(details[player_index].player_team, "\n")] = '\0';

    printf("Enter new batter type: ");
    fgets(details[player_index].batter_1, sizeof(details[player_index].batter_1), stdin);
    details[player_index].batter_1[strcspn(details[player_index].batter_1, "\n")] = '\0';

    printf("Enter new batter handedness: ", details[player_index].batter_2);
    fgets(details[player_index].batter_2, sizeof(details[player_index].batter_2), stdin);
    details[player_index].batter_2[strcspn(details[player_index].batter_2, "\n")] = '\0';

    printf("Enter new bowler type: ", details[player_index].bowler_1);
    fgets(details[player_index].bowler_1, sizeof(details[player_index].bowler_1), stdin);
    details[player_index].bowler_1[strcspn(details[player_index].bowler_1, "\n")] = '\0';

    printf("Enter new bowler arm: ", details[player_index].bowler_2);
    fgets(details[player_index].bowler_2, sizeof(details[player_index].bowler_2), stdin);
    details[player_index].bowler_2[strcspn(details[player_index].bowler_2, "\n")] = '\0';

    FILE *fptr = fopen(ALL_PLAYERS_FILE, "w");

    if (fptr == NULL) 
    {
    printf("Error opening file for writing\n");
    return; 
    }

    for (int i = 0; i < MAX_PLAYERS; i++)
    {        
        fprintf(fptr, "%s\n%s\n%s\n%s\n%s\n%s\n", details[i].player_name, details[i].player_team, details[i].batter_1, details[i].batter_2, details[i].bowler_1, details[i].bowler_2); 
        //the order is such that player name, player team, batter type, batter handedness, bowler type, bowler arm
    }

    fclose(fptr); 

}

void Delete(bat all_players[], player_details details[])
{
    int player_index; 
    Read(all_players, details); 

    printf("\nEnter the player index (1-5) to be delete: ");
    scanf("%d", &player_index);
    getchar();

    while (player_index < 1 || player_index > MAX_PLAYERS)
    {
        printf("\nInvalid option!!");
        printf("\nEnter the player index (1-5) to be deleted: ");
        scanf("%d", &player_index);
        getchar();
    }

    player_index--;
    //can only delete the entire record and not a particular information of a record
    for (int i = player_index; i < MAX_PLAYERS - 1; i++) 
    {
        details[i] = details[i + 1];
    }

    memset(&details[MAX_PLAYERS - 1], 0, sizeof(player_details)); //deleting the last record since every record shifted one index up and also this deals with the case where we want to delete the last record
    printf("Record deleted successfully!!\n\n");
    
    FILE *fptr = fopen(ALL_PLAYERS_FILE, "w");

    if (fptr == NULL) 
    {
    printf("Error opening file for writing\n");
    return; 
    }

    for (int i = 0; i < MAX_PLAYERS; i++)
    {        
        fprintf(fptr, "%s\n%s\n%s\n%s\n%s\n%s\n", details[i].player_name, details[i].player_team, details[i].batter_1, details[i].batter_2, details[i].bowler_1, details[i].bowler_2); 
        //the order is such that player name, player team, batter type, batter handedness, bowler type, bowler arm
    }

    fclose(fptr); 

}