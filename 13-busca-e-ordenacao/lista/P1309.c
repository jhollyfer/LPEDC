// Lista · Módulo 13 · Busca e ordenação
// Exercício P1309 · ★☆☆ · A busca binária que esquece a ponta
//
// A secretaria procura matrículas num vetor ordenado com a busca binária
// abaixo, que tem um erro de propósito: ela não acha algumas matrículas que
// estão lá. Rode, veja quais falham e conserte (é uma mudança pequena).
//
//   Saída esperada (depois do conserto):
//   10: 0
//   47: 3
//   98: 7
//   60: -1
//
// Dicas:
// 1. Antes do conserto, o 10 e o 98 dão -1. Os dois são pontas do vetor.
// 2. O intervalo é fechado: [ini, fim] inclui as duas pontas. Quando
//    ini == fim, ainda sobra uma posição para olhar.
// 3. Resposta esperada: a condição do while deve ser ini <= fim; aí a saída
//    fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int busca(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini < fim) {
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
