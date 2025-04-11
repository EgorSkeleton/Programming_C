#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *ln, *newf;
	ln = fopen("Lastnames.txt", "rt");
	newf = fopen("After1980.txt", "w");
	if (ln == NULL){
		printf("Erorr while opening file");
		return 0;
	}
	char str[50];
	int i, age;
	while(fgets(str, 50, ln)!=NULL){
		for(i=0; i<51; i++){
			printf("%c", str[i]);
			if (str[i] == '1' || str[i] == '2'){
				char a[5] = {str[i], str[i+1], str[i+2], str[i+3], '\0'};
				printf("%s", a);
				age = atoi(a);
				if (age > 1980){
					fputs(str, newf);
				}
			break;
			}
		}
	}
	fclose(ln);
	fclose(newf);
	return 0;
}
