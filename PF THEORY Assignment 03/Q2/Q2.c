#include<stdio.h>
#include<string.h>

#define BALLS 12

struct Player 
{
    char playerName[50];
    int ballScores[BALLS];
    int totalScore;
};

void playGame(struct Player *player);
int validateScore(int score);
struct Player findWinner(struct Player player1, struct Player player2);
void displayMatchScoreboard(struct Player player1, struct Player player2);

int main() 
{
    struct Player player1 = { .totalScore = 0 };
    struct Player player2 = { .totalScore = 0 };

    printf("Enter Player 1 name: ");
    fgets(player1.playerName, 50, stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = 0; 

    printf("Enter Player 2 name: ");
    fgets(player2.playerName, 50, stdin);
    player2.playerName[strcspn(player2.playerName, "\n")] = 0;

    printf("\n-- Player 1 Turn --\n");
    playGame(&player1);

    printf("\n-- Player 2 Turn --\n");
    playGame(&player2);

    printf("\n-- Match Summary --\n");
    displayMatchScoreboard(player1, player2);

    struct Player winner = findWinner(player1, player2);
    
    if (winner.totalScore != -1) 
    {
        printf("\nWinner: %s with a total score of %d!\n", winner.playerName, winner.totalScore);
    } 
    
    else 
    {
        printf("\nIt's a tie!\n");
    }

    return 0;
}

void playGame(struct Player *player) 
{
    printf("Player: %s\n", player->playerName);
    
    for (int i = 0; i < BALLS; i++) 
    {
        int score;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) 
        {
            player->ballScores[i] = score;
            player->totalScore += score;
        } 
        
        else 
        {
            player->ballScores[i] = 0; 
            printf("Invalid score! Ball marked but no runs scored.\n");
        }
    }
}

int validateScore(int score) 
{
    return score >= 0 && score <= 6;
}

struct Player findWinner(struct Player player1, struct Player player2) 
{
    if (player1.totalScore > player2.totalScore) 
    {
        return player1;
    } 
    
    else if (player2.totalScore > player1.totalScore) 
    {
        return player2;
    } 
    
    else 
    {
        struct Player tie = { .totalScore = -1 }; 
        return tie;
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) 
{
    printf("\nScoreboard for %s:\n", player1.playerName);
    for (int i = 0; i < BALLS; i++)
    {
        printf("Ball %d: %d\n", i + 1, player1.ballScores[i]);
    }
    
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", player1.totalScore / (float)BALLS);

    printf("\nScoreboard for %s:\n", player2.playerName);
    for (int i = 0; i < BALLS; i++) 
    {
        printf("Ball %d: %d\n", i + 1, player2.ballScores[i]);
    }
    
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / (float)BALLS);
}
