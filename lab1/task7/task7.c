#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
		char firstname[50];
		char lastname[50];
		int birth_date;
	}human;

void sort_indexes(human people[], int sorted_indexes[]){
	int min_index;
	int i, j;
	bool used[4];
	for(j = 0; j<4; j++){	
		used[i] = false;
	}
	
	for(j = 0; j<4; j++){
		for (i = 0; i < 4; i++) {
            if (!used[i]) {
                min_index = i;
                break;
            }
        }
		for (i = 0; i<4; i++){
			if(!used[i] && people[i].birth_date < people[min_index].birth_date){
				min_index = i;
			}
		}
		
		sorted_indexes[j] = min_index;
		used[min_index] = true;
	}
	
}

int main() {
	FILE *ln;
	ln = fopen("Lastnames_short.txt", "r");
	if (ln == NULL){
		printf("Erorr while opening file");
		return 0;
	}
	human original[4];
	human sorted[4];
	int sorted_indexes[4];
	int i, j;
	
	for(i = 0; i < 4; i++){
		fscanf(ln, "%s %s %d", 
			original[i].firstname, 
			original[i].lastname, 
			&original[i].birth_date);
	}
	fclose(ln);
	
	sort_indexes(original, sorted_indexes);
	
	for (i = 0; i<4; i++){
		sorted[i] = original[sorted_indexes[i]];
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
