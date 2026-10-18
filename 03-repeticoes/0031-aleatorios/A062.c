// A062 · 6000 lançamentos: o dado é honesto?

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time

int main(void) {
    srand(42); // semente fixa, para a saída abaixo ser reproduzível
    // srand((unsigned) time(NULL)); // use esta linha para variar a cada execução

    int um = 0, dois = 0, tres = 0, quatro = 0, cinco = 0, seis = 0;
    int total = 6000;

    for (int i = 0; i < total; i++) {
        switch (1 + rand() % 6) {
        case 1: um++; break;
        case 2: dois++; break;
        case 3: tres++; break;
        case 4: quatro++; break;
        case 5: cinco++; break;
        default: seis++;
        }
    }

    printf("Face 1: %4d (%.1f%%)\n", um, 100.0 * um / total);
    printf("Face 2: %4d (%.1f%%)\n", dois, 100.0 * dois / total);
    printf("Face 3: %4d (%.1f%%)\n", tres, 100.0 * tres / total);
    printf("Face 4: %4d (%.1f%%)\n", quatro, 100.0 * quatro / total);
    printf("Face 5: %4d (%.1f%%)\n", cinco, 100.0 * cinco / total);
    printf("Face 6: %4d (%.1f%%)\n", seis, 100.0 * seis / total);
    return 0;
}
// Saída (glibc, Linux, semente 42):
// Face 1:  976 (16.3%)
// Face 2: 1001 (16.7%)
// Face 3:  978 (16.3%)
// Face 4: 1026 (17.1%)
// Face 5: 1024 (17.1%)
// Face 6:  995 (16.6%)
