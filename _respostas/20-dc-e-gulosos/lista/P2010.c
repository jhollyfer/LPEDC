// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2010 · ★☆☆ · A poltrona com o próprio número

#include <stdio.h>

#define N 10

int chamadas = 0;

int pos_fixa(const int v[], int ini, int fim) {
    chamadas++;
    if (ini > fim) {
        return -1;
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] == meio) {
        return meio;
    }
    if (v[meio] < meio) {
        return pos_fixa(v, meio + 1, fim);
    }
    return pos_fixa(v, ini, meio - 1);
}

int main(void) {
    const int v[N] = {-5, -2, 0, 1, 2, 5, 9, 12, 15, 18};
    int p = pos_fixa(v, 0, N - 1);
    if (p >= 0) {
        printf("Posição %d: v[%d] = %d\n", p, p, v[p]);
    } else {
        printf("Nenhuma posição fixa\n");
    }
    printf("Chamadas: %d\n", chamadas);
    return 0;
}
