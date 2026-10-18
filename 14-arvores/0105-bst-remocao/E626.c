// 0105 · BST: remoção
// Exercício E626 · ★☆☆
//
// No banco, as senhas de espera ficam numa BST e a menor senha é sempre a
// próxima a ser chamada. Complete remove_menor(r, &senha): ela tira o nó com
// a menor chave, guarda essa chave em *senha e devolve a nova raiz. Não use
// bst_remove: escreva a remoção direto. Pode supor a árvore não vazia.
//
//   Saída esperada:
//   Chamando 20, restam: 30 40 50 70
//   Chamando 30, restam: 40 50 70
//   Chamando 40, restam: 50 70
//
// Dicas:
// 1. O menor é o nó mais à esquerda. Ele não tem filho esquerdo, mas pode ter
//    filho direito.
// 2. Recursivo: se r->esq == NULL, o menor é r: guarde a chave, pegue
//    r->dir, dê free(r) e devolva r->dir guardado. Senão,
//    r->esq = remove_menor(r->esq, senha) e devolva r.
// 3. Resposta esperada: a saída acima. Na terceira chamada, o 40 é o menor e
//    a raiz 30 já saiu: quem é a raiz depois?
//
// Escreva sua resposta abaixo (complete remove_menor):

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

No *remove_menor(No *r, int *senha) {
    (void)senha; // apague esta linha
    return r;
}

int main(void) {
    int senhas[] = {30, 20, 50, 40, 70};
    No *raiz = NULL;
    for (int i = 0; i < 5; i++) {
        raiz = bst_insere(raiz, senhas[i]);
    }
    for (int i = 0; i < 3; i++) {
        int senha = 0;
        raiz = remove_menor(raiz, &senha);
        printf("Chamando %d, restam:", senha);
        bst_em_ordem(raiz);
        printf("\n");
    }
    raiz = bst_libera(raiz);
    return 0;
}
