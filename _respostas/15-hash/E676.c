// 0113 · Juntando tudo: o contador de palavras
// Exercício E676 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *palavra;
    int vezes;
} Contagem;

int compara(const void *a, const void *b) {
    const Contagem *x = a;
    const Contagem *y = b;
    if (x->vezes != y->vezes) {
        return y->vezes - x->vezes; // mais vezes primeiro
    }
    return strcmp(x->palavra, y->palavra); // empate: ordem alfabética
}

int main(void) {
    Contagem lista[] = {{"feira", 3}, {"banana", 5}, {"alface", 3},
                        {"ovo", 5},   {"queijo", 1}, {"caqui", 3}};
    int n = (int)(sizeof lista / sizeof lista[0]);

    qsort(lista, (size_t)n, sizeof lista[0], compara);
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", lista[i].palavra, lista[i].vezes);
    }
    return 0;
}
