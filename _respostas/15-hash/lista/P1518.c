// Lista · Módulo 15 · Tabelas hash
// Exercício P1518 · ★★☆ · O produto mais vendido do dia

#include <stdio.h>

#define M 23
#define VAZIO -1

int codigo[M], vendas[M];

void registra(int k) {
    int pos = k % M;
    while (codigo[pos] != VAZIO && codigo[pos] != k) {
        pos = (pos + 1) % M;
    }
    codigo[pos] = k;
    vendas[pos]++;
}

int main(void) {
    int caixa[] = {78912, 55301, 78912, 10450, 55301, 78912, 33017, 10450,
                   55301, 55301, 90008, 78912, 55301, 33017};
    int n = 14;
    for (int i = 0; i < M; i++) {
        codigo[i] = VAZIO;
        vendas[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        registra(caixa[i]);
    }

    int melhor = -1, distintos = 0;
    for (int i = 0; i < M; i++) {
        if (codigo[i] != VAZIO) {
            distintos++;
            printf("%d: vendas %d\n", codigo[i], vendas[i]);
            if (melhor < 0 || vendas[i] > vendas[melhor]) {
                melhor = i;
            }
        }
    }
    printf("%d produtos distintos; mais vendido: %d (%d vendas)\n", distintos, codigo[melhor], vendas[melhor]);
    return 0;
}
