#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *ln, *newf;
	int k;
	ln = fopen("Lastnames.txt", "rt");
	newf = fopen("After1980.txt", "w");
	if (ln == NULL){
		printf("Erorr while opening file");
		return 0;
	}
	char str[50];
	int i, age;
	printf("Choose sort type: 1 - by 1980, 2 - by 'a' ");
	scanf("%d", &k);
	while(fgets(str, 50, ln)!=NULL){
		switch(k){
			case(1):
					for(i=0; i<51; i++){
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
				case(2):
					if(str[i] == 'A'){
						fputs(str, newf);
					}
			}
			
	}
		
	fclose(ln);
	fclose(newf);
	return 0;
}
