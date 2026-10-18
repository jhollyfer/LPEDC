// 0161 · Juntando tudo
// Exercício E966 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "padroes.h"

typedef struct {
    const char *palavra;
    int vezes;
} Contagem;

// mais vezes primeiro; empate em ordem alfabética
int compara(const void *a, const void *b) {
    const Contagem *x = a;
    const Contagem *y = b;
    if (x->vezes != y->vezes) {
        return (y->vezes > x->vezes) - (y->vezes < x->vezes);
    }
    return strcmp(x->palavra, y->palavra);
}

int main(void) {
    const char *narracao =
        "gol! a bola bateu na trave, o juiz deu falta, a bola voltou e foi gol "
        "de novo; falta na entrada da area, bola na trave e gol";
    Contagem lista[] = {{"gol", 0}, {"bola", 0}, {"juiz", 0}, {"falta", 0}, {"trave", 0}};
    int k = sizeof lista / sizeof lista[0];
    int n = (int) strlen(narracao);
    long comp = 0;

    for (int i = 0; i < k; i++) {
        lista[i].vezes = pb_horspool(narracao, n, lista[i].palavra,
                                     (int) strlen(lista[i].palavra), NULL, 0, &comp);
    }
    qsort(lista, (size_t) k, sizeof lista[0], compara);
    for (int i = 0; i < k; i++) {
        printf("%dº %-5s %d\n", i + 1, lista[i].palavra, lista[i].vezes);
    }
    printf("(%ld comparações de letra no total)\n", comp);
    return 0;
}
