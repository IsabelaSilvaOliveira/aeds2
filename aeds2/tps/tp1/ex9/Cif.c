#include <stdio.h>
#include<stdlib.h>

// Cifra recursivamente cada caractere da string, fazendo o caracter deslocar 3 posicoes .
void cifrar( char in [], int i) {

	int n = 0;
	int b = 0;

	if(in[i] == '\0') {
	      return;
	}else  {
		char e = in[i] + 3;
		printf("%c", e);
		cifrar(in,i + 1);
	}
}
	
int main () {

	char f[100];
	int n =0;
    int i = 0;

	fgets(f, 100, stdin);

	
    i = 0;
    while (f[i] != '\0') {
        if (f[i] == '\n') {
            f[i] = '\0';
        }
        i++;
    }


	while(!(f[0] == 'F' && f[1] == 'I' && f[2] == 'M' && f[3] == '\0')){

		cifrar(f,0);
		printf("\n");
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
