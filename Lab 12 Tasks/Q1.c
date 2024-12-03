#include<stdio.h>
#include<stdlib.h>

struct class 
{
    char name[50];
    int roll_no;
    float marks;
};

float avg(int n, int sum, struct class data[])
{
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + data[i].marks;
    }
    
    int avg = sum/n;
    return avg;
}

int main() {
    
    int n, sum;
    printf("Enter the number of students: \n");
    scanf("%d", &n);
    
    struct class *data =(struct class*)malloc(n * sizeof(struct class));
    
    if (!data)
    {
        printf("Memory Allocation failed!! Exiting.....");
        return 1;
    }
    
    printf("Enter details for students: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: \n");
        scanf(" %[^\n]", data[i].name);
        
        printf("Roll Number: \n");
        scanf("%d", &data[i].roll_no);
        
        printf("Marks Obtained: \n");
        scanf("%f", &data[i].marks);
    }
    
    float result=avg(n, sum, data);
    printf("Average Marks for this class are: %.1f", result);
}