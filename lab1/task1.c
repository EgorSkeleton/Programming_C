#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	short i = 1;
	double a, b, c;
	double x1, x2, d;
	do {	
		printf("Vvedite a:\n");
		scanf("%lf", &a);
		printf("Vvedite b:\n");
		scanf("%lf", &b);
		printf("Vvedite c:\n");
		scanf("%lf", &c);
		d = pow(b, 2) - 4*a*c;
		printf("d = %lf\n", d);
		
		
		if(d < 0) printf("KORNEI NET");
		if(d > 0) {
			d = pow(b, 2) - 4*a*c;
			x1 = (-b + sqrt(d))/(2*a);
			x2 = (-b - sqrt(d))/(2*a);
			printf("x1 = %lf\n", x1);
			printf("x2 = %lf\n", x2);
			printf("d = %lf", d);
		}
		if(d == 0){
			x1 = -b/(2*a);
			printf("Only one koren = %lf\n", x1);
		}
		printf("Hotite li vi prodolgite?\nVvedite 0/1 kak net/da\n");
		scanf("%d", &i);
}while(i!=0);
	return 0;
}
