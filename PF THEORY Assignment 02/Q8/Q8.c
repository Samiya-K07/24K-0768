#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXIMUM_HEX_LENGTH 20

//function prototypes
int BinaryToDecimal(int num);
int DecimalToBinary(int num);
void DecimalToHexadecimal(int num);
void HexadecimalToDecimal(char hexnum[]);
void BinaryToHexadecimal(int num);
void HexadecimalToBinary(char hexnum[]);

//function for displaying the menu to get the user choice
int Menu() 
{
    int option;
    
    printf("\nNumerical Conversion Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
    
    printf("Enter your choice: ");
    
    //validating the input

    while (scanf("%d", &option) != 1) 
    {
        printf("Invalid input!! Please enter a number\n");
        
        while(getchar() != '\n'); //for handling input efficiently 
        {
            printf("Enter your choice: ");
        }
    }
    
    return option;
}

int main () {
    
    int option, decimalnum, binarynum;
    char hexnum[MAXIMUM_HEX_LENGTH];

    while (1) //program runs until user exits the program
    {
        option = displayMenu(); //get user decided option

        switch (option) 
        {
            case 1:
            
                printf("Enter a binary number: ");
                scanf("%d", &binarynum);
                
                printf("Decimal equivalent: %d\n", BinaryToDecimal(binarynum));
                break;

            case 2:
                
                printf("Enter a decimal number: ");
                scanf("%d", &decimalnum);
                
                printf("Binary equivalent: %d\n", DecimalToBinary(decimalnum));
                break;

            case 3:
                
                printf("Enter a decimal number: ");
                scanf("%d", &decimalnum);
                
                DecimalToHexadecimal(decimalnum);
                break;

            case 4:
                
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexnum);
                
                HexadecimalToDecimal(hexnum);
                break;

            case 5:
                
                printf("Enter a binary number: ");
                scanf("%d", &binarynum);
                
                BinaryToHexadecimal(binarynum);
                break;

            case 6:
                
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexnum);
                
                HexadecimalToBinary(hexnum);
                break;

            case 7:
                
                printf("Exiting the program....\n");
                exit(0);

            default:
            {
                printf("Invalid choice! Please select a valid option.\n");
            }
        }
    }

    return 0;
}

//converting binary to decimal

int BinaryToDecimal(int num) 
{
    int decimal = 0, base = 1, remainder;
    
    while (num > 0) 
    {
        remainder = num % 10;
        decimal = decimal + (remainder * base);
        num = num/10;
        base = base * 2;
    }
    
    return decimal;
}

//converting decimal to binary
int DecimalToBinary(int num) 
{
    int binary = 0, base = 1;
    
    while (num > 0) {
        
        int lastdigit = num % 2;
        binary = binary + (lastdigit * base);
        num = num/2;
        base = base * 10;
    }
    
    return binary;
}

//converting decimal to hexadecimal
void DecimalToHexadecimal(int num) {
    
    char hex[20];
    int i = 0;

    if (num == 0) 
    {
        printf("Hexadecimal equivalent: 0\n");
        return;
    }

    while (num != 0) 
    {
        int temp = num % 16;
        
        if (temp < 10)
        {
            hex[i++] = temp + '0';
        }
        
        else
        {
            hex[i++] = temp - 10 + 'A';
        }
        
        num = num/16;
    }

    //displaying hexadecimal in reverse order
    
    printf("Hexadecimal equivalent: ");

    for (int j = i - 1; j >= 0; j--) 
    {
        putchar(hex[j]);
    }
    
    putchar('\n');
}

//converting hexadecimal to decimal
void HexadecimalToDecimal(char hexnum[]) 
{
    int decimal = (int)strtol(hexnum, NULL, 16);
    printf("Decimal equivalent: %d\n", decimal);
}

//convert binary to hexadecimal
void BinaryToHexadecimal(int num) 
{
    int decimal = BinaryToDecimal(num);
    DecimalToHexadecimal(decimal);
}

//converting hexadecimal to binary
void HexadecimalToBinary(char hexnum[]) 
{
    int decimal = (int)strtol(hexnum, NULL, 16);
    
    if (decimal == 0) 
    {
        printf("Binary equivalent: 0\n");
        return;
    }

    char binary[100];
    int index_num = 0;

    while (decimal > 0) 
    {
        binary[index_num++] = (decimal % 2) + '0';
        decimal = decimal/2;
    }

    //displaying binary in reverse order
    printf("Binary equivalent: ");
    for (int j = index_num - 1; j >= 0; j--) 
    {
        putchar(binary[j]);
    }
    
    putchar('\n');
}
