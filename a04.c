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
	double		sumTwo = 0;
	double		sumThree = 0;
	double		sumFour = 0;
	double		sumFive = 0;
	double		sumSix = 0;
	double		sumSeven = 0;
	double		sumEight = 0;
	double		sumNine = 0;
	double		sumTen = 0;
	double		*ptr;
	double		*arraySize = &array[ARRAY_SIZE];
	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - Paul Hubbard\n");

	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...
		
			for(ptr = array; ptr < arraySize; ptr = ptr + 30){
				sum = sum + *ptr + *(ptr + 1) + *(ptr + 2) + *(ptr + 3);
				sumTwo = sumTwo + *(ptr + 4) + *(ptr + 5) + *(ptr + 6);
				sumThree = sumThree + *(ptr + 7) + *(ptr + 8) + *(ptr + 9);
				sumFour = sumFour + *(ptr + 10) + *(ptr + 11);
				sumFive = sumFive + *(ptr + 12) + *(ptr + 13) + *(ptr + 14);
				sumSix = sumSix + *(ptr + 15) + *(ptr + 16) + *(ptr + 17);
				sumSeven = sumSeven + *(ptr + 18) + *(ptr + 19) + *(ptr + 20);
				sumEight = sumEight + *(ptr + 21) + *(ptr + 22) + *(ptr + 23);
				sumNine = sumNine + *(ptr + 24) + *(ptr + 25) + *(ptr + 26);
				sumTen = sumTen + *(ptr + 27) + *(ptr + 28) + *(ptr + 29);
				
			}
		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.
		
		}
	//printf("sum: %f\n", sum);

	// You can add some final code between this comment ...
		sum = sum + sumTwo + sumThree + sumFour + sumFive + sumSix + sumSeven + sumEight + sumNine + sumTen;
	// ... and this one.

	return 0;
}
