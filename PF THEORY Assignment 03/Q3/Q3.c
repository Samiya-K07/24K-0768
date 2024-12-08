#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int ValidateEmail(char* email)
{
    int count = 0, period = 0, position = -1;
    
    if (email == NULL || strlen(email) == 0)
    {
        printf("Enter an email address!!");
        return 0;
    }
    
    for (int i=0; email[i]!='\0'; i++)
    {
        if (email[i] =='@')
        {
            count++;
            position=i;
        }
   
        if (count == 1 && email[i] == '.' && i > position)
        {
            period++;
        }
    }
    
    if (period==1 && count==1)
    {
        printf("Valid email!!");
        return 1;

    }
    
    else 
    {
        printf("Invalid email!!");
        return 0;
    }
}

int main() {
    
    char *email = (char*)malloc(256*sizeof(char));
    
    if (email == NULL)
    {
        printf("Memory allocation failed!!");
        return 1;
    }
    
    printf("Enter your email address: \n");
    scanf(" %[^\n]", email);

    ValidateEmail(email);
    free(email);
    
    return 0;
}
