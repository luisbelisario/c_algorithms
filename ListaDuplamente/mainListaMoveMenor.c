#include <stdio.h>
#include "listaMoveMenor.h"

int main() {

	Lista *lista = criar_lista();

	if(eh_vazia(lista)) {
		printf("A lista está vazia!\n\n");
	}
	else {
		printf("A lista não está vazia!\n\n");
	}

	printf("Inserindo o valor -1 no início da lista...\n");
	insere_elemento_inicio(lista, -1);
	printf("Inserindo o valor 0 no início da lista...\n");
	insere_elemento_inicio(lista, 0);
	printf("Inserindo o valor 1 no início da lista...\n");
	insere_elemento_inicio(lista, 1);
	imprimir_lista(lista);
	int menor = menor_elemento(lista);
	printf("Menor elemento da lista: %d\n\n", menor);
	printf("Movendo o menor elemento para início da lista...\n");
	move_elemento_inicio(lista, menor);
	imprimir_lista(lista);
}
