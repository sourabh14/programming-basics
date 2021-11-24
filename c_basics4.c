/* Structure, Enum, Bitwise
*/
#include <stdio.h>
#include <string.h>

struct book {
	char name[20];
	int pages;
};

enum colour {
	red, blue, green, yellow
};

void showbits(int num) {
	int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	for (int i=7; num != 0; i--) {
		binary[i] = num%2;
		num = num/2;
	}
	for (int i=0; i<8; i++) {
		printf("%d", binary[i]);
	}
	printf("\n");
}

void main() {
	/* STRUCTURE - collection of dissimilar data types */
	struct book b1, b2;
	strcpy(b1.name, "Harry Potter");
	b1.pages = 400;
	strcpy(b2.name, "Unbreakable");
	b2.pages = 500;

	printf("Book 1 : %s %d\n", b1.name, b1.pages);
	printf("Book 2 : %s %d\n", b2.name, b2.pages);

	struct book b3 = {"Let us C", 748};
	printf("Book 3 : %s %d\n", b3.name, b3.pages);

	/* Structure pointers */
	struct book *p;
	p = &b1;
	printf("Book 1 : %s %d\n\n", p->name, p->pages);

	/* Enum - define your own data type and what value 
		the variable of this data type can hold
		- makes program more readable
	*/
	enum colour c1, c2;
	c1 = red;
	c2 = blue;

	/* BITWISE */
	int i = 64, j, k;
	printf("Binary of %d: ", i);
	showbits(i); /* displays binary representation */
	/* complement */
	j = ~i;
	printf("Complement of %d: ", i);
	showbits(j);
	/* right shift - divide by 2*/
	j = i>>1;
	printf("Right shift of %d: ", i);
	showbits(j);
	printf("  value: %d\n", j);
	/* left shift - multiply by 2*/
	j = i<<1;
	printf("Left shift of %d: ", i);
	showbits(j);
	printf("  value: %d\n", j);
	/* bitwise AND, OR, XOR */
	printf("i : ");
	showbits(i);
	printf("j : ");
	showbits(j);
	k = i & j;
	printf("i AND j : ");
	showbits(k);
	k = i | j;
	printf("i OR j : ");
	showbits(k);
	k = i ^ j;
	printf("i AND j : ");
	showbits(k);
}