#include <stdio.h>



void incrementarValores(int* a, float* b, char* c) {

	(*a)++;
	(*b)++;
	(*c)++;
}



int main() {

	int a = 1;
	float b = 3.5;
	char c = 'a';

	printf("Inteiro antes do incremento: %d\n", a);
	printf("Float antes do incremento: %f\n", b);
	printf("Char antes do incremento: %c\n", c);

	incrementarValores(&a, &b, &c);

	printf("\nInteiro após o incremento: %d\n", a);
	printf("Float após o incremento: %f\n", b);
	printf("Char após o incremento: %c\n", c);


	return 0;
}
