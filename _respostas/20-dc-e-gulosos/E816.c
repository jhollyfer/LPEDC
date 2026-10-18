// 0136 · Código de Huffman
// Exercício E816 · ★★★

#include <stdio.h>

#define N 8

int main(void) {
    int folha[N] = {1, 1, 2, 3, 5, 8, 13, 21}; // já em ordem crescente
    int interno[N];                           // os nós criados, em ordem de criação
    int f = 0;                                // próxima folha
    int ini = 0, fim = 0;                     // fila dos internos: [ini, fim)
    long total = 0;

    // pega o menor entre a frente das folhas e a frente dos internos
    for (int juncao = 0; juncao < N - 1; juncao++) {
        int par[2];
        for (int t = 0; t < 2; t++) {
            if (f < N && (ini == fim || folha[f] <= interno[ini])) {
                par[t] = folha[f++];
            } else {
                par[t] = interno[ini++];
            }
        }
        interno[fim++] = par[0] + par[1]; // sai em ordem crescente: basta enfileirar
        total += par[0] + par[1];
        printf("junta %2d + %2d = %2d\n", par[0], par[1], par[0] + par[1]);
    }
    printf("Total: %ld bits\n", total);
    return 0;
}
