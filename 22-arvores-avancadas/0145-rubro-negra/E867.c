// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E867 · ★★☆
//
// Escreva confere(r), o fiscal da rubro-negra esquerdista. Ela devolve a altura
// preta (quantos nós pretos há da raiz até um NULL) se as três regras valerem,
// ou um código negativo com a primeira regra quebrada que achar:
//
//   -1: um link vermelho à direita;
//   -2: dois vermelhos seguidos (um vermelho com filho esquerdo vermelho);
//   -3: dois caminhos com quantidades diferentes de nós pretos.
//
// Teste com quatro árvores: a do TAD (rubronegra.h) com as chaves de 1 a 20 e
// três montadas à mão com malloc (escreva uma função no(chave, vermelho, esq,
// dir)), cada nó dado como chave/cor:
//
//   A: 20 preto, filho esquerdo 10 preto, filho direito 30 vermelho
//   B: 30 preto, esquerdo 20 vermelho (com filho esquerdo 10 vermelho),
//      direito 40 preto
//   C: 20 preto, esquerdo 10 preto (com filho esquerdo 5 preto),
//      direito 30 preto sem filhos
//
//   Saída esperada:
//   TAD (1 a 20): ok, altura preta 4
//   Árvore A: quebra a regra 1
//   Árvore B: quebra a regra 2
//   Árvore C: quebra a regra 3
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"

int main(void) {

    return 0;
}
