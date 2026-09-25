#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXT 100
#define MAXL 1000

typedef struct Data {
	int dia;
	int mes;
	int ano;
}Data;
Data parseData( char* in ) {
	Data a;
	char *b = strtok( in, "-");
	a.ano = atoi(b);
	b = strtok(NULL, "-");
	a.mes = atoi(b);
	b = strtok(NULL, "-");
	a.dia = atoi(b);

	return a;
}
void formatData(Data a, char* b){
	sprintf(b, "%02d/%02d/%04d", a.dia, a.mes, a.ano);
}

typedef struct Veiculo {
	int id;
	char marca[MAXT];
	char modelo[MAXT];
	int ano;
	char categoria[MAXT];
	char combustivel[10][MAXT];
	int cilindros;
	double cilindradas;
	char transmissao[MAXT];
	char tracao[MAXT];
	double consumoCidade;
	double consumoEstrada;
	double co2;
	bool turbo;
	Data dataRegistro;
}Veiculo;

Veiculo *parseVeiculo(char* a){
	Veiculo *b = malloc(sizeof(Veiculo));
	char ctemp[MAXT];
	char *d= strtok(a,",");
	b->id = atoi(d);
	d = strtok(NULL, ",");
	sprintf(b->marca,"%s", d);
	d = strtok(NULL, ",");
	sprintf(b->modelo,"%s", d);
	d = strtok(NULL,",");
	b->ano = atoi(d);
	d = strtok(NULL,",");
	sprintf(b->categoria, "%s", d);
	d = strtok(NULL,",");
	sprintf(ctemp,"%s",d);
	d = strtok(NULL,",");
	b->cilindros = atoi(d);
	d = strtok(NULL,",");
	b->cilindradas = atof(d);
	d = strtok(NULL,",");
	sprintf(b->transmissao,"%s",d);
	d = strtok(NULL,",");
	sprintf(b->tracao, "%s",d);
	d = strtok(NULL,",");
	b->consumoCidade = atof(d);
	d = strtok(NULL,",");
	b->consumoEstrada = atof(d);
	d = strtok(NULL,",");
	b->co2 = atof(d);
	d = strtok(NULL,",");
	b->turbo = (strcmp(d,"true") == 0);
	d = strtok(NULL,",");
	b->dataRegistro = parseData(d);
	for(int n = 0; n<10; n++){
		b->combustivel[n][0] = '\0';
	}
	d = strtok(ctemp, ";");;
	int i = 0;
	while(d != NULL) {
		sprintf(b->combustivel[i],"%s", d);
		i++;
		d = strtok(NULL,";");
	}

	return b;
}
void formatVeiculo(Veiculo a, char* p){
	int i = 0;
	int n = 0;
	int b = 0;
	char c[MAXT];
	c[0] = '\0';
	while( n < 10 && a.combustivel[n][0] != '\0') {
		n++;
	}

	for(i =0;i < n; i ++) {
		int j =0; 
		while(a.combustivel[i][j] != '\0') {
			c[b] = a.combustivel[i][j];
			b++;
			j++;
		}
		if (i < n -1){
			c[b]= ',';
			b++;
			c[b] = ' ';
			b++;
		}
	}
	c[b] = '\0';

	char *turbo;
	if(a.turbo == true) {
		turbo = "true";
	}else {
		turbo = "false";
	}
	char d[11];
	formatData(a.dataRegistro,d);


	sprintf(p,"[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1f ## %s ## %s ## %.2f ## %.2f ## %.1f ## %s ## %s]",a.id,a.marca,a.modelo,a.ano,a.categoria,c,a.cilindros,a.cilindradas,a.transmissao,a.tracao,a.consumoCidade,a.consumoEstrada,a.co2,turbo,d);

}

Veiculo* lerCsv (char* carq, int* n) {
	char l[MAXL];
	*n = 0;
	int i = 0;
	FILE *arq = fopen(carq, "r");

	fgets(l,MAXL,arq);
	while( fgets(l,MAXL,arq) != NULL){
		(*n)++;
	}
	fclose(arq);
	arq = fopen(carq, "r");
	Veiculo *a = malloc( (*n) * sizeof(Veiculo));
	fgets(l,MAXL,arq);
	while(fgets(l,MAXL,arq) != NULL){
		Veiculo *v = parseVeiculo(l);
		a[i] = *v;
		free(v);
		i++;

	}
	fclose(arq);
	return a;
}

void slcsort(Veiculo a[], int n) {
	for( int  i = 0; i< n-1; i++) {
		int menor = i;
		for(int j = i+1; j< n; j++ ) {
			if(strcmp(a[j].modelo, a[menor].modelo)< 0){
				menor = j;
			}
		}
		Veiculo tmp = a[i];
		a[i] = a[menor];
		a[menor] = tmp;

	}
}

void main () {
	int n = 0;
	int id = 0;
	char f[MAXL];
	Veiculo *a =  lerCsv("/tmp/veiculos.csv", &n);
	Veiculo b[MAXL];
	int z = 0;

	scanf("%d", &id);
	while ( id != -1) {
		for(int i = 0; i< n; i++){
			if( id == a[i].id) {
			       	b[z] = a[i];
				z++;
			}
		}
		scanf("%d", &id);
	}
	slcsort(b,z);
	for( int c = 0; c<z; c++) {
		formatVeiculo(b[c],f);
		printf("%s\n",f);
	}



	free(a);

}
