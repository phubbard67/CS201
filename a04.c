#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000

int main(void)
{
	double	*array = calloc(ARRAY_SIZE, sizeof(double));
	double	sum = 0;
	int		i;

	// You can add variables between this comment ...
	//double 		sumTwo = 0;
	double		*ptr;
	double 		*arraySize = &array[ARRAY_SIZE];
	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - I. Paul Hubbard\n");

	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...

		//long int    j;
		
			for(ptr = array; ptr < arraySize; ptr+=8){
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 2;
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 3;
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 4;
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 5;
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 6;
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 7;
			sum = *ptr;
			sum = sum + sum;
			ptr = ptr + 8;
			sum = *ptr;
			sum = sum + sum;
			}
		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.
		
		}
	//printf("sum: %f\n", sum);

	// You can add some final code between this comment ...

	// ... and this one.

	return 0;
}
