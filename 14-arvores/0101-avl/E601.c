// 0101 · AVL: balanceamento e rotações
// Exercício E601 · ★☆☆
//
// Monte à mão esta árvore binária, sem campo de altura (struct Arv: chave,
// esq, dir):
//
//   50
//   ├── esq: 30
//   │   ├── esq: 20
//   │   │   └── esq: 10
//   │   └── dir: 40
//   └── dir: 70
//       └── dir: 80
//           └── dir: 90
//
// Escreva altura(r) e relatorio(r). A relatorio mostra, em pré-ordem, a
// altura e o fator de balanceamento (altura da esquerda menos altura da
// direita) de cada nó, marca com "<- desequilibrado" quem tem fator fora de
// -1..1 e devolve quantos nós estão assim. O main diz se a árvore é AVL.
//
//   Saída esperada:
//   50: altura 3, fator 0
//   30: altura 2, fator 1
//   20: altura 1, fator 1
//   10: altura 0, fator 0
//   40: altura 0, fator 0
//   70: altura 2, fator -2 <- desequilibrado
//   80: altura 1, fator -1
//   90: altura 0, fator 0
//   É AVL? não
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esq, *dir;
} Arv;

int main(void) {

    return 0;
}
