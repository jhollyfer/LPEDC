// 0104 · BST: busca e inserção
// Exercício E619 · ★☆☆
//
// No papel, insira estas senhas de atendimento numa BST vazia, nesta ordem:
//
//   45 20 70 10 30 60 90 25
//
// Desenhe a árvore e responda: (a) qual é a altura? (b) por quais nós passa a
// busca pelo 25? (c) e a busca pelo 65, que não existe, termina à direita ou
// à esquerda de quem? Depois rode o programa e confira a em ordem e a altura.
//
// Dicas:
// 1. Cada chave desce da raiz comparando: menor vai para a esquerda, maior
//    para a direita, até achar um NULL.
// 2. O 25 é menor que 45, maior que 20 e menor que 30.
// 3. Resposta esperada: 45 na raiz; 20 (filhos 10 e 30) à esquerda; 70
//    (filhos 60 e 90) à direita; 25 é filho esquerdo do 30. (a) altura 3;
//    (b) 45, 20, 30, 25; (c) 45, 70, 60 e cai à direita do 60.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "bst.h"

int main(void) {
    int senhas[] = {45, 20, 70, 10, 30, 60, 90, 25};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = bst_insere(raiz, senhas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\nAltura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
