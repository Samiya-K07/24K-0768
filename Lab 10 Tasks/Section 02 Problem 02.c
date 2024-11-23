#include<stdio.h>
#include<string.h>


struct movies{
    char title[100];
    char genre[100];
    int year;
    char arr[100];
    float rating;
};

void display(struct movies info[], int no_of_movies)
{
   printf("Details of available movies: \n");
    
    for (int i = 0; i < no_of_movies; i++)
    {
        printf("Movie  %d\n", i+1);
        printf("Title: %s\n", info[i].title);
        printf("Genre: %s\n", info[i].genre);
        printf("Director: %s\n", info[i].arr);
        printf("Year: %d\n", info[i].year);
        printf("Rating: %f\n", info[i].rating);
        printf("\n");
}
}
void add(struct movies info[], int *no_of_movies)
{
printf("Enter the following details: \n");

printf("Title: \n");
scanf(" %[^\n]", info[*no_of_movies].title);

printf("Genre: \n");
scanf(" %[^\n]",info[*no_of_movies].genre);

printf("Director: \n");
scanf(" %[^\n]", info[*no_of_movies].arr);

printf("Release Year: \n");
scanf("%d",&info[*no_of_movies].year);

printf("Rating: \n");
scanf("%f",&info[*no_of_movies].rating);
*no_of_movies++;

printf("Updated list: \n");

display(info, *no_of_movies);

}

void search(struct movies info[], int no_of_movies)
{
    char search[100];
    printf("Enter your genre: ");
    scanf(" %[^\n]", search);
    printf("Searched Results:\n");
    
    int result=0;
    
    for (int i = 0; i < no_of_movies; i++)
    {
        if (strstr(info[i].genre, search))
        {
            printf("Movie  %d\n", i+1);
            printf("Title: %s\n", info[i].title);
            printf("Genre: %s\n", info[i].genre);
            printf("Director: %s\n", info[i].arr);
            printf("Year: %d\n", info[i].year);
            printf("Rating: %.1f\n", info[i].rating);
            printf("\n");
            
            result=1;
        }
    }
       if (result!=1)
       {
            printf("No movies found!!");
       }
}


int main() {
    
    int no_of_movies = 3, choice;
    
    struct movies info[3]=
    {
        {"Scream", "Horror", 2020, "Jenna Ortega", 3.5 },
        {"The Hinger Games", "Thriller", 2023, "Lucy Gray", 4.5},
        {"Interstellar", "Sci-Fic", 2010, "Christopher Nolan", 4.4}
    };
    
    printf("Welcome!\n");
    printf("1. Add a new record\n");
    printf("2. Display all the movies in the inventory\n");
    printf("3. Search for a movie.\n");
    printf("Enter your option: \n");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
        add(info, &no_of_movies);
        break;
        
        case 2:
        display(info, no_of_movies);
        break;
        
        case 3:
        search(info, no_of_movies);
        break;
        
        default:
        printf("Invalid Option!!");
        return 0;
    }
    
    return 0;
}
