typedef struct No {
	int valor;
	struct No* ant;
	struct No* prox;
}No;

typedef struct ListaDupla {
	int tam;
	No *pInicio;
	No *pFim;
}ListaDupla;

ListaDupla* criar_lista_dupla();
int tamanho_lista(ListaDupla* lista);
int eh_vazia(ListaDupla* lista);
void imprimir_lista(ListaDupla *lista);
int insere_elemento_inicio(ListaDupla *lista, int valor);
int insere_elemento_final(ListaDupla *lista, int valor);
int remove_elemento_inicio(ListaDupla *lista);
int remove_elemento_final(ListaDupla *lista);
int remove_elemento_posicao(ListaDupla* lista);
float media_aritmetica(ListaDupla *lista);
int listas_iguais(ListaDupla *lista1, ListaDupla *lista2);
ListaDupla* lista_multiplos3(ListaDupla *lista);
