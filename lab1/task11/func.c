#include <stdarg.h>
#include <stdio.h>

double sum(int count, ...){
	va_list args;
	va_start(args, count);
	
	double sum = 0;
	int i;
	
	for (i = 0; i<count; i++){
		double num = va_arg(args, double);
		sum += num;
	}
	
	va_end(args);
	return sum;
}

double max(int count, ...){
	va_list args;
	va_start(args, count);
	
	double max = va_arg(args, double);
	int i;
	
	for(i = 0; i<count-1; i++){
		double num = va_arg(args, double);
		if (num > max){
			max = num;
		}
	}
	
	va_end(args);
	return max;
}

double min(int count, ...){
	va_list args;
	va_start(args, count);
	
	double min = va_arg(args, double);
	int i;
	
	for(i = 0; i<count-1; i++){
		double num = va_arg(args, double);
		if (num < min){
			min = num;
		}
	}
	
	va_end(args);
	return min;
}

double ave(int count, ...){
	va_list args;
	va_start(args, count);
	
	double sum = 0, ave;
	int i;
	
	for (i=0; i<count; i++){
		double num = va_arg(args, double);
		sum += num;
	}
	
	ave = sum/count;
	
	va_end(args);
	return ave;
}
