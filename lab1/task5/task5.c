#include "matrix.h"

int main(int argc, char *argv[]) {
	int n, i, j, num;
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
	printf("Input + if sum, - if diff, * if mult, s if sum of elements: ");
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
		case 's':
			printf("Input matrix number for sum of elements: ");
			scanf("%d", &num);
			if (num == 1){
				res = s_e(arr1, n);
			}else if(num == 2){
				res = s_e(arr2, n);
			}
			printf("%lf", res);
			break;
	}
	for (i = 0; i < n; i++){
		free(res[i]);
		free(arr1[i]);
		free(arr2[i]);
	}
	free(res);
	free(arr1);
	free(arr2);
	return 0;
}
