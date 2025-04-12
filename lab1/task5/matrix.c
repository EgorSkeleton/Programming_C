#include <stdio.h>
#include <stdlib.h>

double** matrix(int n){
	double **arr;
	int i, k;
	arr = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++){
		arr[i] = (double*)malloc(n * sizeof(double));
	}
	for (i = 0; i < n; i++){
		for (k = 0; k < n; k++){
			printf("Vvedite element masiva: ");
			scanf("%lf", &arr[i][k]);
		}
	}
	return arr;
}

double** sum(double **arr1, double **arr2, int n){
	double **res;
	int i, j;
	res = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++){
		res[i] = (double*)malloc(n * sizeof(double));
	}
	for (i=0; i<n; i++){
		for(j=0; j<n; j++){
			res[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	return res;
}

double** diff(double **arr1, double **arr2, int n){
	double **res;
	int i, j;
	res = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++){
		res[i] = (double*)malloc(n * sizeof(double));
	}
	for (i=0; i<n; i++){
		for(j=0; j<n; j++){
			res[i][j] = arr1[i][j] - arr2[i][j];
		}
	}
	return res;
}

double** mult(double **arr1, double **arr2, int n){
	double **res;
	int i, j, k;
	res = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++){
		res[i] = (double*)malloc(n * sizeof(double));
	}
	for (i=0; i<n; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				res[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	return res;
}

double s_e(double **arr, int n){
	double res;
	int i, j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			res += arr[i][j];
		}
	}
	return res;
}

