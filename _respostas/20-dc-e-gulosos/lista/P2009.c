// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2009 · ★☆☆ · Quando a razão engana

#include <stdio.h>

#define N 3
#define CAP 50

const char *nome[N] = {"TV", "som", "PC"};
const int peso[N] = {10, 20, 30};
const int valor[N] = {600, 1000, 1200};

int guloso(void) {
    int livre = CAP, total = 0;
    for (int i = 0; i < N; i++) { // os itens já estão por razão decrescente
        if (peso[i] <= livre) {
            livre -= peso[i];
            total += valor[i];
        }
    }
    return total;
}

int otimo(void) {
    int melhor = 0;
    for (int m = 0; m < (1 << N); m++) {
        int p = 0, v = 0;
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) {
                p += peso[i];
                v += valor[i];
            }
        }
        if (p <= CAP && v > melhor) {
            melhor = v;
        }
    }
    return melhor;
}

int main(void) {
    printf("Guloso pela razão: R$ %d\n", guloso());
    printf("Ótimo (força bruta): R$ %d\n", otimo());
    return 0;
}
