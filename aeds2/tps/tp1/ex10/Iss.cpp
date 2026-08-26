#include <stdio.h>
#include <stdlib.h>

bool vog(char in[],int i){
	if(in[i] == '\0') {
		return true;
	}else{
	if(in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u' || in[i] == 'A' || in[i] == 'E' || in[i] == 'I' || in[i] == 'O' || in[i] == 'U') {
		
	return vog(in, i+1);
	}
	else{
	return false;}
	}
}

bool cons(char a[], int i) {
        if(a[i] == '\0') {
	return true;
	}
	else {
	if((a[i] >= '0' &&  a[i] <= '9') || ( a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') || (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')){
	return false;
	     }
	}
	return cons(a,i+1);
}

bool inte(char a[], int i){
       	 if(a[i] == '\0') {
	      return true;
	 }else {
	 if(!(a[i] >= '0' && a[i]<= '9')){
	 return false;
	 }
	 }
	return inte(a,i+1);
}

bool real(char a[],int i,int c) {
        if(a[i] == '\0'){
	if(c > 1){
	return false;}
	else { return true;}
	}else {
	if( a[i] == '.' || a[i] == ',') {
	   c++;
	}else if( !(a[i] >= '0' && a[i] <= '9')) {
	return false; }
	}
	return real(a,i+1,c);
}

int main () {
	char f[100];
	scanf("%s",f);

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
		
	
		scanf("%s",f);
		
	}
}
