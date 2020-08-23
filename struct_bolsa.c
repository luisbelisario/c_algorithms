#include <stdio.h>
#include <math.h>

struct st_acao {
	char codigo[6];
	double valor_atual;
	double valor_anterior;
	double variacao;
};

struct st_bolsa {
	struct st_acao acoes[100];
};

void mostraAcoes(struct st_bolsa b[100], int n);
void acoesAbaixo(struct st_bolsa b[100], int n);
double mediaAcoes(struct st_bolsa b[100], int n);
double desvioPadraoAcoes(struct st_bolsa b[100], int n, double media);


int main() {

	int n;

	struct st_bolsa bolsa;

	printf("Digite quantas ações deseja cadastrar: ");
	scanf("%d", &n);
	getchar();

	for(int i=0;i<n;i++) {

		printf("\nDigite o código da companhia %d: ", i+1);
		fgets(bolsa.acoes[i].codigo, 6, stdin);

		printf("Digite o valor atual da ação %d: ", i+1);
		scanf("%lf", &bolsa.acoes[i].valor_atual);

		printf("Digite o valor anterior da ação %d: ", i+1);
		scanf("%lf", &bolsa.acoes[i].valor_anterior);

		bolsa.acoes[i].variacao = (bolsa.acoes[i].valor_atual/bolsa.acoes[i].valor_anterior - 1) * 100;
		getchar();
	}

	printf("\nAções cadastradas com sucesso!\n");

	mostraAcoes(&bolsa, n);
	acoesAbaixo(&bolsa, n);
	double media = mediaAcoes(&bolsa, n);
	double desvio_padrao = desvioPadraoAcoes(&bolsa, n, media);

	printf("\n\nA média dos valores atuais da ações foi: R$ %.2f", media);
	printf("\nO desvio padrão dos valores atuais da ações foi: %.1f", desvio_padrao);
}

void mostraAcoes(struct st_bolsa b[100], int n) {

	printf("\n===Relatório de ações===\n");

	for(int i=0;i<n;i++) {
		printf("\nCódigo da ação: %s", b->acoes[i].codigo);
		printf("\nValor atual: R$ %.2f", b->acoes[i].valor_atual);
		printf("\nValor anterior: R$ %.2f", b->acoes[i].valor_anterior);
		printf("\nVariação percentual: %.1lf%%\n", b->acoes[i].variacao);
	}
}

void acoesAbaixo(struct st_bolsa b[100], int n) {

	double valor;
	int contador = 0;

	printf("\nDigite um valor para verificar quais ações estão abaixo: ");
	scanf("%lf", &valor);

	for(int i=0;i<n;i++) {
		if(b->acoes[i].valor_atual < valor) {
			contador += 1;
		}
	}

	if(contador==1) {
		printf("\nA seguinte ação está com valor abaixo do especificado: ");
		for(int i=0;i<n;i++) {
			if(b->acoes[i].valor_atual < valor) {
				printf("\n%s", b->acoes[i].codigo);
			}
		}
	}
	else if(contador > 1) {
		printf("\nAs seguintes ações estão com valor abaixo do especificado: ");
		for(int i=0;i<n;i++) {
			if(b->acoes[i].valor_atual < valor) {
				printf("\n%s", b->acoes[i].codigo);
			}
		}
	}
	else {
		printf("\nNenhuma ação está com valor abaixo do especificado\n");

	}
}

double mediaAcoes(struct st_bolsa b[100], int n) {

	double media, soma = 0;

	for(int i=0;i<n;i++) {
		soma += b->acoes[i].valor_atual;
	}

	media = soma/n;
	return media;
}

double desvioPadraoAcoes(struct st_bolsa b[100], int n, double media) {

	double desvio, variancia, soma = 0;

	for(int i=0;i<n;i++) {
		soma += (pow(b->acoes[i].valor_atual - media, 2));
	}

	variancia = soma / n;
	desvio = sqrt(variancia);

	return desvio;
}
