// Lista · Módulo 14 · Árvores
// Exercício P1402 · ★☆☆ · A BST das senhas e os três percursos
//
// Insira as senhas 50, 30, 70, 20, 40, 60, 80, 35, 65, nesta ordem, numa
// árvore binária de busca vazia (menor à esquerda, maior à direita, repetida
// é ignorada). Mostre os percursos pré-ordem, em ordem e pós-ordem e libere
// a árvore.
//
//   Saída esperada:
//   pré: 50 30 20 40 35 70 60 65 80
//   em:  20 30 35 40 50 60 65 70 80
//   pós: 20 35 40 30 65 60 80 70 50
//
// Dicas:
// 1. A inserção recursiva devolve a raiz: r->esq = insere(r->esq, chave).
// 2. Desenhe a árvore antes: o 35 fica à esquerda do 40 e o 65 à direita do 60.
// 3. A em ordem de uma BST sai sempre crescente: se não sair, a inserção está
//    errada. A raiz é a primeira da pré e a última da pós.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}
