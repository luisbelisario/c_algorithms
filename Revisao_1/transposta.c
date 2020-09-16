#include <stdio.h>

int main() {

	int matriz[3][3];

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			matriz[i][j] = j+1;
		}
	}

	printf("MATRIZ\n");

	for(int i=0;i<3;i++) {
		printf("[%d] [%d] [%d]\n", matriz[i][0], matriz[i][1], matriz[i][2]);
	}

	int transposta[3][3];
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			transposta[i][j] = matriz[j][i];
		}
	}

	printf("\nMATRIZ TRANSPOSTA\n");

	for(int i=0;i<3;i++) {
		printf("[%d] [%d] [%d]\n", transposta[i][0], transposta[i][1], transposta[i][2]);
	}

	return 0;
}
