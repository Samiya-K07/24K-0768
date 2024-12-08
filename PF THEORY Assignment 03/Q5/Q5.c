#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char ***speciesSupplies, int *numSupplies, int numSpecies);
void addSupplies(char ***speciesSupplies, int *numSupplies, int speciesIndex);
void updateSupply(char ***speciesSupplies, int numSupplies);
void removeSpecies(char ***speciesSupplies, int **numSupplies, int *numSpecies, int speciesIndex);
void displayInventory(char **species, char ***speciesSupplies, int *numSupplies, int numSpecies);
void freeInventory(char ***speciesSupplies, char **species, int *numSupplies, int numSpecies);

int main() {
   
    int numSpecies, choice;
    char **species;
    char ***speciesSupplies;
    int *numSupplies;

    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    species = (char **)malloc(numSpecies * sizeof(char *));
    speciesSupplies = (char ***)malloc(numSpecies * sizeof(char **));
    numSupplies = (int *)malloc(numSpecies * sizeof(int));

    for (int i = 0; i < numSpecies; i++) 
    {
        speciesSupplies[i] = NULL;
        numSupplies[i] = 0;
        species[i] = (char *)malloc(50 * sizeof(char));
        
        printf("Enter the name of species %d: ", i + 1);
        scanf("%s", species[i]);
    }

    do 
    {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                int speciesIndex;
                printf("Enter the index of the species to add supplies (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                
                if (speciesIndex < 1 || speciesIndex > numSpecies) 
                {
                    printf("Invalid species index!\n");
                } 
                
                else 
                {
                    addSupplies(speciesSupplies, numSupplies, speciesIndex - 1);
                }
                break;
            }
            
            case 2: 
            {
                int speciesIndex, supplyIndex;
                printf("Enter the species index (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                
                if (speciesIndex < 1 || speciesIndex > numSpecies || numSupplies[speciesIndex - 1] == 0) 
                {
                    printf("Invalid species or no supplies to update!\n");
                } 
                
                else 
                {
                    printf("Enter the supply index (1 to %d): ", numSupplies[speciesIndex - 1]);
                    scanf("%d", &supplyIndex);
                    
                    if (supplyIndex < 1 || supplyIndex > numSupplies[speciesIndex - 1]) 
                    {
                        printf("Invalid supply index!\n");
                    } 
                    
                    else 
                    {
                        printf("Enter the new name for the supply: ");
                        char temp[50];
                        scanf("%s", temp);
                        strcpy(speciesSupplies[speciesIndex - 1][supplyIndex - 1], temp);
                        printf("Supply updated successfully!\n");
                    }
                }
                break;
            }
           
            case 3: 
            {
                int speciesIndex;
                printf("Enter the index of the species to remove (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                
                if (speciesIndex < 1 || speciesIndex > numSpecies) 
                {
                    printf("Invalid species index!\n");
                } 
                
                else 
                {
                    removeSpecies(speciesSupplies, &numSupplies, &numSpecies, speciesIndex - 1);
                }
                break;
            }
            
            case 4:
               
                displayInventory(species, speciesSupplies, numSupplies, numSpecies);
                break;
            
            case 5:
                freeInventory(speciesSupplies, species, numSupplies, numSpecies);
                printf("Exiting the program. Goodbye!\n");
                break;
           
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addSupplies(char ***speciesSupplies, int *numSupplies, int speciesIndex) 
{
    int numNewSupplies;
    printf("Enter the number of supplies to add: ");
    scanf("%d", &numNewSupplies);

    speciesSupplies[speciesIndex] = (char **)realloc(speciesSupplies[speciesIndex], (numSupplies[speciesIndex] + numNewSupplies) * sizeof(char *));
    
    for (int i = 0; i < numNewSupplies; i++) 
    {
        speciesSupplies[speciesIndex][numSupplies[speciesIndex] + i] = (char *)malloc(50 * sizeof(char));
        printf("Enter supply %d: ", i + 1);
        scanf("%s", speciesSupplies[speciesIndex][numSupplies[speciesIndex] + i]);
    }
    
    numSupplies[speciesIndex] += numNewSupplies;
}

void removeSpecies(char ***speciesSupplies, int **numSupplies, int *numSpecies, int speciesIndex) 
{
  
    for (int i = 0; i < (*numSupplies)[speciesIndex]; i++) 
    {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) 
    {
        speciesSupplies[i] = speciesSupplies[i + 1];
        (*numSupplies)[i] = (*numSupplies)[i + 1];
    }

    (*numSpecies)--;
}

void displayInventory(char **species, char ***speciesSupplies, int *numSupplies, int numSpecies) 
{
    for (int i = 0; i < numSpecies; i++) 
    {
        printf("%s: ", species[i]);
        
        if (numSupplies[i] == 0) 
        {
            printf("No supplies\n");
        } 
        
        else 
        {
            for (int j = 0; j < numSupplies[i]; j++) 
            {
                printf("%s ", speciesSupplies[i][j]);
            }
            printf("\n");
        }
    }
}

void freeInventory(char ***speciesSupplies, char **species, int *numSupplies, int numSpecies) 
{
    for (int i = 0; i < numSpecies; i++) 
    {
        for (int j = 0; j < numSupplies[i]; j++) 
        {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
        free(species[i]);
    }
    
    free(speciesSupplies);
    free(species);
    free(numSupplies);
}
