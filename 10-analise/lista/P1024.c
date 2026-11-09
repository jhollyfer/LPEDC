// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1024 · ★★★ · A busca em escada na tabela de preços
//
// A tabela de fretes tem as linhas (distâncias) e as colunas (pesos) em
// ordem crescente: cada linha cresce para a direita e cada coluna cresce
// para baixo.
//
//    2  5  9 14 20
//    4  8 13 18 25
//    7 11 16 22 30
//   10 15 21 27 35
//
// Escreva bool escada(int m[4][5], int x, int *lin, int *col, int *comp),
// que começa no canto de CIMA À DIREITA: se o valor é maior que x, a coluna
// inteira dali para baixo também é, então vá para a esquerda; se é menor,
// a linha inteira dali para a esquerda também é, então desça. Escreva
// também a força bruta (linha por linha, parando ao achar) e compare as
// comparações para x = 16 e x = 17.
//
//   Saída esperada:
//   16: linha 2, coluna 2 (escada: 5 comparações, força bruta: 13)
//   17: não está (escada: 7 comparações, força bruta: 20)
//
// Dicas:
// 1. Invariante da escada: se x está na matriz, está nas linhas i..3 e nas
//    colunas 0..j. Cada passo descarta uma linha ou uma coluna inteira.
// 2. O laço é while (i < 4 && j >= 0); conte 1 comparação por volta.
// 3. Com L linhas e C colunas, a escada faz no máximo L + C - 1
//    comparações, O(L + C), contra O(L · C) da força bruta.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
