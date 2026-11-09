// Lista · Módulo 15 · Tabelas hash
// Exercício P1515 · ★★☆ · Três sondagens, as mesmas chaves

#include <stdio.h>

#define M 13
#define VAZIO -1

int linear(int k, int i) {
    return (k % M + i) % M;
}

int quadratica(int k, int i) {
    return (k % M + i * i) % M;
}

int dupla(int k, int i) {
    return (k % M + i * (1 + k % 11)) % M;
}

void testa(const char *nome, int (*sonda)(int, int), const int chaves[], int n) {
    int t[M];
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }
    int total = 0;
    for (int c = 0; c < n; c++) {
        for (int i = 0; i < M; i++) {
            int pos = sonda(chaves[c], i);
            total++;
            if (t[pos] == VAZIO) {
                t[pos] = chaves[c];
                break;
            }
        }
    }
    printf("%-10s sondagens %2d:", nome, total);
    for (int i = 0; i < M; i++) {
        if (t[i] == VAZIO) {
            printf(" _");
        } else {
            printf(" %d", t[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int chaves[] = {13, 26, 39, 52, 1, 14};
    testa("linear", linear, chaves, 6);
    testa("quadrática", quadratica, chaves, 6);
    testa("dupla", dupla, chaves, 6);
    return 0;
}
