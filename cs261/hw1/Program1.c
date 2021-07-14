/* CS261- HW1 - Program1.c*/
/* Name:XiYuan Huang
 * Date:4/8/2019
 * Solution description:Define three variables and pass them to the foo
 * function. The function will do the calculation and return a value.
 * Print out all the variable before and after calling the foo function.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int foo(int* a, int* b, int c){
    /* Increment a */
    *a = *a + 1;
    
    /* Decrement  b */
    *b = *b - 1;
    /* Assign a-b to c */
    c = *a - *b;
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    	srand(time(NULL));
	int x,y,z,result;
	x = rand()%10 + 1;
	y = rand()%10 + 1;
	z = rand()%10 + 1;

    /* Print the values of x, y and z */
	printf("Initial values: x = %d, y = %d, z = %d\n",x,y,z);    
    /* Call foo() appropriately, passing x,y,z as parameters */
    	result = foo(&x,&y,z);
    /* Print the values of x, y and z */
    	printf("Final values: x = %d, y = %d, z = %d\n",x,y,z);   
    /* Print the value returned by foo */
 	printf("The result of foo funtion: %d\n", result);
    /* Is the return value different than the value of z?  Why? */
    /* The variable c is the copy of parameter z, and it will not affect
     * the value of z. So the value of z is the same before calling the foo and after calling the foo
     * The result is the return value from foo, and it is the difference between x and y.
     * It does not have any connection with the variable z. So they are different.*/
    return 0;
}
    

