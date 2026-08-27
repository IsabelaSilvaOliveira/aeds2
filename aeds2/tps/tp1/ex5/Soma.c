#include <stdio.h>
#include <stdlib.h>

//calcula iterativamente a soma dos dígitos de um número inteiro.
int soma (int n) {

	int a = 0;
	int b = 0;
	int soma = 0;

        b = n;
	while( b >= 1 ) {
	a = b % 10;
	b = b / 10;
	soma = soma + a;
	}

	return soma;
}

int main () {
	int n = 0;
	int a = 0;
    int b = 1;
	scanf ("%d", &n);
	while(b) {
	a = soma(n);
	printf("%d\n", a);
		if(n == 250) 
		{ b = 0;}		
	scanf( "%d", &n);
	}


}
/*
* 12345 - 15
* 1111 - 4
* 9 - 9
* 1000 - 1
*/
