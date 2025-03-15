#include <stdio.h>
#include <stdlib.h>

void main(){
	int i, j, k;
	double list_1[3][3];
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("Vvod: ");
			scanf("%lf", &list_1[i][j]);
		}
	}
	int sum_on_main_diaganal = list_1[0][0] + list_1[1][1] + list_1[2][2];
	printf("Summa na glavnoi diagonali: %d\n", sum_on_main_diaganal);
	int sum_on_side_diaganal = list_1[0][2] + list_1[1][1] + list_1[2][0];
	printf("Summa na pobochnoi diagonali: %d\n", sum_on_side_diaganal);
	int list_2[2][2];
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			printf("Vvod: ");
			scanf("%d", &list_2[i][j]);
		}
	}
	int list_2_sq[2][2];
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j ++){
			for (k = 0; k < 2; k++){
				list_2_sq[i][j] += list_2[i][k] * list_2[k][j];
			}
			 
		}
	}
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j+=2){
			printf("%d %d\n", list_2_sq[i][j], list_2_sq[i][j+1]);
		}
	}
}
