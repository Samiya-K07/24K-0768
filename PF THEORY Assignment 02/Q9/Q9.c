#include <stdio.h>

void UpDown(char gridarray[][5], int *i, int *j, int *k, int *items);
void LeftRight(char gridarray[][5], int *i, int *j, int *k, int *items);
void PrintGrid(char gridarray[5][5]);

int main () {
    
    char gridarray[5][5] = 
    { {' ', ' ', 'I', 'X', ' '},
      {' ', 'X', ' ', ' ', ' '},
      {'I', ' ', 'X', 'X', ' '},
      {' ', ' ', ' ', 'I', 'X'},
      {' ', 'X', ' ', ' ', 'P'}
    };

    printf("Welcome to Grid Adventure Game.\n\n");
    printf("Enter following keys to play\nW: UP\nS: DOWN\nA: LEFT\nD: RIGHT\nQ: QUIT.\n\n");
    printf("Let's Start!!\n");
    
    int p1 = 4, p2 = 4, items = 0;

    char x;

    while(x!='Q')
    {
        int p3 = 0;

        PrintGrid(gridarray);
        printf("\nEnter your move: ");
        scanf(" %c", &x);

        if(x=='W')
        {
            p3 = p1 - 1;
            UpDown(gridarray, &p2, &p1, &p3, &items);
        }
        else if(x =='S')
        {
            p3 = p1 + 1;
            UpDown(gridarray, &p2, &p1, &p3, &items);
        }
        else if(x =='A')
        {
            p3 = p2 - 1;
            LeftRight(gridarray, &p1, &p2, &p3, &items);
        }
        else if(x=='D')
        {
            p3 = p2 + 1;
            LeftRight(gridarray, &p1, &p2, &p3, &items);
        }
        else if(x =='Q')
        { 
            printf("\nThe game has ended!!\n");
            printf("Collected items are: %d", items);

            return 0;
        }
        
        else 
        {
            printf("Invalid Input\n");
        }
    }

    return 0;
}

void PrintGrid(char gridarray[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("|'%c'", gridarray[i][j]);
        }

        printf("|\n");
    }
}

void UpDown(char gridarray[][5], int *i, int *j, int *k, int *items)
{
    if(*k >= 0 && *k <= 4)
    {
        if(gridarray[*k][*i] == ' ' || gridarray[*k][*i] == 'I')
        {
            if(gridarray[*k][*i] == 'I') 
            {
                (*items)++;
            }

            gridarray[*j][*i] = ' ';
            gridarray[*k][*i] = 'P';
            *j = *k;
        }
    }
    
    else 
    {
        printf("Invalid Input\n");
    }
    
    return;
}

void LeftRight(char gridarray[][5], int *i, int *j, int *k, int *items)
{
    if(*k >= 0 && *k <= 4)
    {
        if(gridarray[*i][*k] == ' ' || gridarray[*i][*k] == 'I')
        {
            if(gridarray[*i][*k] == 'I') 
            {
                (*items)++;
            }

            gridarray[*i][*j] = ' ';
            gridarray[*i][*k] = 'P';
            *j = *k;
        }
    }
    
    else 
    {
        printf("Invalid Input\n");
    }

    return;
}