#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;
unsigned long long sum = 0;

int fib(unsigned long long num1, unsigned long long num2, int amount){
	sum += num1;
	
	if(amount == 1){
		longjmp(env, 1);
	}
	
	return fib(num2, num2+num1, amount-1);
}

int main(){
	int am;
	printf("Input numbers amount: ");
	scanf("%d", &am);
	int val = setjmp(env);
	
	if(val == 0){
		fib(1, 1, am);
	}
	
	printf("%llu", sum);
	return 0;
}
