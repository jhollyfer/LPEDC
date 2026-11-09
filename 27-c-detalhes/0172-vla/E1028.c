// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1028 · ★☆☆
//
// Uma rede tem 3 lojas, e a matriz guarda as vendas (em mil reais) de cada
// loja em cada trimestre. Escreva, com a matriz como parâmetro VLA:
//
//   int soma_linha(int l, int c, int m[l][c], int i)   // total da loja i
//   int soma_coluna(int l, int c, int m[l][c], int j)  // total do trimestre j
//
// e mostre o total de cada loja e de cada trimestre.
//
//   Saída esperada:
//   loja 1: 100
//   loja 2: 80
//   loja 3: 32
//   trimestre 1: 23
//   trimestre 2: 43
//   trimestre 3: 63
//   trimestre 4: 83
//
// Dicas:
// 1. Uma matriz comum int m[3][4] pode ser passada para um parâmetro VLA:
//    soma_linha(3, 4, vendas, 0).
// 2. As dimensões vêm antes da matriz na lista de parâmetros.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int vendas[3][4] = {
        {10, 20, 30, 40},
        {5, 15, 25, 35},
        {8, 8, 8, 8},
    };
    (void)vendas; // apague esta linha
    return 0;
}
