typedef struct No {
	int valor;
	struct No* ant;
	struct No *prox;
}No;

typedef struct Lista {
	No *pInicio;
	int tam;
}Lista;

Lista* criar_lista();
int eh_vazia(Lista *lista);
int insere_elemento_inicio(Lista *lista, int novoValor);
int menor_elemento(Lista *lista);
int move_elemento_inicio(Lista *lista, int valor);
void imprimir_lista(Lista *lista);
