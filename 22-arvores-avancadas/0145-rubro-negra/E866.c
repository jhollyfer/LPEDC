// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E866 · ★☆☆
//
// O estoque guarda os códigos de produto de 1 a 100 numa rubro-negra
// (rubronegra.h), inseridos em ordem crescente. Escreva passos(r, chave):
// quantos nós a busca visita até achar a chave ou cair num NULL. Teste com
// 1, 50, 64, 100 e 101 e, no fim, descubra o pior caso entre os 100 códigos.
//
//   Saída esperada:
//   busca   1: achou (passos: 7)
//   busca  50: achou (passos: 6)
//   busca  64: achou (passos: 1)
//   busca 100: achou (passos: 6)
//   busca 101: não achou (passos: 6)
//   pior caso entre as 100: 7 passos (altura 6)
//
// Dicas:
// 1. É a busca da BST com um contador: a cor não muda nada na busca.
// 2. Some 1 a cada nó visitado; pare quando achar ou quando r ficar NULL.
// 3. Resposta esperada: a saída acima. O 64 é a raiz: inserindo em ordem
//    crescente, a raiz cai numa potência de 2 (teste com 10 e com 1000).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "rubronegra.h"

int main(void) {

    return 0;
}
