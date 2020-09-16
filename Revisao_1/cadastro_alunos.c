#include <stdio.h>


struct st_aluno {
	int matricula;
	float nota1;
	float nota2;
};

struct st_bancoAlunos {
	struct st_aluno alunos[100];
}bancoAlunos;


float calcularMedia(float n1, float n2);

int main() {

	for(int i=0;i<3;i++) {
		printf("Digite a matricula do aluno %d: ", i+1);
		scanf("%d", &bancoAlunos.alunos[i].matricula);
		printf("Digite a primeira nota do aluno %d: ", i+1);
		scanf("%f", &bancoAlunos.alunos[i].nota1);
		printf("Digite a segunda nota do aluno %d: ", i+1);
		scanf("%f", &bancoAlunos.alunos[i].nota2);
	}

	for(int i=0;i<3;i++) {
		float media = calcularMedia(bancoAlunos.alunos[i].nota1, bancoAlunos.alunos[i].nota2);
		printf("Média do aluno %d: %.1f\n", i+1, media);
	}
}

float calcularMedia(float n1, float n2) {
	return (n1+n2)/2;
}
