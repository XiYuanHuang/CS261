#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file)
{
 /* prototype */
	int maxLength = 16;
    	int length = 0;
    	char* word = malloc(sizeof(char) * maxLength);

   	while (1)
    	{
        	char c = fgetc(file);
        	if ((c >= '0' && c <= '9') ||
            	(c >= 'A' && c <= 'Z') ||
            	(c >= 'a' && c <= 'z') ||
            	c == '\'')
        	{	
            		if (length + 1 >= maxLength){
                		maxLength *= 2;
                		word = realloc(word, maxLength);
            		}
            		if((c >= 'A') && (c <='Z')){
                		c += 32;
            		}
            		word[length] = c;
            		length++;
        	}else if (length > 0 || c == EOF){
            		break;
        	}
    	}	
    	if (length == 0)
    	{
        	free(word);
        	return NULL;
    	}
    	word[length] = '\0';
    	return word;
}
/****************************************/

int main (int argc, const char * argv[]) {
    /*Write this function*/

    	const char* fileName;
	struct hashMap *ht;
    	FILE* f;
	char* word;
	int v, i;
	struct hashLink* current;
	if (argc > 1)
    	{
        fileName = argv[1];
    	}
    	printf("Opening file: %s\n", fileName);

    	ht = malloc(sizeof(struct hashMap));
    	initMap(ht, 10);

 
    	f = fopen(fileName, "r");

    	word = getWord(f);
    	v = 1;
    	while(word != 0){
        	insertMap(ht, word, v);
        	free(word);
        	word = getWord(f);
    	}	


    	assert(ht != 0);
    	printf("\n");
    	for(i = 0; i < ht->tableSize; i++){
        	printf("Bucket %d: ", i);
        	current = ht->table[i];
        	while(current != 0){
            		printf("%s: %d", current->key, current->value);
            		current = current->next;
	    		printf("   "); 
        	}
        	printf("\n");
    	}
	

	fclose(f);

	freeMap(ht);
	free(ht);	
return 0;
}

