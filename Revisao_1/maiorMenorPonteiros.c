#include <stdio.h>


void maiorMenor(int v[5], int* maior, int* menor) {

	for(int i=0;i<5;i++) {
		if(*maior>v[i]) {
			*maior = v[i];
		}
		if(*menor<v[i]) {
			*menor = v[i];
		}
	}
}



int main() {

	int vetor[5];

	for(int i=0;i<5;i++) {
		printf("Digite um valor: ");
		scanf("%d", &vetor[i]);
	}

	int maior = vetor[0];
	int menor = vetor[0];

	maiorMenor(vetor, &maior, &menor);

	printf("%d\n", maior);
	printf("%d", menor);

	return 0;
}
