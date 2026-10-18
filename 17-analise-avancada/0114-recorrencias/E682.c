// 0114 · Recorrências e árvore de recursão
// Exercício E682 · ★★☆
//
// Escreva do zero um selection sort RECURSIVO, sem laço externo:
// ordena(v, n) procura o maior de v[0..n-1], troca com v[n-1] e chama
// ordena(v, n - 1). Cada chamada mostra quantas comparações fez, e o main
// mostra o total e o vetor ordenado. Os preços são:
//
//   42 17 88 5 63 29 71 10
//
//   Saída esperada:
//   ordena(8): 7 comparações
//   ordena(7): 6 comparações
//   ordena(6): 5 comparações
//   ordena(5): 4 comparações
//   ordena(4): 3 comparações
//   ordena(3): 2 comparações
//   ordena(2): 1 comparação
//   total: 28 = 8 · 7 / 2
//   5 10 17 29 42 63 71 88
//
// Dicas:
// 1. Caso base: com n <= 1 não há o que fazer.
// 2. A recorrência é T(n) = T(n-1) + (n - 1), com T(1) = 0. A árvore de
//    recursão vira uma linha: 7 + 6 + ... + 1.
// 3. Some as comparações num contador global para o total.
// 4. Resposta esperada: a saída acima. Para n = 1000 seriam 499.500
//    comparações: Θ(n²), mesmo sem nenhum laço aninhado no código. A
//    recursão faz o papel do laço de fora.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
