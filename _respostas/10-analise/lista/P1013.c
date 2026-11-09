// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1013 · ★★☆ · Busca binária com o invariante à vista

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// x não aparece em v[0..ini-1] nem em v[fim+1..n-1]
bool fora_ausente(const int v[], int n, int ini, int fim, int x) {
    for (int i = 0; i < ini; i++) {
        if (v[i] == x) {
            return false;
        }
    }
    for (int i = fim + 1; i < n; i++) {
        if (v[i] == x) {
            return false;
        }
    }
    return true;
}

int busca(const int v[], int n, int x, int *passos) {
    int ini = 0, fim = n - 1;
    *passos = 0;
    while (ini <= fim) {
        assert(fora_ausente(v, n, ini, fim, x)); // invariante
        (*passos)++;
        int meio = (ini + fim) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    assert(ini > fim && fora_ausente(v, n, ini, fim, x)); // término: x não está
    return -1;
}

int main(void) {
    int senhas[10] = {3, 8, 15, 21, 29, 34, 42, 50, 57, 63};
    int procuradas[3] = {42, 3, 60};
    for (int k = 0; k < 3; k++) {
        int passos;
        int pos = busca(senhas, 10, procuradas[k], &passos);
        if (pos >= 0) {
            printf("%d: posição %d (%d passos)\n", procuradas[k], pos, passos);
        } else {
            printf("%d: não está (%d passos)\n", procuradas[k], passos);
        }
    }
    return 0;
}
