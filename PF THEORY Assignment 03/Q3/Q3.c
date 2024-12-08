#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email);

int main() {
    char *email;
    size_t size;

    printf("Enter the maximum length of the email address: ");
    scanf("%zu", &size);

    email = (char *)malloc((size + 1) * sizeof(char));
    
	if (email == NULL) 
	{
        	printf("Memory allocation failed.\n");
        	return 1;
    	}

    printf("Enter the email address: ");
    scanf(" %s", email); 

    if (validateEmail(email)) 
    {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}

int validateEmail(char *email) 
{
    if (email == NULL || strlen(email) == 0) 
    {
        return 0; 
    }

    int atCount = 0;
    char *atPosition = NULL;
    char *dotPosition = NULL;

    for (char *ptr = email; *ptr != '\0'; ptr++) 
    {
        if (*ptr == '@') 
	{
            atCount++;
            atPosition = ptr;
        }
        
	if (atPosition && *ptr == '.') 
	{
            dotPosition = ptr;
        }
    }

    if (atCount != 1) 
    {
        return 0; //must contain exactly one '@'
    }
    if (!dotPosition || dotPosition < atPosition) 
    {
        return 0; //must contain at least one '.' after '@'
    }
    
	return 1;
}
