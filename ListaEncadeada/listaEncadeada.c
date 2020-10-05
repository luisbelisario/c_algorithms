#include <stdlib.h>
#include <stdio.h>
#include "listaEncadeada.h"


Lista* criar_lista() {

	// essa função tem * no cabeçalho porque retorna ponteiro

	Lista* novaLista = (Lista*) malloc(sizeof(Lista));
	// o malloc() aloca dinamicamente um espaço de memoria
	// tenho que passar como argumento o tamanho do espaço em memoria que desejo
	// nesse caso passo o tamanho necessario para armazenar o tipo Lista
	// também tenho qu dizer qual o tipo desse espaço, no caso Lista
	// estou armazenando esse espaço de memoria na variavel(ponteiro) *novaLista

	if(novaLista == NULL) {
		printf("Erro na alocação!");
		return NULL;
	}
	novaLista->pInicio = NULL;
	novaLista->pFim = NULL;
	novaLista->tam = 0;
	return novaLista;
	// aqui estou setando os ponteiros inicio e fim para NULL
	// se o malloc() não retornar NULL
}

int lista_eh_vazia(Lista *lista) {
	if(lista->pInicio == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int insere_elemento_inicio(Lista *lista, Aluno novoAluno) {
	if(lista == NULL) {
		return 0;
	}
	No *novoNo = (No*) malloc(sizeof(No));

	if(novoNo == NULL) {
		return 0;
	}

	novoNo->aluno = novoAluno;

	if(lista_eh_vazia(lista)) {
		lista->pInicio = novoNo;
		lista->pFim = novoNo;
		lista->tam++;
		novoNo->prox = NULL;
	}
	else {
		novoNo->prox = lista->pInicio;
		lista->pInicio = novoNo;
		lista->tam++;
	}
	return 1;
}

int insere_elemento_final(Lista *lista, Aluno novoAluno) {
	if(lista == NULL) {
		return 0;
	}
	No *novoNo = (No*) malloc(sizeof(No));

	if(novoNo == NULL) {
		return 0;
	}
	novoNo->aluno = novoAluno;

	if(lista_eh_vazia(lista)) {
		insere_elemento_inicio(lista, novoAluno);
		lista->tam++;
	}
	else {
		lista->pFim->prox = novoNo;
		novoNo->prox = NULL;
		lista->pFim = novoNo;
		lista->tam++;
	}
	return 1;
}

int remove_elemento_inicio(Lista *lista) {
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

int remove_elemento_final(Lista *lista) {
	if(lista == NULL) {
		return 0;
	}
	No *noRemove = (No*) malloc(sizeof(No));
	No *noAnt = (No*) malloc(sizeof(No));
	noRemove = lista->pInicio;

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

int insere_elemento_posicao(Lista *lista, Aluno novoAluno, int posicao) {
	if(lista == NULL) {
		return 0;
	}
	No *noAdiciona = (No*) malloc(sizeof(No));
	No *noAnt = (No*) malloc(sizeof(No));
	No *noProx = (No*) malloc(sizeof(No));
	noAdiciona->aluno = novoAluno;
	noProx = lista->pInicio;
	noAnt = lista->pInicio;
	int cont = 0;
	if(posicao == 0) {
		insere_elemento_inicio(lista, novoAluno);
	}
	else {
		while(cont < posicao) {
			noAnt = noProx;
			noProx = noProx->prox;
			cont++;
		}
		noAnt->prox = noAdiciona;
		noAdiciona->prox = noProx;
	}
	lista->tam++;
	return 1;
}

int remove_elemento_posicao(Lista *lista, int posicao) {
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


Lista* criar_lista_inversa(Lista *lista) {
	if(lista == NULL) {
		return 0;
	}
	Lista *lista_inversa = criar_lista();
	No *noAux = (No*) malloc(sizeof(No));
	noAux = lista->pInicio;
	for(int i=0;i<lista->tam;i++) {
		insere_elemento_inicio(lista_inversa, noAux->aluno);
		noAux = noAux->prox;
	}
	return lista_inversa;
}

Lista* criar_lista_impares(Lista *lista) {
	if(lista == NULL) {
		return 0;
	}
	Lista *lista_impares = criar_lista();
	No *noAux = (No*) malloc(sizeof(No));
	noAux = lista->pInicio;
	for(int i=0; i<lista->tam; i++) {
		if(noAux->aluno.matricula % 2 != 0) {
			insere_elemento_final(lista_impares, noAux->aluno);
		}
		noAux = noAux->prox;
	}
	return lista_impares;
}

int tamanho_lista(Lista *lista) {
	return lista->tam;
}

void imprimir_lista(Lista *lista) {
	if(lista_eh_vazia(lista)) {
		printf("A lista está vazia\n");
		return;
	}
	No *tmp;
	tmp = lista->pInicio;

	while(tmp != NULL) {
		printf("%d ", tmp->aluno.matricula);
		tmp = tmp->prox;
	}
	printf("\n\n");
}
