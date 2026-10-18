// 0063 · Enum
// Exercício E373 · ★☆☆
//
// Declare o enum abaixo, com alguns valores escolhidos e outros não:
//
//   enum Tamanho { P = 1, M, G, GG = 10, XG, XXG = GG * 2, ESP };
//
// Guarde os sete tamanhos num vetor e os nomes deles num vetor de textos, e
// mostre um por linha, num laço. Depois guarde G + XG numa variável
// enum Tamanho e mostre: o C deixa, mesmo que somar tamanhos não faça
// sentido.
//
//   Saída esperada:
//   P = 1
//   M = 2
//   G = 3
//   GG = 10
//   XG = 11
//   XXG = 20
//   ESP = 21
//   G + XG = 14
//
// Dicas:
// 1. Sem valor escolhido, um nome vale o anterior + 1.
// 2. Um valor pode usar nomes que já apareceram antes: XXG = GG * 2.
// 3. const enum Tamanho tamanhos[] = {P, M, G, ...}; e
//    const char *nomes[] = {"P", "M", ...}; andam juntos pelo mesmo índice.
// 4. Resposta esperada: a saída acima. 14 não é tamanho nenhum, e o C não
//    reclama: para ele, são só inteiros.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
