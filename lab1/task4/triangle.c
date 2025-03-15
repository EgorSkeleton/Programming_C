#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int perimeter(int a, int b, int c){
	int perimeter = a + b + c;
	return perimeter;
}

int square(int a, int b, int c, int p){
	int square = sqrt(p * (p - a) * (p - b) * (p - c));
	return square;
}
bool triangle_rool(int a, int b, int c){
	if ((((a + b)<c) || ((a + c)<b) || ((b + c)<a)) || a < 0 || b < 0 || c < 0){
		printf("Takogo treugolnika net\n");
		return false;
	}
	return true;
}
