#include <stdlib.h>
#include <stdio.h>
#include "listaMoveMenor.h"


Lista* criar_lista() {

	Lista* novaLista = (Lista*) malloc(sizeof(Lista));

	if(novaLista == NULL) {
		printf("Erro na alocação!");
		return NULL;
	}
	novaLista->pInicio = NULL;
	return novaLista;
}

int eh_vazia(Lista *lista) {
	if(lista->pInicio == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int insere_elemento_inicio(Lista *lista, int novoValor) {
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
		novoNo->ant = NULL;
		novoNo->prox = NULL;
		lista->tam++;
	}
	else {
		novoNo->prox = lista->pInicio;
		lista->pInicio->ant = novoNo;
		novoNo->ant = NULL;
		lista->pInicio = novoNo;
		lista->tam++;
	}
	return 1;
}

void imprimir_lista(Lista *lista) {
	if(eh_vazia(lista)) {
		printf("A lista está vazia!\n");
		return;
	}
	No *noAux;
	noAux = lista->pInicio;

	while(noAux != NULL) {
		printf("%d ", noAux->valor);
		noAux = noAux->prox;
	}
	printf("\n\n");
}

int menor_elemento(Lista *lista) {
	if(lista == NULL) {
		return 0;
	}
	No *noAux = lista->pInicio;
	int menor_valor = lista->pInicio->valor;
	for(int i=0;i<lista->tam;i++) {
		if(noAux->valor < menor_valor) {
			menor_valor = noAux->valor;
		}
		noAux = noAux->prox;
	}
	return menor_valor;
}

int move_elemento_inicio(Lista *lista, int menorValor) {
	if(lista == NULL) {
		return 0;
	}
	No *noAux = lista->pInicio;
	while(noAux->valor != menorValor) {
		noAux = noAux->prox;
	}
	noAux->prox = lista->pInicio;
	noAux->ant->prox = NULL;
	noAux->ant = NULL;
	lista->pInicio = noAux;
	return 1;
}
