// Lista · Módulo 15 · Tabelas hash
// Exercício P1519 · ★★☆ · Medindo os blocos da sondagem linear
//
// Insira 27, 40, 2, 15, 8, 21, 34, 50, 11 numa tabela de m = 13 com sondagem
// linear (h(k) = k % 13) e meça o AGRUPAMENTO PRIMÁRIO: mostre a tabela, cada
// bloco de posições ocupadas seguidas (com a posição onde começa e o
// tamanho) e o maior bloco. Um bloco pode dar a volta no fim da tabela.
//
//   Saída esperada:
//   tabela: _ 27 40 2 15 _ _ _ 8 21 34 50 11
//   bloco começando em 1, tamanho 4
//   bloco começando em 8, tamanho 5
//   maior bloco: 5
//
// Dicas:
// 1. Uma posição i começa um bloco se está ocupada e a anterior,
//    (i - 1 + M) % M, está vazia.
// 2. Para não cortar um bloco que dá a volta, comece a varredura logo depois
//    de uma posição vazia e ande M posições com % M.
// 3. O 11 (h = 11) e o 50 (h = 11) acabaram grudados no bloco do 8 e do 21:
//    blocos grandes atraem mais chaves, e a busca dentro deles fica cara.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 13
#define VAZIO -1

int main(void) {

    return 0;
}
