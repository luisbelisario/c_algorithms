#include <stdio.h>

int main() {

	int matriz[5][5];

	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			if(i==j) {
				matriz[i][j] = 1;
			}
			else {
				matriz[i][j] = 0;
			}
		}
	}

	for(int i=0;i<5;i++) {
		printf("[%d] [%d] [%d] [%d] [%d]\n", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4]);
	}
}
