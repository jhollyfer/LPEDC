// 0116 · Análise amortizada
// Exercício E696 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n, cap;
    long copias;
} Vetor;

// troca o vetor por um de capacidade nova, copiando os n elementos
void muda(Vetor *v, int nova) {
    int *outro = malloc(nova * sizeof *outro);
    if (outro == NULL) {
        exit(1);
    }
    for (int i = 0; i < v->n; i++) {
        outro[i] = v->dados[i];
        v->copias++;
    }
    free(v->dados);
    v->dados = outro;
    v->cap = nova;
}

void insere(Vetor *v, int x) {
    if (v->n == v->cap) {
        muda(v, 2 * v->cap);
    }
    v->dados[v->n++] = x;
}

int remove_ultimo(Vetor *v) {
    int x = v->dados[--v->n];
    if (v->cap > 1 && v->n == v->cap / 4) {
        muda(v, v->cap / 2);              // só com um quarto: encolhe pela metade
    }
    return x;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1, 0};
    if (v.dados == NULL) {
        return 1;
    }
    for (int i = 0; i < 16; i++) {
        insere(&v, i);
    }
    printf("16 inserções: %ld cópias (cap %d)\n", v.copias, v.cap);

    v.copias = 0;
    for (int i = 0; i < 500; i++) {       // põe e tira o mesmo item
        insere(&v, 99);
        remove_ultimo(&v);
    }
    printf("1000 operações alternadas: %ld cópias (cap %d)\n", v.copias, v.cap);

    v.copias = 0;
    while (v.n > 0) {
        remove_ultimo(&v);
    }
    printf("esvaziar: %ld cópias (cap %d)\n", v.copias, v.cap);
    free(v.dados);
    return 0;
}
