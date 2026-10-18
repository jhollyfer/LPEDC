// 0063 · Enum
// Exercício E373 · ★☆☆
//
// Preveja o valor de cada nome e o resultado do último printf:
//
//   enum Tamanho { P = 1, M, G, GG = 10, XG, XXG = GG * 2, ESP };
//
//   printf("%d %d %d %d %d %d %d\n", P, M, G, GG, XG, XXG, ESP);
//   printf("%d\n", G + XG);
//
// Dicas:
// 1. Sem valor escolhido, um nome vale o anterior + 1.
// 2. Um valor pode usar nomes que já apareceram antes: XXG = GG * 2.
// 3. Resposta esperada: "1 2 3 10 11 20 21" e 14. Somar tamanhos não faz
//    sentido, mas compila: para o C, são só inteiros.
//
// Escreva sua resposta abaixo (como comentário; depois confira no main):

#include <stdio.h>

int main(void) {

    return 0;
}
