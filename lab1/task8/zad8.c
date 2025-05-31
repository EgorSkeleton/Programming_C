
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



struct human{
	char name[50]; 
	char lastname[50]; 
	int year; 
	char gend[3]; 
	float height; 
};
struct human B[100], temp;

int sravn(const struct human* a, const struct human* b, const char* choose) {
	int i;
	for (i = 0; choose[i] != '\0'; i++) {
		switch (choose[i]) {
		case 'y': 
			if (a->year != b->year) {
				return a->year - b->year;
			}
			break;
		case 'n': 
		{
			int cmp = strcmp(a->name, b->name);
			if (cmp != 0) return cmp;
			break;
		}
		case 'l': 
		{
			int cmp = strcmp(a->lastname, b->lastname);
			if (cmp != 0) return cmp;
			break;
		}
		case 'g': 
			if (a->gend != b->gend) {
				return a->gend - b->gend;
			}
			break;
		case 'h': 
			if (a->height != b->height) {
				return (a->height > b->height) ? 1 : -1;
			}
			break;
		}
	}
	return 0;
}

int main() {
	FILE* f1 = fopen("vvod8.txt","rt");
	
	int k = 0;
	int i = 0, j;
	while (fscanf(f1, "%s %s %d %s %f", B[k].name, B[k].lastname,  &B[k].year, &B[k].gend, &B[k].height) != EOF) {
		k++;
		
	}
	fclose(f1);


	char choose[10];
	printf("Vvedi kreterii (y - year, n - name, l - lastname, g - gender, h - hight) (Vvodi po poredku): ");
	scanf("%s", choose);


	for (i = 0; i < k - 1; i++) {
		for (j = 0; j < k - i - 1; j++) {
			if (sravn(&B[j], &B[j + 1], choose) > 0) {
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}

	
	for (i = 0; i < k; ++i) {
		printf("%s %s %d %s %.2f\n", B[i].name, B[i].lastname, B[i].year, B[i].gend, B[i].height);
	}



	return 0;
}

