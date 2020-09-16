#include <stdio.h>
#include <string.h>

struct st_produto {
	char nome[10];
	int codigo;
	float preco;
};

struct st_cadastroprodutos {
	struct st_produto produtos[10];
};


int main() {


	int n;

	struct st_cadastroprodutos cadastro;

	printf("Digite quantas produtos deseja cadastrar: ");
	scanf("%d", &n);

	for(int i=0;i<n;i++) {

		printf("\nDigite o código do %dº produto: ", i+1);
		scanf("%d", &cadastro.produtos[i].codigo);
		getchar();

		printf("\nDigite o nome do %dº produto: ", i+1);
		fgets(cadastro.produtos[i].nome, 10, stdin);

		printf("Digite o preço do %dº produto: ", i+1);
		scanf("%f", &cadastro.produtos[i].preco);
		getchar();

	}

	printf("\nProdutos cadastrados: \n\n");

	for(int i=0;i<n;i++) {
		printf("%d - ", cadastro.produtos[i].codigo);
		printf("%s", cadastro.produtos[i].nome);
	}

	printf("\nDigite o código do produto que deseja buscar: ");
	int codigobusca;
	scanf("%d", &codigobusca);



	for(int i=0;i<n;i++) {
		if(cadastro.produtos[i].codigo==codigobusca) {
			printf("O preço do produto buscado é: %.2f", cadastro.produtos[i].preco);
		}
	}

	return 0;
}
