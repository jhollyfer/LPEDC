// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2813 · ★★☆ · A lápide no meio do caminho

#include <stdbool.h>
#include <stdio.h>

#define M 7

enum { LIVRE, OCUPADA, LAPIDE };

typedef struct {
    int chave, estado;
} Pos;

int busca(const Pos *t, int k) {
    for (int i = 0; i < M; i++) {
        int j = (k % M + i) % M;
        if (t[j].estado == LIVRE) {
            return -1;
        }
        if (t[j].estado == OCUPADA && t[j].chave == k) {
            return j;
        }
    }
    return -1;
}

void insere(Pos *t, int k) {
    if (busca(t, k) >= 0) {
        return;
    }
    int lapide = -1;
    for (int i = 0; i < M; i++) {
        int j = (k % M + i) % M;
        if (t[j].estado == LAPIDE && lapide < 0) {
            lapide = j;
        }
        if (t[j].estado == LIVRE) {
            int alvo = lapide >= 0 ? lapide : j;
            t[alvo].chave = k;
            t[alvo].estado = OCUPADA;
            return;
        }
    }
    if (lapide >= 0) {
        t[lapide].chave = k;
        t[lapide].estado = OCUPADA;
    }
}

void remove_chave(Pos *t, int k) {
    int j = busca(t, k);
    if (j >= 0) {
        t[j].estado = LAPIDE;
    }
}

void mostra(const char *passo, const Pos *t) {
    printf("%-11s", passo);
    for (int j = 0; j < M; j++) {
        if (t[j].estado == OCUPADA) {
            printf(" %2d", t[j].chave);
        } else {
            printf(" %2s", t[j].estado == LIVRE ? "." : "x");
        }
    }
    printf("\n");
}

int main(void) {
    Pos t[M] = {{0, LIVRE}};
    int v[] = {10, 17, 24, 5};
    for (int i = 0; i < 4; i++) {
        insere(t, v[i]);
    }
    mostra("inseridos:", t);
    remove_chave(t, 17);
    mostra("tira 17:", t);
    int j = busca(t, 24);
    printf("busca 24: posição %d\n", j);
    insere(t, 31);
    mostra("insere 31:", t);
    return 0;
}
