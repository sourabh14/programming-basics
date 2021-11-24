/*
	Data types, Scope of variable, Storage classes, 
	Preprocessors, Build Process

*/

#include <stdio.h>

int gl1; /*external variable*/
static int gl2; /* gl2 is not available to other files, it becomes private*/\

#define PI 3.14
/* Macros with argument */
#define SQUARE(x) (x*x) 

void increment() {
	static int st =1; /* it is never initialized again */
	printf("value of st: %d\n", st);
	st++;
}

void temp() {
	printf("value of gl1 : %d\n", gl1);
}


void main() {
	/* DATA TYPES
		- n bit data type - range is -2^(n-1) to 2^(n-1)-1

		- int for 16 bit compiler is 2 bytes - 16 bit
			range - -32768 to 32767
		- int for 32 bit compiler is 4 bytes

		-float occupies 4 bytes
		-double occupies 8 bytes ; long double occupies 10 bytes

		-unsigned int - value is always positive
		eg: unsigned int num_students;

		-char ch = 'A' means ASCII value of 'A' (i.e. 65) gets stored in ch
		-char is 1 byte or 8 bit - range of signed char variable is -128 to 127
	*/
	char ch = 'A';
	printf("ch: %c %d\n", ch, ch);


	/*SCOPE OF VARIABLE*/
	int e = 1;
	printf("e = %d\n", e);
	{
		int e = 2;
		printf("e = %d\n", e);
		{
			int e = 3;
			printf("e = %d\n", e);
		}
		printf("e = %d\n", e);
	}
	printf("e = %d\n", e);


	/* STORAGE CLASSES
		Auto:- storage : memory, default value: garbage
		Register: storage: cpu registers, default value: garbage, accessed faster
		Static: storage: memory, default value: zero, their value persist, 
			they dont disappear when the function is no longer active
			they are not stored in stack, they are stored in data segment and die only when program comes to end
		External: storage: memory, scope is global
			they are also available to functions defined in other files
			however if we place static before it, it makes the var private and not accessible to other file
	*/
	register int y; /* register variable */

	increment();
	increment();
	increment();

	gl1 = 4;
	temp();

	/* PREPROCESSOR
		-program that processes source code before it is passed to compiler
		-prog.c -> preprocessor -> (expanded source code) -> compiler
		-Directives are preprocessor commands, they begin with #

		Macro expansion: #define
			variables should not be used for storing constants, macros should be used
			it is efficient and makes program easier to understand
	*/
	int rad = 3, sq;
	float area = PI * rad * rad;
	sq = SQUARE (rad);
	printf("rad: %d area: %f square of radius: %d\n", rad, area, sq);

	/* BUILD PROCESS
		Preprocessing -> Compiling -> Assembling -> Linking = executable code -> Loading
		see pg 266 of Let Us C
	*/

}
