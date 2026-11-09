// Lista · Módulo 13 · Busca e ordenação
// Exercício P1308 · ★☆☆ · As capitais mais quentes primeiro

#include <stdio.h>
#include <stdlib.h>

int crescente(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int decrescente(const void *a, const void *b) {
    return crescente(b, a);
}

void mostra(const char *rotulo, const int v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int maximas[] = {34, 29, 38, 22, 31, 36, 27};
    int n = 7;

    qsort(maximas, n, sizeof maximas[0], crescente);
    mostra("crescente", maximas, n);
    qsort(maximas, n, sizeof maximas[0], decrescente);
    mostra("decrescente", maximas, n);
    printf("as 3 mais quentes: %d %d %d\n", maximas[0], maximas[1], maximas[2]);
    return 0;
}
