// 0177 · Rubro-negra clássica
// Exercício E1061 · ★★★
//
// Escreva a inserção da rubro-negra do Cormen à mão, com a sentinela nil
// (variável global, preta, que serve de folha e de pai da raiz):
// gira_esq, gira_dir, conserta (os casos 1, 2 e 3 e o espelho deles),
// insere(chave) e libera. Escreva também:
//
//   void pre(const No *x)    // pré-ordem; vermelho leva "*" depois da chave
//   int fiscal(const No *x)  // pretos de x até a nil (nil inclusive), ou
//                            // -1 se a propriedade 4 ou a 5 falhar
//
// Insira os pacotes 1 a 10, em ordem, mostre a pré-ordem e o veredito do
// fiscal sobre a raiz.
//
//   Saída esperada:
//   pré: 4 2 1 3 6 5 8* 7 9 10*
//   fiscal: as cinco propriedades valem
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

enum { VERMELHO, PRETO };

typedef struct No {
    int chave, cor;
    struct No *esq, *dir, *pai;
} No;

No nil = {0, PRETO, &nil, &nil, &nil};
No *raiz = &nil;

int main(void) {

    return 0;
}
