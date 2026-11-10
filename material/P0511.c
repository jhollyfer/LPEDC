// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0511 · ★★☆ · Quanto custa cada receita em cada mercado
//
// Uma doceira faz duas receitas. A matriz q (2x3) diz quantos quilos de cada
// ingrediente cada receita usa (colunas: farinha, açúcar, chocolate), e a
// matriz p (3x2) diz o preço do quilo de cada ingrediente em dois mercados:
//
//   double q[2][3] = {{2.0, 1.0, 0.5},    // bolo
//                     {1.0, 0.5, 1.0}};   // brigadeirão
//   double p[3][2] = {{5.50, 4.90},       // farinha: mercado A, B
//                     {4.20, 4.80},       // açúcar
//                     {38.00, 41.50}};    // chocolate
//
// O custo de cada receita em cada mercado é o produto c = q x p (2x2):
// c[i][j] = soma de q[i][k] * p[k][j], para k de 0 a 2. Escreva a função
//
//   void multiplicar(double a[2][3], double b[3][2], double c[2][2]);
//
// e mostre o resultado, dizendo o mercado mais barato para cada receita:
//
//   Saída esperada:
//   Bolo: A = R$ 34.20, B = R$ 35.35 -> mais barato no A
//   Brigadeirão: A = R$ 45.60, B = R$ 48.80 -> mais barato no A
//
// Dicas:
// 1. Três for aninhados: i (linhas de q), j (colunas de p) e k (o índice
//    que "anda junto": coluna de q e linha de p).
// 2. Zere c[i][j] antes do laço em k e acumule com +=.
// 3. Uma matriz 2x3 só pode ser multiplicada por uma que tem 3 linhas: o
//    número de colunas da primeira tem que ser o de linhas da segunda.
// 4. Resposta esperada: bolo R$ 34.20 x R$ 35.35 (A) e brigadeirão
//    R$ 45.60 x R$ 48.80 (A).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    double q[2][3] = {{2.0, 1.0, 0.5},    // bolo
                      {1.0, 0.5, 1.0}};   // brigadeirão
    double p[3][2] = {{5.50, 4.90},       // farinha: mercado A, B
                      {4.20, 4.80},       // açúcar
                      {38.00, 41.50}};    // chocolate
    (void) q, (void) p; // apague esta linha quando escrever

    return 0;
}
