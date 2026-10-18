// 0032 · Juntando tudo
// Exercício E187 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int lances = 36000;
    int setes = 0, dois = 0;

    srand((unsigned) time(NULL));
    for (int i = 0; i < lances; i++) {
        int soma = (1 + rand() % 6) + (1 + rand() % 6);
        if (soma == 7) {
            setes++;
        } else if (soma == 2) {
            dois++;
        }
    }
    printf("Soma 7: %d (%.1f%%)\n", setes, 100.0 * setes / lances);
    printf("Soma 2: %d (%.1f%%)\n", dois, 100.0 * dois / lances);
    return 0;
}
