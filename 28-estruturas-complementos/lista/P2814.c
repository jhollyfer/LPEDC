// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2814 · ★★☆ · Do maior para o menor com o antecessor
//
// A tabela de recordes do fliperama guarda as pontuações 5200, 3100, 8800,
// 2500, 4700, 7600, 9900, 4100 numa BST com ponteiro para o pai. Escreva
// antecessor(x) (o espelho do sucessor: com subárvore esquerda, o máximo
// dela; sem, sobe até chegar por um filho direito) e mostre o ranking, do
// maior para o menor, sem recursão: comece no máximo e ande pelo antecessor.
// Mostre também o antecessor do 4700 e do 2500.
//
//   Saída esperada:
//   ranking: 9900 8800 7600 5200 4700 4100 3100 2500
//   antes de 4700: 4100 | antes de 2500: nenhum
//
// Dicas:
// 1. for (No *x = maximo(raiz); x != NULL; x = antecessor(x)).
// 2. O 4700 tem filho esquerdo (4100): o antecessor é o máximo dele.
// 3. O 2500 é o mínimo: não tem antecessor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
