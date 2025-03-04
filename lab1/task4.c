#include <stdio.h>
#include <math.h>

int perimeter(short a, short b, short c);
int square(short a, short b, short c, short p);


int main() {
	int a, b, c;
	printf("Vvedite a: ");
	scanf("%d", &a);
	printf("Vvedite b: ");
	scanf("%d", &b);
	printf("Vvedite c: ");
	scanf("%d", &c);
	if ((((a + b)<c) || ((a + c)<b) || ((b + c)<a)) || a < 0 || b < 0 || c < 0){
		printf("Takogo treugolnika net\n");
		return 0;
	}
	int P = perimeter(a, b, c);
	int p = P/2;
	int S = square(a, b, c, p);
	printf("Perimetr trugolnika: %d\n", P);
	printf("Ploshad treugolnika: %d\n", S);
	return 0;
}

int perimeter(short a, short b, short c){
	int perimeter = a + b + c;
	return perimeter;
}

int square(short a, short b, short c, short p){
	int square = sqrt(p * (p - a) * (p - b) * (p - c));
	return square;
}
