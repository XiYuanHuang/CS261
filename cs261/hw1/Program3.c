/* CS261- HW1 - Program3.c*/
/* Name:XiYuan Huang
 * Date:4/9/2019
 * Solution description:The program will create an array by rand(), and sorts it in ascending order. 
 * It also prints out the array before and after the sorting process.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/     
	int i, j, temp;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(number[j] >  number[j+1]){
				temp = number[j];
				number[j] = number[j+1];
				number[j+1] = temp;
			}
		}
	}
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20, i, j;    
    /*Allocate memory for an array of n integers using malloc.*/
    	int* array = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/ 
	if(n != 0){
		for(i = 0; i < n; i++){	
			*(array + i) = rand();
		}
	}
    /*Print the contents of the array.*/
	if(n != 0){
		printf("The original array is: ");	
		for(j = 0; j < n; j++){
			printf("%d ",array[j]);
		} 
		printf("\n");
	}	
    /*Pass this array along with n to the sort() function of part a.*/
    	if(n != 0){
		sort(array, n);
	}
    /*Print the contents of the array.*/    
    	if(n != 0){
		printf("\nThe sorted array is: ");	
		for(j = 0; j < n; j++){
			printf("%d ",array[j]);
		} 
		printf("\n");
	}
	free(array);
    return 0;
}
