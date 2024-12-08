#include<stdio.h>
#include<string.h>

struct Employee
{
    int employeeCode;
    char employeeName[20];
    int dateOfJoining;
    int monthOfJoining;
    int yearOfJoining;
};

void input(struct Employee *emp)
{
    printf("Enter Employee's Name: \n");
    scanf(" %[^\n]", emp->employeeName);
    printf("Enter Employee's Code: \n");
    scanf("%d", &emp->employeeCode);
    printf("Enter Employee's Date of Joining in the DDMMYYY format: \n");
    scanf("%d %d %d", &emp->dateOfJoining, &emp->monthOfJoining, &emp->yearOfJoining);
}

void checkTenure(struct Employee emp[])
{
    int currDate, currMonth, currYear;
    printf("Enter today's date in DDMMYYYY format : \n");
    scanf("%d %d %d", &currDate, &currMonth, &currYear);
    
    int count = 0;
    printf("Employees who have been working for more than 3 years with us: \n");
    
    for (int i = 0; i < 4; i++)
    {
        int years = currYear - emp[i].yearOfJoining;
        if (currMonth < emp[i].monthOfJoining || (currMonth == emp[i].monthOfJoining && currDate < emp[i].dateOfJoining))
        {
            years--;
        }
        
        if (years > 3)
        {
            printf("Employee Name: %s\n", emp[i].employeeName);
            printf("Employee Code: %d\n", emp[i].employeeCode);
            printf("Date of Joining: %d/%d/%d\n", emp[i].dateOfJoining, emp[i].monthOfJoining, emp[i].yearOfJoining);
        }  
    }
    
    printf("Total Number of employees with tenure of more than 3 years: %d\n", count);
}
    
int main() {
    
    struct Employee emp[4];
    printf("Enter employees' details: \n");
    
    for (int i = 0; i < 4; i++)
    {
        input(&emp[i]);
    }
    checkTenure(emp);
}
