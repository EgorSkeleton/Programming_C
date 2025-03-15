#include "task4.h"

int main() {
	int a, b, c;
	printf("Vvedite a: ");
	scanf("%d", &a);
	printf("Vvedite b: ");
	scanf("%d", &b);
	printf("Vvedite c: ");
	scanf("%d", &c);
	if (!triangle_rool(a, b, c)){
		return 0;
	}
	int P = perimeter(a, b, c);
	int p = P/2;
	int S = square(a, b, c, p);
	printf("Perimetr trugolnika: %d\n", P);
	printf("Ploshad treugolnika: %d\n", S);
	return 0;
}


