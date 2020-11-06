#include <stdio.h>
#include "listaDuplamente.h"

int main() {

	ListaDupla *listaDupla;

	listaDupla = criar_lista_dupla();

	if(eh_vazia(listaDupla)) {
		printf("A lista está vazia!\n\n");
	}
	else {
		printf("A lista não está vazia!\n\n");
	}
	int tamanho = tamanho_lista(listaDupla);
	printf("Tamanho da lista: %d", tamanho);

	printf("Inserindo o valor 1 no início da lista...\n");
	insere_elemento_inicio(listaDupla, 1);
	imprimir_lista(listaDupla);
	printf("Inserindo o valor 0 no início da lista...\n");
	insere_elemento_inicio(listaDupla, 0);
	imprimir_lista(listaDupla);
	printf("Inserindo o valor 2 no fim da lista...\n");
	insere_elemento_final(listaDupla, 2);
	imprimir_lista(listaDupla);
	printf("Inserindo o valor 3 no fim da lista...\n");
	insere_elemento_final(listaDupla, 3);
	imprimir_lista(listaDupla);
	printf("Removendo o primeiro elemento da lista...\n");
	remove_elemento_inicio(listaDupla);
	imprimir_lista(listaDupla);
	printf("Calculando a média aritmética dos elementos...\n");
	printf("A média aritmética dos elementos é: %.1f\n", media_aritmetica(listaDupla));

	ListaDupla *listaDupla1 = criar_lista_dupla();
	ListaDupla *listaDupla2 = criar_lista_dupla();
	printf("Inserindo o valor 1 no início da lista1...\n");
	insere_elemento_inicio(listaDupla1, 1);
	printf("Inserindo o valor 2 no início da lista1...\n");
	insere_elemento_inicio(listaDupla1, 2);
	printf("Inserindo o valor 3 no início da lista1...\n");
	insere_elemento_inicio(listaDupla1, 3);
	printf("Inserindo o valor 1 no início da lista2...\n");
	insere_elemento_inicio(listaDupla2, 1);
	printf("Inserindo o valor 2 no início da lista2...\n");
	insere_elemento_inicio(listaDupla2, 2);
	printf("Inserindo o valor 3 no início da lista2...\n");
	insere_elemento_inicio(listaDupla2, 3);

	imprimir_lista(listaDupla1);
	imprimir_lista(listaDupla2);

	if(listas_iguais(listaDupla1, listaDupla2)) {
		printf("As listas são iguais!\n");
	}
	else {
		printf("As listas são diferentes!\n");
	}

	printf("Removendo o valor 3 do início da lista2...\n");
	remove_elemento_inicio(listaDupla2);

	if(listas_iguais(listaDupla1, listaDupla2)) {
		printf("As listas são iguais!\n");
	}
	else {
		printf("As listas são diferentes!\n");
	}

	printf("Criando uma lista com os múltiplos de 3 da lista 1...\n");
	ListaDupla *listaDupla3 = lista_multiplos3(listaDupla1);
	imprimir_lista(listaDupla3);
}
