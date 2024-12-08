#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{

    char title[100];
    float rating;
    int runtime;     
    char encoding[50];
} ContentMetadata ;

typedef struct 
{
    char resolution[20];
    char playback_history[200];
    float band_width_usage; 
} DevicePreferences;

double** InitializeEngagementMatrix(int num_of_users, int num_of_categories);
DevicePreferences*** InitializeDeviceMatrix(int num_of_users, int num_of_devices);
ContentMetadata*** InitializeContentMatrix(int num_of_categories, int num_of_contents);
void DisplayEngagementMatrix(double** matrix, int num_of_users, int num_of_categories);
void FreeEngagementMatrix(double** matrix, int num_of_users);
void freeDeviceMatrix(DevicePreferences*** matrix, int num_of_users, int num_of_devices);
void freeContentMatrix(ContentMetadata*** matrix, int num_of_categories, int num_of_contents);

int main() {
    
    int num_of_users, num_of_categories, num_of_devices, num_of_contents;

    printf("Enter the number of users: ");
    scanf("%d", &num_of_users);
    
    printf("Enter the number of content categories: ");
    scanf("%d", &num_of_categories);
    
    printf("Enter the number of devices per user: ");
    scanf("%d", &num_of_devices);
    
    printf("Enter the number of contents per category: ");
    scanf("%d", &num_of_devices);

    double** EngagementMatrix = InitializeEngagementMatrix(num_of_users, num_of_categories);

    DevicePreferences*** DeviceMatrix = InitializeDeviceMatrix(num_of_users, num_of_devices);
    ContentMetadata*** ContentMatrix = InitializeContentMatrix(num_of_categories, num_of_contents);

    printf("\nEngagement Matrix:\n");
    DisplayEngagementMatrix(EngagementMatrix, num_of_users, num_of_categories);

    FreeEngagementMatrix(EngagementMatrix, num_of_users);
    FreeDeviceMatrix(DeviceMatrix, num_of_users, num_of_devices);
    FreeContentMatrix(ContentMatrix, num_of_categories, num_of_contents);

    return 0;
}

double** InitializeEngagementMatrix(int num_of_users, int num_of_categories) 
{
    double** matrix = (double**)malloc(num_of_users * sizeof(double*));
    
    for (int i = 0; i < num_of_users; i++) 
    {
        matrix[i] = (double*)malloc(num_of_categories * sizeof(double));
        
        for (int j = 0; j < num_of_categories; j++) 
        {
            matrix[i][j] = (rand() % 100) / 10.0; 
        }
    }
    
    return matrix;
}


DevicePreferences*** InitializeDeviceMatrix(int num_of_users, int num_of_devices) 
{
    DevicePreferences*** matrix = (DevicePreferences***)malloc(num_of_users * sizeof(DevicePreferences**));
    
    for (int i = 0; i < num_of_users; i++) 
    {
        matrix[i] = (DevicePreferences**)malloc(num_of_devices * sizeof(DevicePreferences*));
        
        for (int j = 0; j < num_of_devices; j++) 
        {
            matrix[i][j] = (DevicePreferences*)malloc(sizeof(DevicePreferences));
            snprintf(matrix[i][j]->resolution, 20, "1080p");
            snprintf(matrix[i][j]->playback_history, 200, "Watched 3 movies");
            matrix[i][j]->band_width_usage = (rand() % 100) / 10.0;
        }
    }
    
    return matrix;
}

ContentMetadata*** InitializeContentMatrix(int num_of_categories, int num_of_contents) 
{
    ContentMetadata*** matrix = (ContentMetadata***)malloc(num_of_categories * sizeof(ContentMetadata**));
    
    for (int i = 0; i < num_of_categories; i++) 
    {
        matrix[i] = (ContentMetadata**)malloc(num_of_contents * sizeof(ContentMetadata*));
        
        for (int j = 0; j < num_of_contents; j++) 
        {
            matrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
            snprintf(matrix[i][j]->title, 100, "Content %d-%d", i + 1, j + 1);
            matrix[i][j]->rating = (rand() % 50) / 10.0 + 5.0; 
            matrix[i][j]->runtime = (rand() % 120) + 60;       
            snprintf(matrix[i][j]->encoding, 50, "H.264");
        }
    }
    
    return matrix;
}

void DisplayEngagementMatrix(double** matrix, int num_of_users, int num_of_categories) 
{
    for (int i = 0; i < num_of_users; i++) 
    {
        printf("User %d: ", i + 1);
        for (int j = 0; j < num_of_categories; j++) 
        {
            printf("%.1f ", matrix[i][j]);
        }
        
        printf("\n");
    }
}

void FreeEngagementMatrix(double** matrix, int num_of_users) 
{
    for (int i = 0; i < num_of_users; i++) 
    {
        free(matrix[i]);
    }
    
    free(matrix);
}

void FreeDeviceMatrix(DevicePreferences*** matrix, int num_of_users, int num_of_devices) 
{
    for (int i = 0; i < num_of_users; i++) 
    {
        for (int j = 0; j < num_of_devices; j++) 
        {
            free(matrix[i][j]);
        }
        
        free(matrix[i]);
    }
    
    free(matrix);
}

void FreeContentMatrix(ContentMetadata*** matrix, int num_of_categories, int num_of_contents) 
{
    for (int i = 0; i < num_of_categories; i++) 
    {
        for (int j = 0; j < num_of_contents; j++) 
        {
            free(matrix[i][j]);
        }
        
        free(matrix[i]);
    }
    
    free(matrix);
}