#include <stdio.h>
#include <stdlib.h>

//calcula o comprimento da maior substring sem caracteres repetidos.
int longa(char in[]){
	bool a = 1;
	bool c = 1; 
	int b = 0;
	int h =0;
	int n =0;
	int i =0;
	int j =0;


	while(a){
	if(in[b]){
        n++;
	}else
	{ a = 1;}
	b++;
	}
	
	
	  for(i = 0; i < n-1; i++) {
		  for(j = i+1; j< n; j++) {
			  if(in[i] == in[j] && c){
				  c = 1;
				  h = j;

		               }
		 	         
		   }
	   }
	 if( h == 0) {
		 h = n;}
	
	//printf("%d\n",h);

	return h;
}




int main () {

	char f[100];
	scanf("%s", f);

	while(!(f[0] == 'F' && f[1] == 'I' && f[2] == 'M' && f[3] == '\0')) {
	
        printf("%d\n", longa(f));
	scanf("%s", f);
	}
}
