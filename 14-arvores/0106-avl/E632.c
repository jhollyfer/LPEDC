// 0106 · AVL: balanceamento e rotações
// Exercício E632 · ★☆☆
//
// SEM RODAR, preveja o que o programa mostra. Ele insere duas sequências em
// duas AVL diferentes e mostra a pré-ordem, a altura e o total de rotações
// simples feitas até ali (a dupla conta 2). Desenhe cada inserção no papel.
//
// Dicas:
// 1. 30, 10, 20: o 30 fica com fator +2 e o filho 10 com -1. Que caso é?
// 2. De 1 a 7: as rotações acontecem ao inserir o 3, o 5, o 6 e o 7.
// 3. Resposta esperada:
//    30 10 20 -> pré 20 10 30 | altura 1 | rotações 2
//    1 a 7    -> pré 4 2 1 3 6 5 7 | altura 2 | rotações 6
//    (a primeira árvore usou 2 rotações; a segunda, mais 4, e o contador é
//    um só para o programa todo). A árvore de 1 a 7 fica perfeita.
//
// Escreva sua resposta abaixo (a saída, como comentário):

#include <stdio.h>
#include "avl.h"

int main(void) {
    int a[] = {30, 10, 20};
    No *r1 = NULL;
    for (int i = 0; i < 3; i++) {
        r1 = avl_insere(r1, a[i]);
    }
    printf("30 10 20 -> pré");
    avl_pre_ordem(r1);
    printf(" | altura %d | rotações %d\n", avl_altura(r1), avl_rotacoes());

    No *r2 = NULL;
    for (int i = 1; i <= 7; i++) {
        r2 = avl_insere(r2, i);
    }
    printf("1 a 7    -> pré");
    avl_pre_ordem(r2);
    printf(" | altura %d | rotações %d\n", avl_altura(r2), avl_rotacoes());

    r1 = avl_libera(r1);
    r2 = avl_libera(r2);
    return 0;
}
