#include <stdlib.h>
#include <stdio.h>
#include "listaCircular.h"


ListaCircular* criar_lista() {


	ListaCircular* novaLista = (ListaCircular*) malloc(sizeof(ListaCircular));

	if(novaLista == NULL) {
		printf("Erro na alocação!");
		return NULL;
	}
	novaLista->pInicio = NULL;
	novaLista->tam = 0;
	return novaLista;
	// aqui estou setando os ponteiros inicio e fim para NULL
	// se o malloc() não retornar NULL
}

int eh_vazia(ListaCircular *lista) {
	if(lista->pInicio == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int tamanho_lista(ListaCircular *lista) {
	return lista->tam;
}

int insere_elemento_inicio(ListaCircular *lista, int novoValor) {
	if(lista == NULL) {
		return 0;
	}
	No *novoNo = (No*) malloc(sizeof(No));

	if(novoNo == NULL) {
		return 0;
	}

	novoNo->valor = novoValor;

	if(eh_vazia(lista)) {
		lista->pInicio = novoNo;
		lista->tam++;
		novoNo->prox = novoNo;
	}
	else {
		novoNo->prox = lista->pInicio;
		lista->pInicio = novoNo;
		lista->tam++;
	}
	return 1;
}

int remove_elemento_inicio(ListaCircular *lista) {
	if(lista == NULL) {
		return 0;
	}
	No *noRemove = (No*) malloc(sizeof(No));
	noRemove = lista->pInicio;
	lista->pInicio = noRemove->prox;
	free(noRemove);
	lista->tam--;
	return 1;
}

void imprimir_lista(ListaCircular *lista) {
	if(eh_vazia(lista)) {
		printf("A lista está vazia\n");
		return;
	}
	No *tmp;
	tmp = lista->pInicio;

	for(int i=0;i<lista->tam;i++) {
		printf("%d ", tmp->valor);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

int troca_valores(ListaCircular *lista, int posicao) {
	if(eh_vazia(lista)) {
		printf("A lista está vazia\n");
		return 0;
	}
	No *noAtual = lista->pInicio;
	No *noProx = lista->pInicio->prox;
	No *noAux;
	for(int i=0;i<posicao;i++) {
		noAtual = noAtual->prox;
		noProx = noProx->prox;
	}
	noAux = noAtual;
	noAtual = noProx;
	noProx = noAux;
	return 1;
}
