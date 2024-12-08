#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void InitializeInventory(char ***species_of_supplies, int *num_of_supplies, int num_of_species);
void AddSupplies(char ***species_of_supplies, int *num_of_supplies, int species_index);
void UpdateSupply(char ***species_of_supplies, int num_of_supplies);
void RemoveSpecies(char ***species_of_supplies, int **num_of_supplies, int *num_of_species, int species_index);
void DisplayInventory(char **species, char ***species_of_supplies, int *num_of_supplies, int num_of_species);
void FreeInventory(char ***species_of_supplies, char **species, int *num_of_supplies, int num_of_species);

int main() {
   
    int num_of_species, choice;
    char **species;
    char ***species_of_supplies;
    int *num_of_supplies;

    printf("Enter the number of species: ");
    scanf("%d", &num_of_species);

    species = (char **)malloc(num_of_species * sizeof(char *));
    species_of_supplies = (char ***)malloc(num_of_species * sizeof(char **));
    num_of_species = (int *)malloc(num_of_species * sizeof(int));

    for (int i = 0; i < num_of_species; i++) 
    {
        species_of_supplies[i] = NULL;
        num_of_supplies[i] = 0;
        species[i] = (char *)malloc(50 * sizeof(char));
        
        printf("Enter the name of species %d: ", i + 1);
        scanf("%s", species[i]);
    }

    do 
    {
        printf("\nMenu:\n");
        printf("1.Add Supplies\n");
        printf("2.Update Supply\n");
        printf("3.Remove Species\n");
        printf("4.Display Inventory\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                int species_index;
                printf("Enter the index of the species to add supplies (1 to %d): ", num_of_species);
                scanf("%d", &species_index);
                
                if (species_index < 1 || species_index > num_of_species) 
                {
                    printf("Invalid species index!!\n");
                } 
                
                else 
                {
                    AddSupplies(species_of_supplies, num_of_supplies, species_index - 1);
                }
                break;
            }
            
            case 2: 
            {
                int species_index, supply_index;
                printf("Enter the species index (1 to %d): ", num_of_species);
                scanf("%d", &species_index);
                
                if (species_index < 1 || species_index > num_of_species || num_of_supplies[species_index - 1] == 0) 
                {
                    printf("Either invalid species or no supplies to update!!\n");
                } 
                
                else 
                {
                    printf("Enter the supply index (1 to %d): ", num_of_supplies[species_index - 1]);
                    scanf("%d", &supply_index);
                    
                    if (supply_index < 1 || supply_index > num_of_supplies[species_index - 1]) 
                    {
                        printf("Invalid supply index!!\n");
                    } 
                    
                    else 
                    {
                        printf("Enter the new name for the supply: ");
                        char temp[50];
                        scanf("%s", temp);
                        
                        strcpy(species_of_supplies[species_index - 1][supply_index - 1], temp);
                        printf("Supply has been updated successfully!!\n");
                    }
                }
                break;
            }
           
            case 3: 
            {
                int species_index;
                printf("Enter the index of the species to remove (1 to %d): ", num_of_species);
                scanf("%d", &species_index);
                
                if (species_index < 1 || species_index > num_of_species) 
                {
                    printf("Invalid species index!!\n");
                } 
                
                else 
                {
                    RemoveSpecies(species_of_supplies, &num_of_supplies, &num_of_species, species_index - 1);
                }
                break;
            }
            
            case 4:
               
                DisplayInventory(species, species_of_supplies, num_of_supplies, num_of_species);
                break;
            
            case 5:
                
                FreeInventory(species_of_supplies, species, num_of_supplies, num_of_species);
                printf("Exiting the program..........\n");
                break;
           
            default:
                
                printf("Invalid choice!! Enter valid choice.....\n");
        }
    } while (choice != 5);

    return 0;
}

void AddSupplies(char ***species_of_supplies, int *num_of_supplies, int species_index) 
{
    int num_of_new_supplies;
    printf("Enter the number of supplies to add: ");
    scanf("%d", &num_of_new_supplies);

    species_of_supplies[species_index] = (char **)realloc(species_of_supplies[species_index], (num_of_supplies[species_index] + num_of_new_supplies) * sizeof(char *));
    
    for (int i = 0; i < num_of_new_supplies; i++) 
    {
        species_of_supplies[species_index][num_of_supplies[species_index] + i] = (char *)malloc(50 * sizeof(char));
        
        printf("Enter supply %d: ", i + 1);
        scanf("%s", species_of_supplies[species_index][num_of_supplies[species_index] + i]);
    }
    
    num_of_supplies[species_index] += num_of_new_supplies;
}

void RemoveSpecies(char ***species_of_supplies, int **num_of_supplies, int *num_of_species, int species_index) 
{
  
    for (int i = 0; i < (*num_of_supplies)[species_index]; i++) 
    {
        free(species_of_supplies[species_index][i]);
    }
    free(species_of_supplies[species_index]);

    for (int i = species_index; i < *num_of_species - 1; i++) 
    {
        species_of_supplies[i] = species_of_supplies[i + 1];
        (*num_of_supplies)[i] = (*num_of_supplies)[i + 1];
    }

    (*num_of_species)--;
}

void DisplayInventory(char **species, char ***species_of_supplies, int *num_of_supplies, int num_of_species) 
{
    for (int i = 0; i < num_of_species; i++) 
    {
        printf("%s: ", species[i]);
        
        if (num_of_supplies[i] == 0) 
        {
            printf("No supplies!!\n");
        } 
        
        else 
        {
            for (int j = 0; j < num_of_supplies[i]; j++) 
            {
                printf("%s ", species_of_supplies[i][j]);
            }
            printf("\n");
        }
    }
}

void FreeInventory(char ***species_of_supplies, char **species, int *num_of_supplies, int num_of_species) 
{
    for (int i = 0; i < num_of_species; i++) 
    {
        for (int j = 0; j < num_of_supplies[i]; j++) 
        {
            free(species_of_supplies[i][j]);
        }
        free(species_of_supplies[i]);
        free(species[i]);
    }
    
    free(species_of_supplies);
    free(species);
    free(num_of_supplies);
}
