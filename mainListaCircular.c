#include <stdio.h>
#include "listaCircular.h"

int main() {

	ListaCircular *listaCircular;

	listaCircular = criar_lista();

	if(eh_vazia(listaCircular)) {
		printf("A lista está vazia!\n\n");
	}
	else {
		printf("A lista não está vazia!\n\n");
	}
	int tamanho = tamanho_lista(listaCircular);
	printf("Tamanho da lista: %d", tamanho);

	printf("Inserindo o valor 2 no início da lista...\n");
	insere_elemento_inicio(listaCircular, 2);
	imprimir_lista(listaCircular);
	printf("Inserindo o valor 1 no início da lista...\n");
	insere_elemento_inicio(listaCircular, 1);
	imprimir_lista(listaCircular);
	printf("Inserindo o valor 0 no início da lista...\n");
	insere_elemento_inicio(listaCircular, 0);
	imprimir_lista(listaCircular);

	troca_valores(listaCircular, 1);
	imprimir_lista(listaCircular);
}
