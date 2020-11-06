#include <stdlib.h>
#include <stdio.h>
#include "listaDuplamente.h"


ListaDupla* criar_lista_dupla() {

	ListaDupla* novaLista = (ListaDupla*) malloc(sizeof(ListaDupla));

	if(novaLista == NULL) {
		printf("Erro na alocação!");
		return NULL;
	}
	novaLista->pInicio = NULL;
	novaLista->pFim = NULL;
	novaLista->tam = 0;
	return novaLista;
}

int tamanho_lista(ListaDupla* lista) {
	return lista->tam;
}

int eh_vazia(ListaDupla* lista) {
	if(lista->pInicio == NULL) {
		return 1;
	}
	return 0;
}

void imprimir_lista(ListaDupla *lista) {
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

int insere_elemento_inicio(ListaDupla *lista, int valor) {
	if(lista == NULL) {
		return 0;
	}

	No *novoNo = (No*) malloc(sizeof(No));
	if(novoNo == NULL) {
		return 0;
	}

	novoNo->valor = valor;

	if(eh_vazia(lista)) {
		lista->pInicio = novoNo;
		lista->pFim = novoNo;
		lista->tam++;
		novoNo->ant = NULL;
		novoNo->prox = NULL;
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

int insere_elemento_final(ListaDupla *lista, int valor) {
	if(lista == NULL) {
		return 0;
	}

	No *novoNo = (No*) malloc(sizeof(No));
	if(novoNo == NULL) {
		return 0;
	}

	novoNo->valor = valor;
	if(eh_vazia(lista)) {
		insere_elemento_inicio(lista, valor);
		lista->tam++;
	}
	else {
		lista->pFim->prox = novoNo;
		novoNo->ant = lista->pFim;
		novoNo->prox = NULL;
		lista->pFim = novoNo;
		lista->tam++;
	}
	return 1;
}

int remove_elemento_inicio(ListaDupla *lista) {
	if(lista == NULL) {
		return 0;
	}
	if(eh_vazia(lista)) {
		printf("A lista está vazia!");
		return 0;
	}
	else {
		No *noRemove;
		noRemove = lista->pInicio;
		lista->pInicio = noRemove->prox;
		free(noRemove);
		lista->tam--;
		return 1;
	}
}

int remove_elemento_final(ListaDupla *lista) {
	if(lista == NULL) {
		return 0;
	}
	if(eh_vazia(lista)) {
		printf("A lista está vazia!");
		return 0;
	}
	else {
		No *noRemove = lista->pInicio;
		No *noAnt = lista->pInicio;

		while(noRemove->prox != NULL) {
			noAnt = noRemove;
			noRemove = noRemove->prox;
		}

		noAnt->prox = noRemove->prox;
		lista->pFim = noAnt;
		lista->tam--;
		free(noRemove);
		return 1;
	}
}

int remove_elemento_posicao(ListaDupla *lista, int posicao) {
	if(lista == NULL) {
		return 0;
	}
	No *noRemove = (No*) malloc(sizeof(No));
	No *noAnt = (No*) malloc(sizeof(No));
	int cont = 0;
	noRemove = lista->pInicio;

	while(cont < posicao) {
		noAnt = noRemove;
		noRemove = noRemove->prox;
		cont++;
	}
	noAnt->prox = noRemove->prox;
	lista->tam--;
	free(noRemove);
	return 1;
}


float media_aritmetica(ListaDupla *lista) {
	if(lista == NULL) {
		return 0;
	}
	if(eh_vazia(lista)) {
		printf("A lista está vazia!");
		return 0;
	}
	else {
		int soma = 0;
		No *noAux = lista->pInicio;
		for(int i=0;i<lista->tam;i++) {
			soma += noAux->valor;
			noAux = noAux->prox;
		}
		int media = soma/lista->tam;
		return media;
	}
}

int listas_iguais(ListaDupla *lista1, ListaDupla *lista2) {
	if(lista1 == NULL || lista2 == NULL) {
		return 0;
	}
	if(lista1->tam != lista2->tam) {
		printf("Os tamanhos das listas são diferentes!\n");
		return 0;
	}
	else{
		int controle = 1;

		No *noAux1 = lista1->pInicio;
		No *noAux2 = lista2->pInicio;

		while(noAux1->prox != NULL) {
			if(noAux1->valor == noAux2->valor) {
				noAux1 = noAux1->prox;
				noAux2 = noAux2->prox;
			}
			else {
				controle = 0;
				break;
			}
		}
		return controle;
	}
}

ListaDupla* lista_multiplos3(ListaDupla *lista) {
	if(lista == NULL) {
		return 0;
	}
	if(eh_vazia(lista)) {
		printf("A lista está vazia!");
		return 0;
	}
	else {
		ListaDupla* lista3 = criar_lista_dupla();
		No *noAux = lista->pInicio;
		for(int i=0;i<lista->tam;i++) {
			if(noAux->valor % 3 == 0) {
				insere_elemento_inicio(lista3, noAux->valor);
			}
			noAux = noAux->prox;
		}
		return lista3;
	}
}
