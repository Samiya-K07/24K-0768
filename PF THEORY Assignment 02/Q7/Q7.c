#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

fill(char array[6][5]) 
{
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            array[i][j] = 'A' + (rand() % 26);
        }
    }
    
    array[5][0] = '0';
    array[5][1] = '5';
    array[5][2] = '6';
    array[5][3] = '0';
}

disparr(char array[6][5]) 
{
    printf("\nCharacter Array:\n");
    
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

int search_function(char array[6][5], const char *str) \
{
    int length = strlen(str);
    
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j <= 5 - length; j++) 
        {
            if (strncmp(&array[i][j], str, length) == 0) 
            {
                //Found horizontally
                return 1; 
            }
        }
    }

    // Search vertically (top to down)
    for (int j = 0; j < 6; j++) 
    {
        for (int i = 0; i <= 5 - length; i++) {
            
            int found = 1;
            
            for (int k = 0; k < length; k++) 
            {
                if (array[i + k][j] != str[k]) 
                {
                    found = 0;
                    break;
                }
            }
            
            if (found == 1) 
            {
                // Found vertically
                return 1; 
            }
        }
    }

    // Not found
    return 0; 
}

int main () {
    
    char string[6][5];
    char temp[100];
    int score = 0;

    srand(time(NULL)); //for randomization

    while (1) 
    {
        fill(string);
        disparr(string);

        while (1) 
        {
            printf("Enter a string you need to search (or type 'END' to repopulate): ");
            scanf("%s", temp);

            if (strcmp(temp, "END") == 0) 
            {
                break; 
            }

            if (search(string, temp)) 
            {
                //incrementing the score if found
                score++; 
                
                printf("%s is present!! Score: %d\n", temp, score);
            } 
            
            else 
            {
                //decrementing the score if not found
                score--; 
                printf("%s is not present!! Score: %d\n", temp, score);
            }
        }
    }

    return 0;
}
