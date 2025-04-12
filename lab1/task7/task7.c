#include <stdio.h>
#include <stdlib.h>

struct human{
		char firstname[50];
		char lastname[50];
		int birth_date;
	};

int min(struct human struct_lst[]){
	int i, min;
	for(i=0; i<4; i++){
		if(i==0){
			min = struct_lst[i].birth_date;
		}
		else if(struct_lst[i].birth_date < min){
			min = struct_lst[i].birth_date;
		}
	}
	return min;
}

int main() {
	FILE *ln;
	ln = fopen("Lastnames_short.txt", "r");
	if (ln == NULL){
		printf("Erorr while opening file");
		return 0;
	}
	struct human original[4];
	struct human sorted[4];
	int i, j;
	
	for(i = 0; i < 4; i++){
		fscanf(ln, "%s %s %d", 
			original[i].firstname, 
			original[i].lastname, 
			&original[i].birth_date);
	}
	for(j=0;j<4;j++){
		for(i=0; i<4; i++){
			if(original[i].birth_date == min(original)){
				sorted[j] = original[i];
				original[i].birth_date = 2000;
				break;
			}
		}	 
	}
	printf("sorted list:\n");
	for(i=0; i<4; i++){
		printf("%s %s %d\n", 
			sorted[i].firstname,
			sorted[i].lastname,
			sorted[i].birth_date);
	}
	
	return 0;
}
