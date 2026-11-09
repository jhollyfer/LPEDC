// Lista · Módulo 13 · Busca e ordenação
// Exercício P1309 · ★☆☆ · A busca binária que esquece a ponta
//
// Resposta: com o intervalo fechado [ini, fim], o laço precisa continuar
// enquanto ini <= fim. Com ini < fim, quando sobra uma posição só (ini ==
// fim) o laço para sem olhar para ela, e o 98 (a última) some.

#include <stdio.h>

int busca(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int matriculas[] = {10, 23, 35, 47, 52, 66, 71, 98};
    int n = 8;
    int testes[] = {10, 47, 98, 60};

    for (int k = 0; k < 4; k++) {
        printf("%d: %d\n", testes[k], busca(matriculas, n, testes[k]));
    }
    return 0;
}
