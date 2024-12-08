#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[20];
    int ball_scores[12];
    int total_score;
} Players;

void PlayGame(Players player[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("PLAYER %d\n", i+1);
        printf("Enter your scores, you have 12 balls to play for!!\n");
            
            for (int j = 0; j < 12; j++)
            {
                printf("Ball# %d\n", j+1);
                scanf("%d", &player[i].ball_scores[j]);
            }
            
            printf("\n");
    }
}

void ValidateScore(Players player[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if ((player[i].ball_scores[j]>6) || player[i].ball_scores[j]<0)
            {
                player[i].ball_scores[j]=0;
            }
        }
    }
}

void FindWinner(Players player[])
{
    int found;
    
    for (int i = 0; i < 2; i++)
    {
        int max=player[0].total_score;
        
        for (int j = 0; j < 12; j++)
        {
            player[i].total_score+= player[i].ball_scores[j];
        }
        
        if(player[i].total_score > max)
        {
            player[i].total_score = max; 
            found=i;
        }
    }
    
    printf("Player %d Wins!!\n", found+1);
}

void AvgScore(Players player[])
{
    
    for (int i = 0; i < 2; i++)
    {
        player[i].total_score=0;
        float avg;
        
        for (int j = 0; j < 12; j++)
        {
            player[i].total_score+= player[i].ball_scores[j];
        }
       
        printf("Total Score for Player %d: %d\n", i+1, player[i].total_score);
        avg = (player[i].total_score)/12.0;
        printf("Average Score for Player %d: %.2f\n",i+1, avg);
    }
}

void DisplayMatchScoreboard(Players player[])
{
    printf("\nScore Board\n");
    
    for (int i = 0; i < 2; i++)
    {
        printf("PLAYER %d: %s\n", i+1, player[i].name);
        printf("Scores: ");
        
        for (int j = 0; j < 12; j++)
        {
            printf("%d ", player[i].ball_scores[j]);
        }
        printf("\n");
    }
    
    AvgScore(player);
    
}

int main() {
    
    Players player[2];
    printf("WELCOME TO CRICKET SHOWDOWN!\n");
    printf("Enter the names of the player: \n");
   
    for (int i = 0; i < 2; i++)
    {
        scanf(" %[^\n]", player[i].name);
    }
    
    PlayGame(player);
    ValidateScore(player);
    FindWinner(player);
    DisplayMatchScoreboard(player);
}
