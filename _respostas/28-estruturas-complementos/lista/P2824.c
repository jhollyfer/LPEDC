// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2824 · ★★★ · Lápides demais: hora de reconstruir

#include <stdio.h>

#define M 13

enum { LIVRE, OCUPADA, LAPIDE };

typedef struct {
    int chave, estado;
} Pos;

int busca(const Pos *t, int k, int *sondagens) {
    for (int i = 0; i < M; i++) {
        int j = (k % M + i) % M;
        *sondagens = i + 1;
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
    for (int i = 0; i < M; i++) {
        int j = (k % M + i) % M;
        if (t[j].estado != OCUPADA) {
            t[j].chave = k;
            t[j].estado = OCUPADA;
            return;
        }
    }
}

void remove_chave(Pos *t, int k) {
    int s;
    int j = busca(t, k, &s);
    if (j >= 0) {
        t[j].estado = LAPIDE;
    }
}

void mostra(const char *rotulo, const Pos *t) {
    printf("%s", rotulo);
    for (int j = 0; j < M; j++) {
        if (t[j].estado == OCUPADA) {
            printf(" %d", t[j].chave);
        } else {
            printf(" %s", t[j].estado == LIVRE ? "." : "x");
        }
    }
    printf("\n");
}

int main(void) {
    Pos t[M] = {{0, LIVRE}};
    int v[] = {1, 14, 27, 40, 53, 66};
    for (int i = 0; i < 6; i++) {
        insere(t, v[i]);
    }
    int sai[] = {14, 27, 40, 53};
    for (int i = 0; i < 4; i++) {
        remove_chave(t, sai[i]);
    }
    int s;
    busca(t, 79, &s);
    mostra("antes:  ", t);
    printf("busca 79: %d sondagens\n", s);

    Pos nova[M] = {{0, LIVRE}};
    for (int j = 0; j < M; j++) {
        if (t[j].estado == OCUPADA) {
            insere(nova, t[j].chave);
        }
    }
    busca(nova, 79, &s);
    mostra("depois: ", nova);
    printf("busca 79: %d sondagens\n", s);
    return 0;
}
