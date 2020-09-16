#include <stdio.h>


void duplicaVetor(int *vetor);

int main() {

	int array[10];

	for(int i=0;i<10;i++) {
		printf("Digite o valor do %dº elemento: ", i+1);
		scanf("%d", &array[i]);
	}

	duplicaVetor(array);
	printf("\nElementos após a duplicação: \n");
	for(int i=0;i<10;i++) {
		printf("%d\n", array[i]);
	}
}

void duplicaVetor(int *vetor) {

	for(int i=0;i<10;i++) {
		vetor[i] *= 2;
	}
}
