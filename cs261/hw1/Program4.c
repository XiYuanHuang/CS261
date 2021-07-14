/* CS261- HW1 - Program4.c*/
/* Name:XiYuan Huang
 * Date:4/9/2019
 * Solution description:Redo the functions for the Program 2, and add a sort function for the student ID.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/     
	int i, j, k, temp;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if((students+j)->initials[0] > (students+j+1)->initials[0]){
				for(k = 0; k < 2; k++){
					temp = (students+j)->initials[k];
					(students+j)->initials[k]= (students+j+1)->initials[k];
					(students+j+1)->initials[k] = temp; 
				}
				temp = (students+j)->score;
				(students+j)->score= (students+j+1)->score;
				(students+j+1)->score = temp; 
			}else if((students+j)->initials[0] == (students+j+1)->initials[0]){
				if((students+j)->initials[1] > (students+j+1)->initials[1]){
					for(k = 0; k < 2; k++){
						temp = (students+j)->initials[k];
						(students+j)->initials[k]= (students+j+1)->initials[k];
						(students+j+1)->initials[k] = temp; 
					}
				}
				temp = (students+j)->score;
				(students+j)->score= (students+j+1)->score;
				(students+j+1)->score = temp; 

			}
		}
	}
	
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10, i, j;
	srand(time(NULL));		 
    /*Allocate memory for n students using malloc.*/
    	struct student *students;
	students = (struct student *) malloc(n*sizeof(struct student));     
    /*Generate random IDs and scores for the n students, using rand().*/
	
	if(n != 0){
		for(i = 0; i < 10; i++){
			for(j = 0; j < 2; j++){
				(students+i)->initials[j] = rand()%26 + 'A';
			}
			(students+i)->score = rand()%100 + 1;
		}
    /*Print the contents of the array of n students.*/
		printf("The original data\n");
		for(i = 0; i < 10; i++){
			printf("Student %d initial: ", i+1);
			for(j = 0; j < 2; j++){
				printf("%c",(students + i)->initials[j]);
			}
			printf("  score: %d\n",(students + i)->score);
		}
    /*Pass this array along with n to the sort() function*/
   		 sort(students, n);
    /*Print the contents of the array of n students.*/
   		printf("\nThe sorted data\n");
		for(i = 0; i < 10; i++){
			printf("Student %d initial: ", i+1);
			for(j = 0; j < 2; j++){
				printf("%c",(students + i)->initials[j]);
			}
			printf("  score: %d\n",(students + i)->score);
		} 
	}
	free(students);
    return 0;
}
