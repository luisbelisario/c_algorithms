typedef struct {
	char nome[20];
	int jogos;
	int gols;
	int assist;
}novoJogador;


void criarJogador(novoJogador *jogador, char nome[20], int jogos, int gols, int assist);

void imprimirEstat(novoJogador *jogador);

void ehBom(novoJogador *jogador);
