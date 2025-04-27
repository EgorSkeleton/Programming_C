#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 80

typedef struct{
		char firstname[50];
		char lastname[50];
		int birth_date;
	}human;

void sort_by_birth_date(human people[], int sorted_indexes[], int size){
	int min_index;
	int i, j;
	bool used[size];
	for(j = 0; j<size; j++){	
		used[i] = false;
	}
	
	for(j = 0; j<size; j++){
		for (i = 0; i < size; i++) {
           	 	if (!used[i]) {
                		min_index = i;
                		break;
            		}
        	}
		for (i = 0; i<size; i++){
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
	char str[N];
	int i, j;
	int size = 0;
	while(fgets(str, N, ln) != NULL){
		size++;
	}
	rewind(ln);
	human original[size];
	human sorted[size];
	int sorted_indexes[size];
	
	for(i = 0; i < size; i++){
		fscanf(ln, "%s %s %d", 
			original[i].firstname, 
			original[i].lastname, 
			&original[i].birth_date);
	}
	fclose(ln);
	
	sort_by_birth_date(original, sorted_indexes, size);
	
	for (i = 0; i<size; i++){
		sorted[i] = original[sorted_indexes[i]];
	}
	
	printf("sorted list:\n");
	for(i=0; i<size; i++){
		printf("%s %s %d\n", 
			sorted[i].firstname,
			sorted[i].lastname,
			sorted[i].birth_date);
	}
	
	return 0;
}
