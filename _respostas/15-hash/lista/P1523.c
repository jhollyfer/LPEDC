// Lista · Módulo 15 · Tabelas hash
// Exercício P1523 · ★★★ · O cadastro que duplicava pacientes
//
// Resposta: (1) a busca tratava a LAPIDE como VAZIO e desistia nela; o certo
// é parar só no VAZIO e passar reto pela lápide. (2) a inserção ocupava a
// primeira lápide sem antes conferir se a chave já existia mais adiante no
// caminho; com a lápide no meio, o 32 entrava de novo e ficava duplicado. O
// certo é buscar primeiro e só inserir se não achar.

#include <stdio.h>

#define M 11
#define VAZIO -1
#define LAPIDE -2

int busca(const int t[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == VAZIO) {
            return -1;
        }
        if (t[pos] == k) {
            return pos;
        }
    }
    return -1;
}

// devolve a posição onde k ficou, ou -1 se k já existia
int insere(int t[], int k) {
    if (busca(t, k) >= 0) {
        return -1;
    }
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == VAZIO || t[pos] == LAPIDE) {
            t[pos] = k;
            return pos;
        }
    }
    return -1;
}

void remove_chave(int t[], int k) {
    int pos = busca(t, k);
    if (pos >= 0) {
        t[pos] = LAPIDE;
    }
}

void mostra(const int t[]) {
    printf("tabela:");
    for (int i = 0; i < M; i++) {
        if (t[i] == VAZIO) {
            printf(" _");
        } else if (t[i] == LAPIDE) {
            printf(" X");
        } else {
            printf(" %d", t[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int t[M];
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }
    int fichas[] = {10, 21, 32, 43, 5};
    for (int i = 0; i < 5; i++) {
        insere(t, fichas[i]);
    }
    mostra(t);

    remove_chave(t, 21);
    printf("busca 32: %d\n", busca(t, 32));
    printf("busca 43: %d\n", busca(t, 43));
    printf("insere 32 de novo: %d\n", insere(t, 32));
    printf("insere 54: %d\n", insere(t, 54));
    mostra(t);
    return 0;
}
