// 0099 · BST: busca e inserção
// Exercício E592 · ★★☆
//
// Escreva insere_sem_recursao(No **raiz, int chave): a inserção na BST com um
// laço, recebendo o ENDEREÇO da raiz. Assim a função não devolve nada e o
// main não precisa fazer raiz = .... Repetida é ignorada.
//
// O main insere as matrículas 50 30 70 20 40 60 80 30 e mostra:
//
//   Saída esperada:
//   Em ordem: 20 30 40 50 60 70 80
//   Altura: 2
//
// Dicas:
// 1. Use No **p = raiz. Enquanto *p != NULL, compare e faça
//    p = &(*p)->esq ou p = &(*p)->dir. Se a chave for igual, saia.
// 2. Quando o laço parar com *p == NULL, p é o endereço do ponteiro que
//    precisa apontar para o nó novo (pode ser a própria raiz!). Faça o
//    malloc, preencha e faça *p = novo.
// 3. Resposta esperada: a saída acima (o 30 repetido não entra).
//
// Escreva sua resposta abaixo (complete insere_sem_recursao):

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insere_sem_recursao(No **raiz, int chave) {
    (void)raiz; // apague estas duas linhas
    (void)chave;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 30};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        insere_sem_recursao(&raiz, matriculas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\nAltura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
