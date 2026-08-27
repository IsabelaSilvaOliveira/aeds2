#include <stdio.h>
#include<stdlib.h>

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

	scanf("%s",f);


	while(!(f[0] == 'F' && f[1] == 'I' && f[2] == 'M' && f[3] == '\0')){

		cifrar(f,0);
		printf("\n");

		scanf("%s",f);

	}
}
