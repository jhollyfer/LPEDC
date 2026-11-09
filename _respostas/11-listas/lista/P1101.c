// Lista · Módulo 11 · Listas
// Exercício P1101 · ★☆☆ · Encaixar uma música no meio da playlist

#include <stdbool.h>
#include <stdio.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int n;
} ListaSeq;

int deslocamentos = 0;

bool seq_insere(ListaSeq *l, int pos, int codigo) {
    if (l->n == CAP || pos < 0 || pos > l->n) {
        return false;
    }
    for (int i = l->n; i > pos; i--) {
        l->v[i] = l->v[i - 1];
        deslocamentos++;
    }
    l->v[pos] = codigo;
    l->n++;
    return true;
}

void seq_imprime(const ListaSeq *l) {
    printf("[");
    for (int i = 0; i < l->n; i++) {
        printf(i == 0 ? "%d" : " %d", l->v[i]);
    }
    printf("]\n");
}

int main(void) {
    ListaSeq festa = {.n = 0};
    seq_insere(&festa, 0, 10);
    seq_insere(&festa, 1, 30);
    seq_insere(&festa, 1, 20);
    seq_insere(&festa, 0, 5);
    bool ok = seq_insere(&festa, 9, 99);
    seq_imprime(&festa);
    printf("Inserir na posição 9: %s\n", ok ? "aceito" : "recusado");
    printf("Deslocamentos: %d\n", deslocamentos);
    return 0;
}
