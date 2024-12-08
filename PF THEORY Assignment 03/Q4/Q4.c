#include <stdio.h>
#include <stdlib.h>

void InputEmployees(int **ratings, int num_of_employees, int num_of_periods);
void DisplayPerformance(int **ratings, int num_of_employees, int num_of_periods);
int FindEmployeeOfTheYear(int **ratings, int num_of_employees, int num_of_periods);
int FindHighestRatedPeriod(int **ratings, int num_of_employees, int num_of_periods);
int FindWorstPerformingEmployee(int **ratings, int num_of_employees, int num_of_periods);

int main() {
    
    int num_of_employees, num_of_periods;

    printf("Enter the number of employees: ");
    scanf("%d", &num_of_employees);
    
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &num_of_periods);

    int **ratings = (int **)malloc(num_of_employees * sizeof(int *));
    
    if (ratings == NULL) 
    {
        printf("Memory allocation failed!!\n");
        return 1;
    }
    
    for (int i = 0; i < num_of_employees; i++) 
    {
        ratings[i] = (int *)malloc(num_of_periods * sizeof(int));
        
        if (ratings[i] == NULL) 
        {
            printf("Memory allocation failed for employee %d!!\n", i + 1);
            return 1;
        }
    }

    InputEmployees(ratings, num_of_employees, num_of_periods);

    printf("\nEmployee Performance Ratings:\n");
    DisplayPerformance(ratings, num_of_employees, num_of_periods);

    int employee_of_the_year = FindEmployeeOfTheYear(ratings, num_of_employees, num_of_periods);
    printf("\nEmployee of the Year: Employee %d\n", employee_of_the_year + 1);

    int highest_rated_period = FindHighestRatedPeriod(ratings, num_of_employees, num_of_periods);
    printf("Highest Rated Period: Period %d\n", highest_rated_period + 1);

    
    int worst_employee = FindWorstPerformingEmployee(ratings, num_of_employees, num_of_periods);
    printf("Worst Performing Employee: Employee %d\n", worst_employee + 1);


    for (int i = 0; i < num_of_employees; i++) 
    {
        free(ratings[i]);
    }
    
    free(ratings);

    return 0;
}

void InputEmployees(int **ratings, int num_of_employees, int num_of_periods) 
{
    for (int i = 0; i < num_of_employees; i++) 
    {
        printf("\nEnter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < num_of_periods; j++) 
        {
            int rating;
            do 
            {
                printf("Period %d (1-10): ", j + 1);
                scanf("%d", &rating);
                
                if (rating < 1 || rating > 10) 
                {
                    printf("Invalid rating!! Please enter a value between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            
            ratings[i][j] = rating;
        }
    }
}

void DisplayPerformance(int **ratings, int num_of_employees, int num_of_periods) 
{
    for (int i = 0; i < num_of_employees; i++) 
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < num_of_periods; j++) 
        {
            printf("%d ", ratings[i][j]);
        }
        
        printf("\n");
    }
}

int FindEmployeeOfTheYear(int **ratings, int num_of_employees, int num_of_periods) 
{
    int best_employee = 0;
    double highest_average = 0.0;

    for (int i = 0; i < num_of_employees; i++) 
    {
        int total = 0;
        for (int j = 0; j < num_of_periods; j++) 
        {
            total += ratings[i][j];
        }
       
        double average = (double)total / num_of_periods;
        
        if (average > highest_average)
        {
            highest_average = average;
            best_employee = i;
        }
    }
    return best_employee;
}

int FindHighestRatedPeriod(int **ratings, int num_of_employees, int num_of_periods) 
{
    int best_period = 0;
    double highest_average = 0.0;

    for (int j = 0; j < num_of_periods; j++) 
    {
        int total = 0;
        
        for (int i = 0; i < num_of_employees; i++) 
        {
            total += ratings[i][j];
        }
        double average = (double)total / num_of_employees;
        
        if (average > highest_average) 
        {
            highest_average = average;
            best_period = j;
        }
    }
    return best_period;
}

int FindWorstPerformingEmployee(int **ratings, int num_of_employees, int num_of_periods) 
{
    int worst_employee = 0;
    double lowest_average = 10.0; 

    for (int i = 0; i < num_of_employees; i++) 
    {
        int total = 0;
        
        for (int j = 0; j < num_of_periods; j++) 
        {
            total += ratings[i][j];
        }
        double average = (double)total / num_of_periods;
        
        if (average < lowest_average) 
        {
            lowest_average = average;
            worst_employee = i;
        }
    }
    
    return worst_employee;
}
