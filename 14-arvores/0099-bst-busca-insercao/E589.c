// 0099 · BST: busca e inserção
// Exercício E589 · ★☆☆
//
// O posto de saúde guarda as senhas de atendimento numa BST. O main insere,
// nesta ordem:
//
//   45 20 70 10 30 60 90 25
//
// Complete a função nivel_de(r, chave), que desce pela árvore como a busca e
// devolve a profundidade da chave (a raiz tem nível 0), ou -1 se a chave não
// estiver lá. O main mostra a em ordem, a altura e o nível de algumas senhas:
//
//   Saída esperada:
//   Em ordem: 10 20 25 30 45 60 70 90
//   Altura: 3
//   Senha 45: nível 0
//   Senha 70: nível 1
//   Senha 30: nível 2
//   Senha 25: nível 3
//   Senha 65: nível -1
//
// Dicas:
// 1. Use um laço igual ao de bst_busca e um contador que começa em 0 e sobe
//    1 a cada vez que você desce um nível.
// 2. Se o laço terminar com r == NULL, a chave não existe: devolva -1.
// 3. Resposta esperada: a saída acima. O 25 fica embaixo de 45, 20 e 30.
//
// Escreva sua resposta abaixo (complete nivel_de):

#include <stdio.h>
#include "bst.h"

int nivel_de(const No *r, int chave) {
    (void)r; // apague estas duas linhas quando escrever a função
    (void)chave;
    return -1;
}

int main(void) {
    int senhas[] = {45, 20, 70, 10, 30, 60, 90, 25};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = bst_insere(raiz, senhas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\nAltura: %d\n", bst_altura(raiz));

    int testes[] = {45, 70, 30, 25, 65};
    for (int i = 0; i < 5; i++) {
        printf("Senha %d: nível %d\n", testes[i], nivel_de(raiz, testes[i]));
    }

    raiz = bst_libera(raiz);
    return 0;
}
