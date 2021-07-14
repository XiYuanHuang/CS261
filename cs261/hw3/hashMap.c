#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <assert.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (struct hashLink**)malloc(sizeof(struct hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}		

void freeMap (struct hashMap * ht)
{  /*write this*/
	
	struct hashLink *cur;
	struct hashLink *next;
	int i;
	assert(ht != 0);
	for(i = 0; i < ht->tableSize; i++){
		cur = ht->table[i];
		while(cur != 0){
			next = cur->next;
			free(cur->key);
			free(cur);
			cur = next;
		}
	}
	free(ht->table);
	ht->count = 0;
}


void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	 int hashindex;
	 assert(ht != 0);
   	 assert(k != 0);

   	 hashindex = HASH_FUNCTION(k) % (ht->tableSize);
   	 if(hashindex < 0){
  	      hashindex += ht->tableSize;
  	  }

   	 if(containsKey(ht, k) == 1){
      		  int* val = atMap(ht, k);
       		 *val += v;
   	 }else{
		struct hashLink* cur = ht->table[hashindex];
		struct hashLink* newLink = malloc(sizeof(struct hashLink));
   		newLink->key = malloc(sizeof(char) * (strlen(k) + 1));
    		strcpy(newLink->key, k);
    		newLink->value = v;
    		newLink->next = cur;
		assert(newLink != 0);
        	ht->table[hashindex] = newLink;
        	ht->count++;
    	 }

   	 if(tableLoad(ht) > 10){
		int i;
		struct hashLink* current;
   		struct hashMap* temp = malloc(sizeof(struct hashMap));
		initMap(temp, 2*ht->tableSize);
    		for(i = 0; i < ht->tableSize; i++){
        		current = ht->table[i];
        		while(current != 0){
            			insertMap(temp, current->key, current->value);
            			current = current->next;
        		}
    		}
    		freeMap(ht);
    		ht->table = temp->table;
    		ht->count = temp->count;
    		ht->tableSize = temp->tableSize;
    		free(temp);
  	 }

	
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this*/
	struct hashLink* cur;
	int hashindex;
	assert(ht != 0);
	assert(k != 0);
	
    	hashindex = HASH_FUNCTION(k) % ht->tableSize;
   	if(hashindex < 0){
       		 hashindex += ht->tableSize;
    	}
	
    	cur = ht->table[hashindex];
    	while(cur != 0){
       		 if(strcmp(cur->key, k) == 0){
           		 return &(cur->value);
       		 }
        	cur = cur->next;
    	}

    	return NULL;


}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	int hashIndex;
	struct hashLink *cur;
	assert(ht != 0);	
	assert(k != 0);
	hashIndex = HASH_FUNCTION(k)%ht->tableSize;
	if(hashIndex < 0){
		hashIndex += ht->tableSize;
	}	
	cur = ht->table[hashIndex];
	while(cur != 0){
		if(strcmp(cur->key,k) == 0){	
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/
	int hashIndex;
	struct hashLink *cur, *last;
	assert(ht != 0);
	assert(k != 0);
	hashIndex = HASH_FUNCTION(k)% ht->tableSize;
	if(hashIndex < 0){
		hashIndex += ht->tableSize;
	}
	cur = ht->table[hashIndex];	
	if(containsKey(ht, k) == 1){
		if(strcmp(cur->key, k) == 0){
			ht->table[hashIndex] = cur->next;
		}
		else{
			while(strcmp(cur->key,k) != 0){
				last = cur;
				cur = cur->next;
			}
			last->next = cur->next;
		}
		free(cur->key);
		free(cur);	
		ht->count--;
	}	
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	assert(ht != 0);
	return ht->count;	
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
	assert(ht != 0);
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
	int i, count;
	assert(ht != 0);
	for(i = 0; i < ht->tableSize; i++){
		if(ht->table[i] == 0){
			count++;
		}
	}
	return count;
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
	float a, b,c;
	assert(ht != 0);
	a = ht->count;
	b = ht->tableSize;
	c = a/b;
	return c;	
}	
