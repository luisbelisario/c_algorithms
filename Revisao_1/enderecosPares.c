#include <stdio.h>


int main() {

	int array[5];

	for(int i=0;i<5;i++) {
		printf("Digite o valor do %dº elemento: ", i+1);
		scanf("%d", &array[i]);
	}

	printf("\nEndereço dos valores pares: \n");
	for(int i=0;i<5;i++) {
		if(array[i]%2==0) {
			printf("%p\n", &array[i]);
		}
	}
}
