#include <stdio.h>
#include <string.h>
#include "jogador.h"

void criarJogador(novoJogador *jogador, char nome[20], int jogos, int gols, int assist) {
	strcpy(jogador->nome, nome);
	jogador->jogos = jogos;
	jogador->gols = gols;
	jogador->assist = assist;
}

void imprimirEstat(novoJogador *jogador) {
	printf("\nNome: %s", jogador->nome);
	printf("Jogos: %d\n", jogador->jogos);
	printf("Gols: %d\n", jogador->gols);
	printf("Assistências: %d\n", jogador->assist);
}

void ehBom(novoJogador *jogador) {
	if(jogador->gols >= 3 || jogador->assist >= 3) {
		printf("É bom!\n");
	}
	else {
		printf("Não é bom!\n");
	}
}
