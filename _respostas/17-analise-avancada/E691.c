// 0116 · Análise amortizada
// Exercício E691 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n, cap;
    long copias; // total de cópias feitas pelas mudanças
} Vetor;

void insere(Vetor *v, int valor) {
    if (v->n == v->cap) {
        int nova = v->cap * 2;
        int *maior = malloc(nova * sizeof *maior);
        if (maior == NULL) {
            exit(1);
        }
        for (int i = 0; i < v->n; i++) {
            maior[i] = v->dados[i];
            v->copias++;
        }
        free(v->dados);
        v->dados = maior;
        v->cap = nova;
    }
    v->dados[v->n++] = valor;
}

int main(void) {
    int tamanhos[] = {10, 100, 1000, 1000000};
    printf("      n    cópias  cópias/n\n");
    for (int t = 0; t < 4; t++) {
        Vetor v = {malloc(sizeof(int)), 0, 1, 0};
        if (v.dados == NULL) {
            return 1;
        }
        for (int i = 0; i < tamanhos[t]; i++) {
            insere(&v, i);
        }
        printf("%7d %9ld %9.2f\n", tamanhos[t], v.copias, (double)v.copias / tamanhos[t]);
        free(v.dados);
    }
    return 0;
}
