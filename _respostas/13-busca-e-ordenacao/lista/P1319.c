// Lista · Módulo 13 · Busca e ordenação
// Exercício P1319 · ★★☆ · Busca binária no ranking decrescente

#include <stdio.h>

// v está em ordem DECRESCENTE
int busca(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] > x) { // o meio é maior: x está mais para a direita
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int pontos[] = {980, 875, 870, 720, 650, 610, 455, 300};
    int n = 8;
    int consultas[] = {650, 980, 300, 500};

    for (int k = 0; k < 4; k++) {
        int pos = busca(pontos, n, consultas[k]);
        if (pos >= 0) {
            printf("%d pontos: %dº lugar\n", consultas[k], pos + 1);
        } else {
            printf("%d pontos: ninguém\n", consultas[k]);
        }
    }
    return 0;
}
