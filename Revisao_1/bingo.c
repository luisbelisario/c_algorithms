#include <stdio.h>
#include <stdlib.h>

int main() {

	int cartela[5][5];

	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			if(i==0 && j==0){
				cartela[i][j] = rand() % 99;
			}
			else {
				int num = rand() % 99;
				if(num != cartela[i][j-1]) {
					cartela[i][j] = num;
				}
			}
		}
	}

	for(int i=0;i<5;i++) {
		printf("[%d] [%d] [%d] [%d] [%d]\n", cartela[i][0], cartela[i][1], cartela[i][2], cartela[i][3], cartela[i][4]);
	}

}
