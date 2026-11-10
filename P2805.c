// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2805 · ★☆☆ · O fator de cada nó
//
// Ainda com a árvore do P2803 (60, 30, 90, 20, 45, 75, 40, 50, 95), mostre
// em ordem cada chave com o seu fator de balanceamento, altura(esq) -
// altura(dir), e diga no fim se a árvore é AVL (todo fator em -1, 0 ou 1).
// Depois insira 55 e repita.
//
//   Saída esperada:
//   fatores: 20(0) 30(-1) 40(0) 45(0) 50(0) 60(1) 75(0) 90(0) 95(0)
//   é AVL
//   fatores: 20(0) 30(-2) 40(0) 45(-1) 50(-1) 55(0) 60(2) 75(0) 90(0) 95(0)
//   não é AVL
//
// Dicas:
// 1. O fator de uma folha é (-1) - (-1) = 0.
// 2. Uma flag global ou um ponteiro para bool marca se algum fator saiu de
//    -1..1.
// 3. O 55 entra à direita do 50 e desequilibra o 30 e o 60.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
