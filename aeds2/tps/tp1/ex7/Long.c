#include <stdio.h>
#include <stdlib.h>

// Calcula o comprimento da maior substring sem caracteres repetidos.
int longa(char in[]) {
    int a = 1;
    int b = 0;
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int h = 0;
    int resp = 0;
    int repetiu = 0;
    int continua = 1;


    while (a) {
        if (in[b] != '\0') {
            n++;
        } else {
            a = 0;
        }
        b++;
    }

   
    for (i = 0; i < n; i++) {

        h = 0;
        continua = 1;

        for (j = i; j < n && continua; j++) {

            repetiu = 0;

            // Verifica se in[j] já apareceu entre i e j-1
            for (k = i; k < j; k++) {
                if (in[j] == in[k]) {
                    repetiu = 1;
                }
            }

            if (repetiu) {
                continua = 0;
            } else {
                h++;

                if (h > resp) {
                    resp = h;
                }
            }
        }
    }

    return resp;
}

int main() {
    char f[100];

    scanf("%s", f);

    while (!(f[0] == 'F' &&
             f[1] == 'I' &&
             f[2] == 'M' &&
             f[3] == '\0')) {

        printf("%d\n", longa(f));

        scanf("%s", f);
    }
}

/*
Testes:
abcabcbb - 3
abcc - 3
abcdbe - 4
pwwkew - 3
abcdef - 6
aaaa - 1
a - 1
obs: tive que adicionar o for que verifica se in[j] já apareceu entre i e j-1 pois eu estava achando apenas a substring antes de encontrar uma letra repetida, e nao a maior.
*/
