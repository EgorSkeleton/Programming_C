#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MAXIMUM(a, b){\
	int max = atoi(a[0]), i;\
	for(i=1; i<(b); i++){\
		int current = atoi(a[i]);\
		max = MAX(max, current);\
	}\
	printf("Max: %d\n", max);\
}
#define AVE(a, b){\
	int sum = atoi(a[0]), i;\
	for (i=1; i<(b); i++){\
		int current = atoi(a[i]);\
		sum += current;\
	}\
	double ave = sum/b;\
	printf("Average: %.2f\n", ave);\
}
#define N 256

int main() {
	char *input[N];
	char *nums[N];
	int k = 0, i;
	fgets(input, N, stdin);
	char *numbers = strtok(input, " ");
	while (numbers) {
		nums[k++] = numbers;
        numbers = strtok(NULL, " ");
    }
	
	MAXIMUM(nums, k);
	AVE(nums, k);
	return 0;
}
