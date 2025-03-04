#include <stdio.h>
#include <ctype.h>

void main(){
	char str[80];
	int i;
	printf("Vvedite stroku simvolov: ");
	fgets(str, sizeof(str), stdin);
	for (i = 0; i<sizeof(str); i++){
		char ch = str[i];
		if ((ch == 'a')||(ch == 'b')){
			str[i] = toupper(ch);
		}
	}
	printf("Result: %s\n", str);
}
