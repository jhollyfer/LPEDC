// 0104 · BST: busca e inserção
// Exercício E620 · ★☆☆
//
// Complete menor_chave e maior_chave, que devolvem a menor e a maior
// matrícula da academia. Use um laço (sem recursão) e não visite a árvore
// inteira: aproveite a regra da BST. Pode supor que a árvore não é vazia.
//
//   Saída esperada:
//   Matrícula mais antiga: 20
//   Matrícula mais nova: 80
//
// Dicas:
// 1. Onde mora a menor chave? Ninguém à esquerda dela pode existir.
// 2. Desça pela esquerda enquanto r->esq != NULL. Cuidado: o nó mais à
//    esquerda não precisa ser folha; ele pode ter filho direito.
// 3. Resposta esperada: 20 e 80.
//
// Escreva sua resposta abaixo (complete as duas funções):

#include <stdio.h>
#include "bst.h"

int menor_chave(const No *r) {
    (void)r; // apague esta linha
    return 0;
}

int maior_chave(const No *r) {
    (void)r; // apague esta linha
    return 0;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    printf("Matrícula mais antiga: %d\n", menor_chave(raiz));
    printf("Matrícula mais nova: %d\n", maior_chave(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
