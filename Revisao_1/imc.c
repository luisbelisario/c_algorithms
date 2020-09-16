#include <stdio.h>
#include <string.h>

struct st_pessoa {
	char cpf[10];
	float altura;
	float peso;
	char sexo;
};

struct st_cadastropessoas {
	struct st_pessoa pessoas[10];
};

float calculaIMC(float altura, float peso);

int main() {


	int n;

	struct st_cadastropessoas cadastro;

	printf("Digite quantas pessoas deseja cadastrar: ");
	scanf("%d", &n);
	getchar();

	for(int i=0;i<n;i++) {

		printf("\nDigite o cpf da %dª pessoa: ", i+1);
		fgets(cadastro.pessoas[i].cpf, 10, stdin);

		printf("Digite a altura da %dª pessoa: ", i+1);
		scanf("%f", &cadastro.pessoas[i].altura);

		printf("Digite o peso da %dª pessoa: ", i+1);
		scanf("%f", &cadastro.pessoas[i].peso);
		getchar();

		printf("Digite o sexo da %dª pessoa: ", i+1);
		scanf("%c", &cadastro.pessoas[i].sexo);
		getchar();
	}

	printf("\nPessoas cadastradas com sucesso!\n");

	printf("Digite o cpf da pessoa que deseja calcular o IMC: ");
	char cpfbusca[10];
	fgets(cpfbusca, 10, stdin);

	float imc;

	for(int i=0;i<n;i++) {
		if(strcmp(cadastro.pessoas[i].cpf, cpfbusca) == 0) {
			imc = calculaIMC(cadastro.pessoas[i].altura, cadastro.pessoas[i].peso);
		}
	}

	printf("O IMC da pessoa buscada é: %.1f", imc);

	return 0;
}

float calculaIMC(float altura, float peso) {
	return peso/(altura*altura);
}
