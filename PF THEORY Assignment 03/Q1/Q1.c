#include<stdio.h>
#include<string.h>

typedef struct 
{
    int employee_code;
    char employee_name[20];
    int date_of_joining;
    int month_of_joining;
    int year_of_joining;
} Employee;


void Input(Employee *emp)
{
    printf("Enter Employee name: \n");
    scanf(" %[^\n]", emp->employee_name);
    
    printf("Enter Employee code: \n");
    scanf("%d", &emp-> employee_code);
    
    printf("Enter Employee date of joining in the DDMMYYY format: \n");
    scanf("%d %d %d", &emp->date_of_joining, &emp->month_of_joining, &emp->year_of_joining);
}

void CheckTenure(Employee emp[])
{
    int current_date, current_month, current_year;
   
    printf("Enter today's date in DDMMYYYY format : \n");
    scanf("%d %d %d", &current_date, &current_month, &current_year);
    
    int count = 0;
    
    printf("Employees who have been working for more than 3 years with us:\n");
    
    for (int i = 0; i < 4; i++)
    {
        int years = current_year-emp[i].year_of_joining;
        
        if (current_month<emp[i].month_of_joining || (current_month == emp[i].month_of_joining && current_date < emp[i].date_of_joining))
        {
            years--;
        }
        
        if (years > 3)
        {
            printf("Employee name: %s\n", emp[i].employee_name);
            printf("Employee code: %d\n", emp[i].employee_code);
            printf("Date of joining: %d/%d/%d\n", emp[i].date_of_joining, emp[i].month_of_joining, emp[i].year_of_joining);
        }  
    }
    
    printf("Total Number of employees with tenure of more than 3 years: %d\n", count);
}
    
int main() {
    
    Employee emp[4];
    
    printf("Enter employees details: \n");
    
    for (int i = 0; i < 4; i++)
    {
        Input(&emp[i]);
    }
    
    CheckTenure(emp);
}
