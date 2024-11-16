#include <stdio.h>

void compressedword(char* word[], int num_of_words);

int main () {
	
    char* word[]= {"booooook", "coooool", "heeeey"};
	int num_of_words = sizeof(word)/sizeof(word[0]);
	
	compressed(word,num_of_words);
	
    return 0;
}	

void compressedword(char* word[], int num_of_words)
{
	char after_compressed[100];
	int eliminated = 0;
	
	printf("Compressed Words:\n");
	
    for(int i = 0; i < num_of_words; i++)
    {
		int a = 0;
		int og_length = 0;
		
		for(int j = 0; word[i][j] != '\0'; j++)
        {
			og_length++;
		    if(j == 0 || word[i][j] != word[i][j-1])
            {
				after_compressed[a] = word[i][j];
				a++;
			}
		}
		
        after_compressed[a] = '\0';
		
		int new_length = og_length - a;
		
		printf("%s -> %s (Removed %d characters)\n", word[i], after_compressed, new_length);
		eliminated = eliminated + new_length;
	}	
	
	printf("Total number of characters removed: %d\n", eliminated);
}	
