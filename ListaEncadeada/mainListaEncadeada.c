#include <stdio.h>
#include "listaEncadeada.h"

int main() {
	Lista *minhaLista;
	// Aqui estou criando um ponteiro que contem o endereço de uma estrutura TLista
	// vide listaEncadeada.h

	Aluno aluno0;
	aluno0.matricula = 100;

	Aluno aluno1;
	aluno1.matricula = 101;

	Aluno aluno2;
	aluno2.matricula = 102;

	Aluno aluno3;
	aluno3.matricula = 103;

	Aluno aluno4;
	aluno4.matricula = 104;

	Aluno aluno5;
	aluno5.matricula = 105;

	Aluno aluno6;
	aluno6.matricula = 106;

	minhaLista = criar_lista();
	printf("Lista inicializada!\n\n");

	int tam_lista = tamanho_lista(minhaLista);

	printf("Tamanho da lista: %d\n\n", tam_lista);

	if(lista_eh_vazia(minhaLista)) {
		printf("A lista está vazia!\n\n");
	}
	else {
		printf("A lista não está vazia!\n\n");
	}

	printf("Inserindo elemento no início da lista...\n\n");
	insere_elemento_inicio(minhaLista, aluno1);
	imprimir_lista(minhaLista);
	printf("Inserindo outro elemento no início da lista...\n\n");
	insere_elemento_inicio(minhaLista, aluno0);
	imprimir_lista(minhaLista);
	printf("Inserindo elementos no final da lista...\n\n");
	insere_elemento_final(minhaLista, aluno2);
	insere_elemento_final(minhaLista, aluno3);
	insere_elemento_final(minhaLista, aluno4);
	insere_elemento_final(minhaLista, aluno5);
	insere_elemento_final(minhaLista, aluno6);
	imprimir_lista(minhaLista);
	printf("Testando se a lista está vazia...\n\n");
	if(lista_eh_vazia(minhaLista)) {
		printf("A lista está vazia!\n\n");
	}
	else {
		printf("A lista não está vazia!\n\n");
	}
	tam_lista = tamanho_lista(minhaLista);
	printf("Tamanho da lista: %d\n\n", tam_lista);
	printf("Removendo elemento do início da lista...\n\n");
	remove_elemento_inicio(minhaLista);
	imprimir_lista(minhaLista);
	printf("Removendo elemento do final da lista...\n\n");
	remove_elemento_final(minhaLista);
	imprimir_lista(minhaLista);
	printf("Inserindo elemento da posição 1 da lista...\n\n");
	insere_elemento_posicao(minhaLista, aluno1, 1);
	imprimir_lista(minhaLista);
	printf("Removendo elemento da posição 1 da lista...\n\n");
	remove_elemento_posicao(minhaLista, 1);
	imprimir_lista(minhaLista);

	printf("Criando lista de ímpares...\n\n");
	Lista *listaImpares = criar_lista_impares(minhaLista);
	imprimir_lista(listaImpares);
	printf("Criando lista inversa...\n\n");
	Lista *listaInversa = criar_lista_inversa(minhaLista);
	imprimir_lista(listaInversa);


	return 0;
}
