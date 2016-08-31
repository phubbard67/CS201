// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextHexInt()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static char *studentName = "Paul Hubbard";

// report whether machine is big or small endian

	//Unsigned int value for


void bigOrSmallEndian(){
	unsigned int testInt = 1;
	char *testChar = (char*) &testInt;

	if((int)*testChar == 1){
		printf("byte order: little-endian \n");
	}
	else{
		printf("byte order: big-endian \n");
	}
}


// get next int (entered in hex) using scanf()
// returns true (success) or false (failure)
// if call succeeded, return int value via iPtr
bool getNextHexInt(unsigned int *iPtr)
{
	// replace this code with the call to scanf()
	int userAddress = 0;
	int lowerLimit = -(pow(2.0, 31));
	int upperLimit = pow(2.0, 31) - 1;

	scanf("%X", &userAddress);

	if((userAddress >= lowerLimit) && (userAddress <= upperLimit)){
		*iPtr = userAddress;
		return true;
	}
	else{
		return false;	
	}
	
}

//function that creates a mask of all 1s
static int createMask(int bitNumber){
	return (1 << bitNumber) - 1;
}

// print requested data for the given number
void printNumberData(int i)
{

	
	static int NumOfFractBits = 23;
	static int NumOfExpBits = 8.0;
//	static int NumOfBits = 32.0;

	static int expBias;
	static int exp;

	static int expMask;
	static int fractMask;
	static int leftBitMask = 1 << (sizeof(int) * 8 - 1);

	static int signBit;
	static int fractBits;
	static int expBits;

	static int fractField;
	
	
	expBias = 127;

	expMask = createMask(NumOfExpBits);
	fractMask = createMask(NumOfFractBits);
	
	signBit = (i >> (NumOfExpBits + NumOfFractBits)) & 0x01;
	expBits = (i >> NumOfFractBits) & expMask;
	fractField = i & fractMask;
	fractBits = fractField << (sizeof(int) * 8 - NumOfFractBits);

	printf("signBit %d, expBits %d, fractBits 0x%08X\n", signBit, expBits, fractField);
	
	//decide whether +0, -0, normalized, denormalized
	if(expBits == 0.0){
		if (fractBits == 0){
				if(signBit){
					printf("-zero\n");
				}else{
					printf("+zero\n");
				}
		}else{
			exp = 1 - expBias;
			printf("denormalized:	exp = %d\n", exp);
		}
	}
	//decide whether +inf or -inf 
	else if(expBits == expMask){
		if(fractBits == 0){
			if(signBit){
				exp = expBits;
				printf("-infinity:	exp = %d\n", exp); 
			}else{
				exp = expBits;
				printf("+infinity:	exp = %d\n", exp);
			}
		}
	//decide whether qnan or snan	
			 else if(fractBits & leftBitMask){
				exp = expBits;
				printf("QNaN:	exp = %d\n", exp);
			}
			else{
				exp = expBits;
				printf("SNaN:	exp = %d\n", exp);
			}
		}
	
	else{
		exp = expBits - expBias;
		printf("normalized:	exp = %d\n", exp);
	}
	
	
}
// do not change this function in any way
int main(int argc, char **argv)
{
	unsigned int	i;					// number currently being analyzed
	bool			validInput;			// was user input valid?

	printf("CS201 - A01p - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextHexInt(&i);
		printf("0x%08X\n", i);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(i);
		if (i == 0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
	return 0;
}
