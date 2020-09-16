#include <stdio.h>

int main() {

	int matriz[4][4];
	int num;

	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			printf("Digite o valor da posição [%d][%d]: ", i, j);
			scanf("%d", &num);
			matriz[i][j] = num;
		}
	}

	int soma = 0;

	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			if(matriz[i][j]>10) {
				soma += 1;
			}
		}
	}

	if(soma==0) {
		printf("Nenhum dos valores é maior que 10!");
	}
	else {
		printf("Número de valores maiores que 10: %d", soma);
	}
}
