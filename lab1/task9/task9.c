#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 256

double sum_input(char *nums[], int size) {
    double summ = 0;
    int i, j, k;
    char sign = '+';
    char str[N];
    
    for (i = 0; i < size; i++) {
        k = 0;
        for (j = 0; j < strlen(nums[i]); j++) {
            if (nums[i][j] == '+' || nums[i][j] == '-') {
                if (j > 0) {
                    str[k] = '\0';
                    if (str[0] != '\0') {
                        if (sign == '-') {
                            summ -= atof(str);
                        } else {
                            summ += atof(str);
                        }
                    }
                    k = 0;
                }
                sign = nums[i][j];
            } else if (isdigit(nums[i][j]) || nums[i][j] == '.') {
                str[k++] = nums[i][j];
            }
        }
        if (k > 0) {
            str[k] = '\0';
            if (sign == '-') {
                summ -= atof(str);
            } else {
                summ += atof(str);
            }
        }
    }
    return summ;
}

int main() {
	char input[N];
	char *nums[N];
	int i, j;
	int k = 0;
	fgets(input, N, stdin);
	char *numbers = strtok(input, " ");
	while (numbers) {
		nums[k++] = numbers;
        numbers = strtok(NULL, " ");
    }
	double sum = sum_input(nums, k);
	printf("%.2f\n", sum);
	return 0;
}
