#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define N 65

void double_1_count(double num){
	int i, k = 0, count = 0;
	char num_str[N];
	union {
		double x;
	 	uint64_t u;
	} converter;
	
	converter.x = num;
	uint64_t bits = converter.u;
	
	for (i = 63; i >= 0; i--) {
		num_str[k++] = ((bits >> i) & 1) ? '1' : '0';
        printf("%lu", (bits >> i) & 1); 
	}
	num_str[k] = '\0';
	for(i=0; i<N; i++){
		if(num_str[i] == '1'){
			count++;
		}
	}
	printf("\n%d\n", count);
}

void long_1_count(long num){
	int i, k = 0, count = 0;
	char num_str[33];
	union {
		long x;
		uint32_t u;
	}converter;
	
	converter.x = num;
	uint32_t bits = converter.u;
	
	for (i = 31; i>= 0; i--){
		num_str[k++] = ((bits >> i) & 1) ? '1' : '0';
		printf("%lu", (bits >> i) & 1);
	}
	printf("\n");
	num_str[k] = '\0';
	for(i=0; i<33; i++){
		if(num_str[i] == '1'){
			count++;
		}
	}
	printf("\n%d", count);
}

int main() {
	double num1;
	long num2;
	printf("Input double number\n");
	scanf("%lf", &num1);
	printf("Input long number\n");
	scanf("%ld", &num2);
	double_1_count(num1);
	long_1_count(num2);
	return 0;
}
