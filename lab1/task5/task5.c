#include "matrix.h"

int main(int argc, char *argv[]) {
	int n, i, j;
	char c;
	printf("Vvedite razmernost matritsi: ");
	scanf("%d", &n);
	double **arr1, **arr2, **res;
	printf("VVedite znachenia pervoi matritsi\n");
	arr1 = matrix(n);
	printf("VVedite znachenia vtoroi matritsi\n");
	arr2 = matrix(n);
	res = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++){
		res[i] = (double*)malloc(n * sizeof(double));
	}
	printf("Input + if sum, - if diff, * if mult: ");
	scanf(" %c", &c);
	switch(c){
		case '+':
			res = sum(arr1, arr2, n);
			for (i = 0; i < n; i++){
				for(j=0; j<n; j++){
					printf("%lf ", res[i][j]);
				}
				printf("\n");
			}
			break;
		case '-':
			res = diff(arr1, arr2, n);
			for (i = 0; i < n; i++){
				for(j=0; j<n; j++){
					printf("%lf ", res[i][j]);
				}
				printf("\n");
			}
			break;
		case '*':
			res = mult(arr1, arr2, n);
			for (i = 0; i < n; i++){
				for(j=0; j<n; j++){
					printf("%lf ", res[i][j]);
				}
				printf("\n");
			}
			break;
	}
	for (i = 0; i < n; i++){
		free(res[i]);
		free(arr1[i]);
		free(arr2[i]);
	}
	free(res);
	free(arr1);
	free(arr1);
	return 0;
}
