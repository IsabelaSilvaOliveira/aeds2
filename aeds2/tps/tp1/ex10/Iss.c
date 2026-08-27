#include <stdio.h>
#include <stdlib.h>

// verifica recursivamente se todos os caracteres da string sao vogais.
int vog(char in[],int i){
	if(in[i] == '\0') {
		return 1;
	}else{
	if(in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u' || in[i] == 'A' || in[i] == 'E' || in[i] == 'I' || in[i] == 'O' || in[i] == 'U') {
		
	return vog(in, i+1);
	}
	else{
	return 0;}
	}
}

// verifica recursivamente se todos os caracteres da string sao consoantes.
int cons(char a[], int i) {
        if(a[i] == '\0') {
	return 1;
	}
	else {
	if((a[i] >= '0' &&  a[i] <= '9') || ( a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') || (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')){
	return 0;
	     }
	}
	return cons(a,i+1);
}

// verifica recursivamente se a string representa um numero inteiro.
int inte(char a[], int i){
       	 if(a[i] == '\0') {
	      return 1;
	 }else {
	 if(!(a[i] >= '0' && a[i]<= '9')){
	 return 0;
	 }
	 }
	return inte(a,i+1);
}

// verifica recursivamente se a string representa um numero real.
int real(char a[],int i,int c) {
        if(a[i] == '\0'){
	if(c > 1){
	return 0;}
	else { return 1;}
	}else {
	if( a[i] == '.' || a[i] == ',') {
	   c++;
	}else if( !(a[i] >= '0' && a[i] <= '9')) {
	return 0; }
	}
	return real(a,i+1,c);
}

int main () {
	char f[500];
	int i = 0;

	fgets(f, 500, stdin);

    while (f[i] != '\0') {
        if (f[i] == '\n') {
            f[i] = '\0';
        }
        i++;
    }

	while(!(f[0] == 'F' && f[1] == 'I' && f[2] == 'M' && f[3] == '\0')) {
		if(vog(f,0)){
			printf("SIM ");
		}else
		{ printf("NAO ");}
		if(cons(f,0)){
			printf("SIM ");
		}else
		{ printf("NAO ");}
		if( inte(f,0)){
			printf("SIM ");
		}else
		{ printf("NAO "); }
		if(real(f,0,0)){
			printf("SIM\n");
		}else
		{ printf("NAO\n");}
		
	
		fgets(f, 500, stdin);

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
testes:
* aeiou - esperado: SIM NAO NAO NAO
* bcdfg - esperado: NAO SIM NAO NAO
* 12345 - esperado: NAO NAO SIM SIM
* 12.5 - esperado: NAO NAO NAO SIM
*/
