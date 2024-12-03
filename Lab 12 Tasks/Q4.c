#include <stdio.h>
#include <stdlib.h>

struct Book 
{
    char title[100];
    char author[100];
    int publicationYear;
};

struct Library 
{
    struct Book *books;
    int numberofbooks;
};

int main() {
    
    struct Library *library;
    library = (struct Library *)malloc(sizeof(struct Library)); 
    
    if (!library) 
    {
        printf("Memory Allocation failed!! Exiting....\n");
        return 1;
    }

    library->numberofbooks = 5;

    library->books = (struct Book *)malloc(library->numberofbooks * sizeof(struct Book));
    
    if (!library->books) 
    {
        printf("Memory Allocation failed!! Exiting....\n");
        free(library);  
        return 1;
    }

    printf("Enter details for %d books:\n", library->numberofbooks);
   
    for (int i = 0; i < library->numberofbooks; i++) 
    {
        printf("Book %d:\n", i + 1);
        printf("Enter title: ");
        scanf(" %[^\n]", library->books[i].title); 
        printf("Enter author: ");
        scanf(" %[^\n]", library->books[i].author);  
        printf("Enter publication year: ");
        scanf("%d", &library->books[i].publicationYear);
    }
    
    printf("\nBooks published after the year 2000:\n");
    
    for (int i = 0; i < library->numberofbooks; i++) 
    {
        if (library->books[i].publicationYear > 2000) 
        {
            printf("%s\n", library->books[i].title);
        }
    }
    
    free(library->books); 
    free(library);         

    return 0;
}