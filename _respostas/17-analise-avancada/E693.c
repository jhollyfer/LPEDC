// 0116 · Análise amortizada
// Exercício E693 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n, cap;
    long copias;
    int mudancas;
} Vetor;

// cresce para nova = cap * num / den, mas sempre pelo menos 1 a mais:
// com cap = 1 e fator 1,5, 1 * 3 / 2 dá 1 e o vetor não cresceria
void insere(Vetor *v, int valor, int num, int den) {
    if (v->n == v->cap) {
        int nova = (int)((long)v->cap * num / den);
        if (nova <= v->cap) {
            nova = v->cap + 1;
        }
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
        v->mudancas++;
    }
    v->dados[v->n++] = valor;
}

void testa(const char *nome, int num, int den, int n) {
    Vetor v = {malloc(sizeof(int)), 0, 1, 0, 0};
    if (v.dados == NULL) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        insere(&v, i, num, den);
    }
    printf("%-6s %8d %10ld %8.2f %9d\n", nome, v.mudancas, v.copias, (double)v.copias / n, v.cap - v.n);
    free(v.dados);
}

int main(void) {
    int n = 1000000;
    printf("fator  mudanças    cópias  cópias/n     sobra\n");
    testa("x 1,5", 3, 2, n);
    testa("x 2", 2, 1, n);
    return 0;
}
