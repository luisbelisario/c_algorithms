#include <stdio.h>
#include "jogador.h"


int main() {

	int n;
	novoJogador jogadores[100];

	printf("Quantos jogadores deseja cadastrar? ");
	scanf("%d", &n);
	getchar();

	for(int i=0;i<n;i++) {
		novoJogador jogador;

		printf("\nDigite o nome do %dº jogador: ", i+1);
		fgets(jogador.nome, 20, stdin);
		printf("Digite a quantidade de jogos desse jogador: ");
		scanf("%d", &jogador.jogos);
		printf("Digite a quantidade de gols desse jogador: ");
		scanf("%d", &jogador.gols);
		printf("Digite a quantidade de assistências desse jogador: ");
		scanf("%d", &jogador.assist);
		getchar();

		jogadores[i] = jogador;
	}

	for(int j=0;j<n;j++) {
		imprimirEstat(&jogadores[j]);
		ehBom(&jogadores[j]);
	}
}
