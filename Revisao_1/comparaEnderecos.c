#include <stdio.h>

int main() {


	int a = 10;
	int b = 11;

	printf("Endereço de memória de a: %p\n", &a);
	printf("Endereço de memória de b: %p\n", &b);

	if(&a>&b) {
		printf("O endereço de a é maior que o de b!");
	}
	else {
		printf("O endereço de b é maior que o de a!");
	}

	return 0;
}
