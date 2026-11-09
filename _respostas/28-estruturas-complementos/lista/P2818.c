// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2818 · ★★☆ · A classificação da corrida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[12];
    int tempo, idade;
} Atleta;

int compara(const void *a, const void *b) {
    const Atleta *x = a;
    const Atleta *y = b;
    if (x->tempo != y->tempo) {
        return x->tempo - y->tempo;
    }
    if (x->idade != y->idade) {
        return y->idade - x->idade;
    }
    return strcmp(x->nome, y->nome);
}

int main(void) {
    Atleta v[] = {{"Lia", 1520, 34}, {"Davi", 1490, 28}, {"Rita", 1520, 41},
                  {"Caio", 1490, 28}, {"Bia", 1610, 22},  {"Teo", 1520, 41}};
    qsort(v, 6, sizeof(Atleta), compara);
    for (int i = 0; i < 6; i++) {
        printf("%d. %-5s %d:%02d  %d anos\n", i + 1, v[i].nome, v[i].tempo / 60, v[i].tempo % 60,
               v[i].idade);
    }
    return 0;
}
