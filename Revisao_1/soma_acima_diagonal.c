#include <stdio.h>

int main() {

	int matriz[3][3];

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			matriz[i][j] = j;
		}
	}

	int soma = 0;

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(j>i) {
				soma += matriz[i][j];
			}
		}
	}

	printf("Soma: %d", soma);
}
