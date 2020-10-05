typedef struct Aluno {
	int matricula;
	float nota1, nota2, nota3;
}Aluno;

typedef struct No {
	Aluno aluno;
	struct No *prox;
	/* Aqui estou definindo uma struct do tipo nó.
	 * Uma struct nó tem um Item e um ponteiro DO TIPO nó
	 * que aponta para o próximo no
	 */
}No;

typedef struct Lista {
	int tam;
	No *pInicio;
	No *pFim;
}Lista;

// Aqui estou criando uma struct com dois ponteiros do tipo Nó
// Esses ponteiros apontam para o início e para o fim da lista, respectivamente

Lista* criar_lista();
int lista_eh_vazia(Lista *lista);
int insere_elemento_inicio(Lista *lista, Aluno novoItem);
int insere_elemento_final(Lista *lista, Aluno novoItem);
int remove_elemento_inicio(Lista *lista);
int remove_elemento_final(Lista *lista);
int insere_elemento_posicao(Lista *lista, Aluno aluno, int posicao);
int remove_elemento_posicao(Lista *lista, int posicao);
int inverter_lista(Lista *lista);
Lista* criar_lista_impares(Lista *lista);
Lista* criar_lista_inversa(Lista *lista);
void imprimir_lista(Lista *lista);
int tamanho_lista(Lista *lista);
