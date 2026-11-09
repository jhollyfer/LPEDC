// Lista · Módulo 14 · Árvores
// Exercício P1416 · ★★☆ · A fila de prioridade da impressora

#include <stdio.h>

typedef struct {
    char dono[10];
    int prioridade; // 1 = mais urgente
    int chegada;
} Trabalho;

// a vem antes de b? menor prioridade; no empate, quem chegou antes
int antes(const Trabalho *a, const Trabalho *b) {
    if (a->prioridade != b->prioridade) {
        return a->prioridade < b->prioridade;
    }
    return a->chegada < b->chegada;
}

void troca(Trabalho *a, Trabalho *b) {
    Trabalho t = *a;
    *a = *b;
    *b = t;
}

void insere(Trabalho h[], int *n, Trabalho t) {
    int i = (*n)++;
    h[i] = t;
    while (i > 0 && antes(&h[i], &h[(i - 1) / 2])) {
        troca(&h[i], &h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Trabalho extrai(Trabalho h[], int *n) {
    Trabalho topo = h[0];
    h[0] = h[--(*n)];
    int i = 0;
    while (2 * i + 1 < *n) {
        int f = 2 * i + 1;
        if (f + 1 < *n && antes(&h[f + 1], &h[f])) {
            f++;
        }
        if (!antes(&h[f], &h[i])) {
            break;
        }
        troca(&h[i], &h[f]);
        i = f;
    }
    return topo;
}

int main(void) {
    Trabalho chegam[] = {
        {"Caixa", 3, 1}, {"Gerente", 1, 2}, {"RH", 2, 3},
        {"Vendas", 3, 4}, {"Diretor", 1, 5}, {"Estoque", 2, 6},
    };
    Trabalho heap[10];
    int n = 0;

    for (int i = 0; i < 6; i++) {
        insere(heap, &n, chegam[i]);
    }
    printf("ordem de impressão:\n");
    while (n > 0) {
        Trabalho t = extrai(heap, &n);
        printf("  %-8s prioridade %d, chegou em %d\n", t.dono, t.prioridade, t.chegada);
    }
    return 0;
}
