#include <stdio.h>

int main () {
    
    char *transaction[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    int group[6] = {0};
    int n = 6;

    printf("Grouped Anagrams:\n");

    for (int i = 0; i < n; i++) 
    {
        if (group[i] == 1) 
        {
            continue;
        }
        
        printf("[");
        group[i] = 1;

        int count[26] = {0};
        
        for (int j = 0; transaction[i][j] != '\0'; j++) 
        {
            count[transaction[i][j] - 'a']++;
        }
    
        
        printf("'%s'", transaction[i]);

        for (int k = i + 1; k < n; k++) 
        {    
            if (group[k] == 0) 
            { 
                int temp[26] = {0};

                for (int z = 0; transaction[k][z] != '\0'; z++) 
                {
                    temp[transaction[k][z] - 'a']++;
                }

                int anagram = 1; 
                
                for (int y = 0; y < 26; y++) 
                {
                    if (count[y] != temp[y]) 
                    {    
                        anagram = 0;
                        
                        break;
                    }
                }

                if (anagram == 1) 
                {  
                    printf(", '%s'", transaction[k]); 
                    group[k] = 1; 
                }
            }
        }
        
        printf("]\n"); 
    }

    return 0;
}

