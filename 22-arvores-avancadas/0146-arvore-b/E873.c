// 0146 · Árvore B
// Exercício E873 · ★★☆
//
// No disco, cada nó da árvore B ocupa um bloco inteiro, cheio ou não. A
// ocupação é a fração das vagas de chave que estão em uso:
// chaves / (nós · AB_MAX). Monte duas árvores com as chaves de 1 a 200: uma
// inserindo em ordem crescente e outra na ordem embaralhada i * 37 % 200 + 1
// (i de 0 a 199, que passa por todos os números de 1 a 200 uma vez só).
// Escreva mede(r, &chaves, &nos), que soma as chaves e os nós de uma árvore,
// e mostre nós, altura e ocupação de cada uma.
//
//   Saída esperada:
//   crescente:   nós 195 | altura 6 | ocupação 34.2%
//   embaralhada: nós 127 | altura 5 | ocupação 52.5%
//
// Dicas:
// 1. mede é um percurso: some r->n em *chaves, 1 em *nos e desça pelos
//    filhos de 0 a r->n se não for folha.
// 2. Faça a conta em double: 100.0 * chaves / (nos * AB_MAX). Para imprimir
//    o símbolo de porcentagem no printf, escreva %%.
// 3. Resposta esperada: a saída acima. Na ordem crescente, todo nó que se
//    divide deixa a metade esquerda com 1 chave para sempre: ninguém mais
//    insere ali.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "arvoreb.h"

int main(void) {

    return 0;
}
