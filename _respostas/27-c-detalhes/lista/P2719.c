// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2719 · ★★☆ · Ordenar andando com ponteiros

#include <stdio.h>

int *maior(int *ini, int *fim) {
    int *m = ini;
    for (int *p = ini + 1; p < fim; p++) {
        if (*p > *m) {
            m = p;
        }
    }
    return m;
}

void ordenar(int *ini, int *fim) {
    while (fim - ini > 1) {
        int *m = maior(ini, fim);
        int t = *m;
        *m = *(fim - 1);
        *(fim - 1) = t;
        fim--;
    }
}

int main(void) {
    int v[] = {42, 7, 19, 88, 3};
    int *m = maior(v, v + 5);
    printf("maior: %d no índice %td\n", *m, m - v);
    ordenar(v, v + 5);
    printf("ordenado:");
    for (int *p = v; p < v + 5; p++) {
        printf(" %d", *p);
    }
    printf("\n");
    return 0;
}
