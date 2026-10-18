// A195 · Duas árvores com a mesma em ordem

#include <stdio.h>
#include "arvore.h"

void percursos(const char *titulo, const No *r) {
    printf("%s\n  pré:", titulo);
    arv_pre_ordem(r);
    printf("\n  em:");
    arv_em_ordem(r);
    printf("\n  pós:");
    arv_pos_ordem(r);
    printf("\n  altura %d\n", arv_altura(r));
}

int main(void) {
    // equilibrada: B na raiz, A à esquerda, C à direita
    No *cheia = arv_cria('B', arv_cria('A', NULL, NULL), arv_cria('C', NULL, NULL));

    // torta: cada nó só tem filho à direita (parece uma lista)
    No *torta = arv_cria('A', NULL, arv_cria('B', NULL, arv_cria('C', NULL, NULL)));

    // caso de borda: árvore vazia (os percursos não mostram nada)
    No *vazia = NULL;

    percursos("cheia:", cheia);
    percursos("torta:", torta);
    percursos("vazia:", vazia);

    // a em ordem é igual nas duas primeiras: sozinha ela não diz a forma;
    // a pré-ordem (ou a pós) junto com ela já diz
    cheia = arv_libera(cheia);
    torta = arv_libera(torta);
    return 0;
}
// Saída:
// cheia:
//   pré: B A C
//   em: A B C
//   pós: A C B
//   altura 1
// torta:
//   pré: A B C
//   em: A B C
//   pós: C B A
//   altura 2
// vazia:
//   pré:
//   em:
//   pós:
//   altura -1
