/*
	Functions, Pointers, Custom Library
	Arrays, Strings
*/

#include <stdio.h>
#include "mylib.h"
#include <string.h>


int calsum(int i, int j, int k) {
	return i+j+k;
}

void swap(int *p, int *q) {
	int n;
	n = *p;
	*p = *q;
	*q = n;
}

void calcAreaPerim(float r, float *a, float *p) {
	*a = 3.14 * r * r;
	*p = 2 * 3.14 * r;
}

int fact(int f) {
	if (f == 1) 
		return 1;
	else
		return f * fact(f-1);
}

void displayArr(int *a, int s) {
	printf("Array elements: ");
	for (int i=0; i<s; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
}

void main() {
	/* functions */
	int a,b,c, sum;
	printf("Enter three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	/* call by value - value of variables are sent as argument */
	sum = calsum(a,b,c);
	printf("sum = %d\n", sum);

	/* pointers - are variable that contain address of another variable */
	int *addr;
	addr = &a;
	printf("value of a = %d\n", a);
	printf("address of a = %p\n", &a);
	printf("address of a = %p\n", addr);
	printf("value of a = %d\n", *addr);

	int **pp;
	pp = &addr;
	printf("value of addr: %p\n", addr);
	printf("address of addr: %p\n", &addr);

	/* call by reference - address are sent as variable */
	swap(&a, &b);
	printf("value of a = %d b = %d \n", a, b);
	/* it can be used to return multiple value */
	float radius, area, perimeter;
	radius = 4.5;
	calcAreaPerim(radius, &area, &perimeter);
	printf("area: %f perimeter: %f\n", area, perimeter);

	/* recursion */
	int f, fac;
	printf("Enter any number : ");
	scanf("%d", &f);
	fac = fact(f);
	printf("factorial of %d is %d\n", f, fac);

	/* use custom library */
	int m = multiply(a, b);
	printf("a*b = %d\n", m);

	/* Array - group of similar quantities */
	int arr1[6];
	arr1[0] = 1;
	arr1[1] = 3;
	arr1[2] = 5;
	displayArr(arr1, 3); /* arr1 is a pointer */

	/* initialization */
	int arr2[] = {2, 4, 6, 8};
	displayArr(arr2, 4);

	/* 2D array */
	int arr3[4][4] = {
			{1, 2, 3, 4},
			{1, 2, 3, 4},
			{1, 2, 3, 4},
			{1, 2, 3, 4}
		};
	for (int i=0; i<4; i++) {
		displayArr(arr3[i], 4);
	}

	/* Strings- array of characters terminated by '\0' 
		ASCII value fo \0 is 0 */
	char name1[] = {'a', 'b', 'c', '\0'};
	char name2[] = "Program";
	printf("Name 1: %s\n", name1);
	printf("Name 2: %s\n", name2);

	/* scanning string */
	char name3[25], name4[25], name5[50];
	printf("Enter your name: ");
	gets(name3);
	printf("You entered: %s\n", name3);

	/* Standard functions */
	/* length */
	int len1 = strlen(name3);
	printf("Length of string : %d\n", len1);
	/* copy */
	strcpy(name4, name3);
	printf("Copied string : %s\n", name4);
	/* concatenate */
	strcat(name3, name4);
	printf("Concatenated string : %s\n", name3);
	/* comapre */
	if (strcmp(name3, name4) == 0) {
		printf("Name 3 and name 4 are identical\n");
	} else {
		printf("Name 3 and name 4 are not identical\n");
	}

}