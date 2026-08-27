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
	int i = 0;

	fgets(f, 100, stdin);

	// remove o \n colocado pelo fgets
    i = 0;
    while (f[i] != '\0') {
        if (f[i] == '\n') {
            f[i] = '\0';
        }
        i++;
    }

	while(!(f[0] == 'F' && f[1] == 'I' && f[2] == 'M' && f[3] == '\0')) {

		inverter(f);
		printf("%s\n",f);
		fgets(f, 100, stdin);

		i = 0;
        while (f[i] != '\0') {
            if (f[i] == '\n') {
                f[i] = '\0';
            }
            i++;
        }
	}
}
/*
* abcde - edcba
* arara - arara
* a - a
* abcd - dcba
* obs: pensei que era em c++, entao tive que mudar o sacnf para o fgets, pois nele nao tava lendo uma frase completa.
*/



