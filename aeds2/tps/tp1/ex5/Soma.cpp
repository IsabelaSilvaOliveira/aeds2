#include <stdio.h>
#include <stdlib.h>


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
	scanf ("%d", &n);
	while( n != 0) {
	a = soma(n);
	printf("Soma dos digitos de %d: %d\n", n , a);
	scanf( "%d", &n);
	}


}
