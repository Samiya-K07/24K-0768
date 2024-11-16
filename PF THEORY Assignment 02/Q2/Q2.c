#include<stdio.h>
#include<string.h>

int main () {

char slogans[3][50] = {"buy now", "save big", "limited offer"};

int num_of_slogans = 3; 
char character; 

for (int i = 0; i < num_of_slogans; i++)
{
    int processed[256] = {0}; 

    for (int j = 0; slogans[i][j] != '\0'; j++)
    {
        processed[slogans[i][j]]++; 
    }

    printf("For \"%s\" : {", slogans[i]);
    int commas = 1; 

    for (int k = 0; slogans[i][k] != '\0'; k++) 
    {
        character = slogans[i][k];
        if (processed[(unsigned char)character] > 0) 
        {
            if (commas != 1) 
            {
                printf(", ");
            }
                printf("'%c': %d", character, processed[character]);
                processed[character] = 0;
                commas = 0;
        }
    }
        printf("}\n"); 
}

    return 0;
}
