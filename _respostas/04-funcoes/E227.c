// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E227 · ★★★

#include <stdio.h>

int multiplicacoes = 0;

long long pot_lenta(long long x, int e) {
    if (e == 0) {
        return 1;
    }
    multiplicacoes++;
    return x * pot_lenta(x, e - 1);
}

long long pot_rapida(long long x, int e) {
    if (e == 0) {
        return 1;
    }
    if (e % 2 == 0) {
        long long metade = pot_rapida(x, e / 2);
        multiplicacoes++;
        return metade * metade;
    }
    multiplicacoes++;
    return x * pot_rapida(x, e - 1);
}

void comparar(long long x, int e) {
    multiplicacoes = 0;
    long long r = pot_lenta(x, e);
    printf("lenta:  %lld^%d = %lld (%d multiplicações)\n", x, e, r, multiplicacoes);
    multiplicacoes = 0;
    r = pot_rapida(x, e);
    printf("rápida: %lld^%d = %lld (%d multiplicações)\n", x, e, r, multiplicacoes);
}

int main(void) {
    comparar(3, 13);
    comparar(2, 60);
    return 0;
}
