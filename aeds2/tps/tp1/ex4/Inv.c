#include <stdio.h>
#include <stdlib.h>
//Inverte iterativamente os caracteres de uma string.
void inverter (char in[]) {
	int n = 0;
	int a = 1;
	int b = 0;
	int i = 0;
	int j = 0;
	int y = 0;
	char temp;

	while(a) {
	if(in[b]) {
	n++;
	}else{
	a = 0; }
	b++;
	}

        j = n - 1;
	y = n/2;

	for( i = 0; i < y; i++) {
		temp = in[i];
		in[i] = in[j];
		in[j] = temp;
		j--;
	}
}
int main () {

	char f[100];
	scanf("%s", f);


	while(!(f[0] == 'F' && f[1] == 'I' && f[2] == 'M' && f[3] == '\0')) {

		inverter(f);
		printf("%s\n",f);
		scanf("%s",f);
	}
}
/*
* abcde - edcba
* arara - arara
* a - a
* abcd - dcba
*/



