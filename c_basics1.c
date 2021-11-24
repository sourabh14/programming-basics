#include <stdio.h>
#include <math.h>

void main() {
	int p = 9;
	int r = 5;
	int t = 10;
	int greatest;
	float si;
	char chh;
	
	/* printing */
	si = (p*r*t)/100.0;
	chh = 'a';

	printf("Character chh = %c\n", chh);
	printf("p = %d , r = %d , t = %d\n", p, r, t);
	printf("Simple interest = %f\n", si);

	/* scanning */
	printf("Enter values of p,n,r\n");
	scanf("%d %d %d", &p, &r, &t);
	si = (p*r*t)/100.0;
	printf("p = %d , r = %d , t = %d\n", p, r, t);
	printf("Simple interest = %f\n", si);

	/* math */
	si = pow(4,5);
	printf("\n");
	printf("4 to power 5 = %f\n", si);

	/* condition - if else */
	printf("\n");
	if (p == r) {
		printf("p equals r\n");
	} else {
		printf("p not equals r\n");
	}

	/* multiple if - both conditions are checked */
	if (p < r) {
		printf("p less than r\n");
	} 
	if (r > t) {
		printf("r is greater than t\n");
	}

	/* if and else if */
	if (p < r) {
		printf("p less than r\n");
	} else if (p >= r) {
		printf("p greater than or equals r\n");
	}

	/* logical operators - AND OR NOT */
	if ((p < r) && (t > r)) {
		printf("p is less than r and t is greater than r\n");
	} else {
		printf("p not equals r\n");
	}

	if (p != r) {
		printf("p not equals r\n");
	}

	/* ternary operators ? and : */
	greatest = ( p>r ? p:r);
	greatest = (greatest>t ? greatest:t);
	printf("Greatest of p,r,t is - %d\n", greatest);
	printf("\n");

	/* switch */
	int s = 2;

	switch(s) {
		case 1: printf("s=1"); 
			break;
		case 2: printf("s=2");
			break;
		case 3: printf("s=3");
			break;
		case 4: printf("s=4");
			break;
	}
	printf("\n");

	/* goto */
	s = 2;
	if (s == 2) {
		goto abc;
	}
	printf("jibber jabber");

	abc : printf("s equals 2\n");

	/* for loop */
	int i, j;

	printf("\n");
	for (i=1; i<=5; i++) {
		for (j=1; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	
	/* while loop */
	i=1;
	while (i<5){
		printf("%d four times print\n", i);
		i++;
	}
	printf("\n");
	i=1;
	do {
		printf("%d four times print\n", i);
		i++;
	} while (i<5);

	/* break and continue */
	i=1;
	printf("\n");
	while (i<5){
		printf("%d two times print\n", i);
		i++;
		if (i == 3)
			break;
	}

	i=1;
	printf("\n");
	while (i<5){
		printf("%d four times print\n", i);
		i++;
		if (i == 3)
			continue;
		if (i == 3)
			break;
	}
}