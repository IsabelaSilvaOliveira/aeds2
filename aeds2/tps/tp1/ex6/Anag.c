#include <stdio.h>
#include <stdlib.h>

bool anagrama( char a[], char b[]){
	bool resp = true;
	bool z = true;
	int i = 0;
	int j = 0;
	int t1 =0;
	int t2 = 0;
	int c = 0;
	int y =0;

        while(z) {
	if(a[c]){
	t1++;
	}else{
	z = false;}
	c++;
	}

	c = 0;
	z = true;

	while(z){
	if(b[c]) {
	t2++;
	}else{
	z = false;}
	c++;
	}
	
	if ( t1 != t2 ) {
	resp = false;
	}
	else {
	for(i = 0; i< t1; i++) {
		for(j = 0; j< t1; j++) {
			if( a[i] == b[j]){
				y++;
			}
		}
		if( y == 0 ){
		resp = false;}
	     }
	}

	return resp;
}


int main () {
 char a[100];
 char b[100];
 

 scanf("%s", a);
 scanf("%s", b);

 while(!(a[0] == 'F' && a[1] == 'I' && a[2] == 'M' && a[3] == '\0')) {
	 if(anagrama(a,b)){
           printf("SIM\n"); 
	}else
	{  printf("NAO\n");}
	scanf("%s", a);
	scanf("%s", b);
}

}
