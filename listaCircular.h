typedef struct No {
	int valor;
	struct No *prox;
}No;

typedef struct ListaCircular {
	int tam;
	No *pInicio;
}ListaCircular;

ListaCircular* criar_lista();
int eh_vazia(ListaCircular *lista);
int insere_elemento_inicio(ListaCircular *lista, int novoValor);
void imprimir_lista(ListaCircular *lista);
int tamanho_lista(ListaCircular *lista);
int troca_valores(ListaCircular *lista, int posicao);
