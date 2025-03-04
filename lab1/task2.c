#include <stdio.h>
#include <stdlib.h>

void main(){
	int i, j;
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
	list_2_sq[0][0] = list_2[0][0] * list_2[0][0] + list_2[0][1] * list_2[1][0];
	list_2_sq[0][1] = list_2[0][0] * list_2[0][1] + list_2[0][1] * list_2[1][1];
	list_2_sq[1][0] = list_2[1][0] * list_2[0][0] + list_2[1][1] * list_2[1][0];
	list_2_sq[1][1] = list_2[1][0] * list_2[0][1] + list_2[1][1] * list_2[1][1];
	printf("%d %d\n", list_2_sq[0][0], list_2_sq[0][1]);
	printf("%d %d\n", list_2_sq[1][0], list_2_sq[1][1]);
}
