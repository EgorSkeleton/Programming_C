#include <stdio.h>
#include <stdlib.h>

void forward(int N){
	if (N<10){
		printf("%d ", N);
	}else{
		forward(N / 10);
		printf("%d ", N % 10);
	}
}

void backward(int N){
	if (N<10){
		printf("%d ", N);
	}else{
		printf("%d ", N % 10);
		backward(N / 10);
	}
}

int main() {
	int N;
	printf("Input natural number: ");
	scanf("%d", &N);
	forward(N);
	printf("\n");
	backward(N);
	return 0;
}
