// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2001 · ★☆☆ · A senha do painel

#include <stdio.h>

#define N 16

int chamadas;

int busca(const int v[], int ini, int fim, int x) {
    chamadas++;
    if (ini > fim) {
        return -1;
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] == x) {
        return meio;
    }
    if (x < v[meio]) {
        return busca(v, ini, meio - 1, x);
    }
    return busca(v, meio + 1, fim, x);
}

int main(void) {
    const int senhas[N] = {3, 8, 12, 15, 21, 27, 33, 40, 46, 52, 58, 64, 71, 79, 85, 90};
    const int procura[3] = {64, 3, 50};
    for (int k = 0; k < 3; k++) {
        chamadas = 0;
        int p = busca(senhas, 0, N - 1, procura[k]);
        if (p >= 0) {
            printf("Senha %d: posição %d (%d chamadas)\n", procura[k], p, chamadas);
        } else {
            printf("Senha %d: não chamada (%d chamadas)\n", procura[k], chamadas);
        }
    }
    return 0;
}
