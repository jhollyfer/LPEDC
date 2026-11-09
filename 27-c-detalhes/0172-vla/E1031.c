// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1031 · ★★★
//
// Duas lojas fazem a compra do mês de 3 produtos (arroz, feijão, café), e
// dois fornecedores, A e B, cobram preços diferentes. Multiplique a matriz
// de quantidades (lojas x produtos) pela de preços (produtos x
// fornecedores) para obter o custo de cada loja em cada fornecedor:
//
//   void multiplicar(int l, int m, int c, int a[l][m], int b[m][c], int r[l][c])
//
// Depois mostre o custo e o fornecedor mais barato para cada loja.
//
//   quantidades:  loja 1: 10, 0, 5     loja 2: 2, 8, 4
//   preços:       arroz: A 3, B 4      feijão: A 6, B 5    café: A 2, B 1
//
//   Saída esperada:
//   loja 1: A = R$ 40, B = R$ 45 -> melhor A
//   loja 2: A = R$ 62, B = R$ 52 -> melhor B
//
// Dicas:
// 1. r[i][j] é a soma, para k de 0 a m - 1, de a[i][k] * b[k][j].
// 2. As três dimensões vêm antes das matrizes. Crie r como VLA no main,
//    com int lojas = 2, fornecedores = 2.
// 3. Zere r[i][j] antes de acumular: VLA não pode ser inicializado com {0}.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
