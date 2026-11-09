// Lista · Módulo 11 · Listas
// Exercício P1110 · ★☆☆ · A playlist de trás para frente, no lugar

#include <stdio.h>

#define CAP 10

typedef struct {
    int v[CAP];
    int n;
} ListaSeq;

int seq_inverte(ListaSeq *l) {
    int trocas = 0;
    for (int i = 0, j = l->n - 1; i < j; i++, j--) {
        int t = l->v[i];
        l->v[i] = l->v[j];
        l->v[j] = t;
        trocas++;
    }
    return trocas;
}

void mostra(const ListaSeq *l, int trocas) {
    printf("[");
    for (int i = 0; i < l->n; i++) {
        printf(i == 0 ? "%d" : " %d", l->v[i]);
    }
    printf("] em %d trocas\n", trocas);
}

int main(void) {
    ListaSeq treino = {{11, 22, 33, 44, 55, 66, 77}, 7};
    ListaSeq curta = {{1, 2, 3, 4}, 4};
    int t = seq_inverte(&treino);
    mostra(&treino, t);
    t = seq_inverte(&curta);
    mostra(&curta, t);
    return 0;
}
