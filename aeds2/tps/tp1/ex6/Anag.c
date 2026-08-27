#include <stdio.h>
#include <stdlib.h>

// Verifica  se duas strings sao anagramas.
int anagrama(char a[], char b[]) {
    int resp = 1;
    int z = 1;
    int i = 0;
    int j = 0;
    int t1 = 0;
    int t2 = 0;
    int c = 0;
    int y = 0;

    while (z) {
        if (a[c] != '\0') {
            t1++;
        } else {
            z = 0;
        }
        c++;
    }

    c = 0;
    z = 1;

    while (z) {
        if (b[c] != '\0') {
            t2++;
        } else {
            z = 0;
        }
        c++;
    }

    if (t1 != t2) {
        resp = 0;
    }
    else {
        for (i = 0; i < t1; i++) {

            y = 0;

            for (j = 0; j < t1; j++) {

    char x = a[i];
    char w = b[j];

    if (x >= 'A' && x <= 'Z') {
        x = x + 32;
    }

    if (w >= 'A' && w <= 'Z') {
        w = w + 32;
    }

    if (x == w) {
        y++;
    }
}

            if (y == 0) {
                resp = 0;
            }
        }
    }

    return resp;
}

int main() {
    char a[100];
    char b[100];

    scanf("%s", a);
    scanf("%s", b);

    while (!(a[0] == 'F' &&
             a[1] == 'I' &&
             a[2] == 'M' &&
             a[3] == '\0')) {

        if (anagrama(a, b)) {
            printf("SIM\n");
        }
        else {
            printf("NAO\n");
        }

        scanf("%s", a);
        scanf("%s", b);
    }
}

/*
testes:
* listen silent - SIM
* amor roma - SIM
* abc abd - NAO
* abc ab - NAO
*/
