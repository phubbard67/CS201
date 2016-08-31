#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RND_CTL_BIT_SHIFT   10

// floating point rounding modes: IA-32 Manual, Vol. 1, p. 4-20
typedef enum {
    ROUND_NEAREST_EVEN =    0 << RND_CTL_BIT_SHIFT,
    ROUND_MINUS_INF =       1 << RND_CTL_BIT_SHIFT,
    ROUND_PLUS_INF =        2 << RND_CTL_BIT_SHIFT,
    ROUND_TOWARD_ZERO =     3 << RND_CTL_BIT_SHIFT
} RoundingMode;

// do not change anything above this comment

double roundD(double n, RoundingMode roundingMode)
{
	// here you will set the FPU rounding mode as specified,
	// and then round n to the nearest integer in the specified mode
	
	short int contInit; 
	double newN;
	short int bxHold;
	
	asm("		fnstcw	%[contInit]					\n" // sets the var to round control value
		"		movw	%[contInit], %%bx			\n" // move the control into a register
		"		and		$0xF3FF, %%bx				\n" // get the value of nInit to compare to
		"		or		%[roundingMode], %%bx		\n" // mask the round cont to get the rounding mode
		"		movw	%%bx, %[bxHold]				\n" // hold the value of the reg in a temp var
		"		fldcw	%[bxHold]					\n"	// put the temp value in the contrl reg
		"		fldl	%[n]						\n" // load in the float value
		"		frndint								\n" // round the integer
		"		fstpl	%[newN]						\n" // the output for in
		"		fldcw	%[contInit]					\n" // return control to the orig state
		
		:	[newN]	"=m"	(newN)						//output
		:	[contInit]	"m"		(contInit),				//inputs
			[roundingMode]	"m"	(roundingMode),
			[n]			"m"		(n),
			[bxHold]	"m"		(bxHold)
		:	"bx"										//it's clobbering time
	);

    return newN;
}

double hullSpeed(double lgth)
{
	// here you will compute the hull speed for the specified boat length,
	// implementing the numerical computation in GNU Assembly Language
	// through use of FPU instructions (do NOT call sqrt() from math.h)
	
	double multVal = 1.34;
	double knots;

	asm("		fldl	%[lgth]						\n" //load lgth into the stack
		"		fsqrt								\n" //square root the stack
		"		fldl	%[multVal]					\n" //load multVal onto the stack
		"		fmulp								\n"	//multiply the two values on the stack
		"		fstpl	%[knots]					\n" //load the value of the multipication into knots
	
		: [knots]	"=m"	(knots)						//output
		: [multVal]	"m"		(multVal),					//inputs
		  [lgth]	"m"		(lgth)
	);

	return knots;
}

// do not change anything below this comment, except for printing out your name

double hullSpeedC(double lgth)
{
	// this C implementation of the hull speed computation is provided
	// so you can compare its correct results with the results of your code

	return 1.34 * sqrt(lgth);
}

void printRounded(char *label, RoundingMode roundingMode,
				  double lgth, double hullSpd, double hullSpdC)
{
	printf("%s hullSpeed(%.0f) = %.0f, %.0f\n",
		   label, lgth,
		   roundD(hullSpd,  roundingMode),
		   roundD(hullSpdC, roundingMode));
}

int main (int argc, char **argv)
{
	double	lgth;
	double	hullSpd, hullSpdC;

	printf("CS201 - Assignment 02 -	Paul Hubbard\n");
	if (argc != 2) {
		printf("need 1 argument: boat length\n");
		return -1;
		}
	lgth = atof(argv[1]);
	hullSpd = hullSpeed(lgth);
	hullSpdC = hullSpeedC(lgth);

	printf("hullSpeed(%.0f) = %.3f, %.3f\n", lgth, hullSpd, hullSpdC);
	printRounded("round even:", ROUND_NEAREST_EVEN, lgth, hullSpd, hullSpdC);
	printRounded("round down:", ROUND_MINUS_INF,    lgth, hullSpd, hullSpdC);
	printRounded("round up:  ", ROUND_PLUS_INF,     lgth, hullSpd, hullSpdC);
	printRounded("round zero:", ROUND_TOWARD_ZERO,  lgth, hullSpd, hullSpdC);

	return 0;
}
