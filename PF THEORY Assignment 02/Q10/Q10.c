#include<stdio.h>

int main(){
    int x, space, innerspace, i , j , k;

    printf("Enter any number: ");
    scanf("%d", &x);

    space = (x * 2) - 2;
    innerspace = 0;

    for(i = 0; i <  x - 1; i++)
    {
        for(j = 0; j < space; j++)
        {
            printf(" ");
        }

        printf("*");

        for(k = 0; k < innerspace; k++)
        {
            printf(" ");
        }

        if(k != 0)
        {
            printf("*");
        }

    printf("\n");

        space--;

        if(i == 0)
        {
            innerspace++;
        }
        else
        {
            innerspace = innerspace + 2;
        }
    }


    for(i = 0 ;  i < x; i++)
    {
        printf("*");
    }

    for(i = 0;  i < innerspace; i++)
    {
        printf(" ");
    }

    for(i = 0 ;  i < x; i++)
    {
        printf("*");
    }


    printf("\n");
    innerspace = (innerspace * 2) - 1;
    space = 1;

    for(i = 0; i < x - 1;  i++)
    {
        for(j = 0; j  < space; j++)
        {
            printf(" ");
        }

        printf("*");

        for(k = 0 ; k < innerspace; k++)
        {
            printf(" ");
        }

        printf("*");
        printf("\n");

        innerspace = innerspace + 2;
        space++;

    }
    
    space = x - 2;
    innerspace = 1;
    
    for(i = 0; i < x - 2; i++)
    {
        for(j = 0; j < space; j++)
        {
            printf(" ");
        }
        
        printf("*");
        
        for(k = 0; k < space; k++)
        {
            printf(" ");
        }

        printf("*");
        
        for(j = 0;  j < innerspace; j++)
        {
            printf(" ");
        }
        
        printf("*");
        
        for( j = 0; j < space; j++)
        {
            printf(" ");
        }
        
        printf("*");
        printf("\n");
        
        space --;
        innerspace = innerspace + 4;

    }
   
    innerspace = innerspace + 2;
    
    printf("*");
    
    for(j = 0; j < innerspace; j++)
    {
        printf(" ");
    }

    printf("*");
    
    return 0;
}
