// Lista · Módulo 06 · Ponteiros
// Exercício P0620 · ★★☆ · Três ordens para o mesmo vetor

#include <stdio.h>
#include <stdlib.h>

int crescente(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return (x > y) - (x < y);
}

int decrescente(const void *a, const void *b) {
    return crescente(b, a); // inverter os argumentos inverte a ordem
}

int pares_primeiro(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    int gx = x % 2, gy = y % 2; // 0 = par, 1 = ímpar
    if (gx != gy) {
        return gx - gy;
    }
    return crescente(a, b);
}

void ordenar_e_mostrar(const char *nome, const int *orig, int n,
                       int (*cmp)(const void *, const void *)) {
    int v[8];
    for (int i = 0; i < n; i++) {
        v[i] = orig[i];
    }
    qsort(v, n, sizeof v[0], cmp);
    printf("%-15s", nome);
    for (int i = 0; i < n; i++) {
        printf(" %2d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int sorteados[8] = {47, 12, 85, 30, 9, 66, 21, 58};

    ordenar_e_mostrar("Crescente:", sorteados, 8, crescente);
    ordenar_e_mostrar("Decrescente:", sorteados, 8, decrescente);
    ordenar_e_mostrar("Pares primeiro:", sorteados, 8, pares_primeiro);
    return 0;
}
