/* CS261- HW1 - Program2.c*/
/* Name:XiYuan Huang
 * Date:4/8/2019
 * Solution description:This program will allocate memory for the struct student. 
 * Then it will assign the name and score to each student. 
 * The max, min and average score will be calculated and print out. Lastly, it will free the memory.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *s;
	s = (struct student *) malloc(10*sizeof(struct student));     
     /*return the pointer*/
	return s;
}

void generate(struct student* students){
	int i,j;
	srand(time(NULL));
	/*assert (students >= 0);*/
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
	for(i = 0; i < 10; i++){
		for(j = 0; j < 2; j++){
			(students+i)->initials[j] = rand()%26 + 'A';
		}
		(students+i)->score = rand()%100 + 1;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	int i,j;
	for(i = 0; i < 10; i++){
		printf("Student %d initial: ", i+1);
		for(j = 0; j < 2; j++){
			printf("%c",(students + i)->initials[j]);
		}
		printf("  score: %d\n",(students + i)->score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = 100, max = 0, total = 0, avg, i;
    for(i = 0; i < 10; i++){
	if((students + i)->score <= min){
		min = (students + i)->score;
	}
	if((students + i)->score >= max){
		max = (students + i)->score;
	}
	total += (students + i)->score;
    }
	avg = total / 10;
	printf("\nMaximum score: %d, Minimum score: %d, Average score: %d\n", max, min, avg); 
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if(stud != NULL ){
		free(stud);
		stud = 0;
    	}
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);	
    return 0;
}

