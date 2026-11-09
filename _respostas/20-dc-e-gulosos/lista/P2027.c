// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2027 · ★★★ · Quantos passaram?

#include <stdio.h>

#define N 10

// procura em v[ini..fim]; fim == ini quer dizer "é este índice"
int primeira(const int v[], int ini, int fim, int x) {
    if (ini == fim) {
        return ini;
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] >= x) {
        return primeira(v, ini, meio, x);
    }
    return primeira(v, meio + 1, fim, x);
}

int main(void) {
    const int nota[N] = {35, 40, 50, 60, 70, 70, 70, 85, 90, 100};
    const int corte[3] = {70, 50, 101};
    for (int i = 0; i < 3; i++) {
        int p = primeira(nota, 0, N, corte[i]); // N é a resposta "nenhum"
        printf("Corte %d: %d aprovados\n", corte[i], N - p);
    }
    return 0;
}
