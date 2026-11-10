// 0176 · AVL: remoção
// Exercício E1054 · ★★☆
//
// Escreva uma AVL de int do zero (sem TAD): No com chave, altura, esq e dir;
// alt (altura de NULL é -1), atualiza, gira_dir, gira_esq, equilibra,
// insere, pre (pré-ordem) e libera. Na remoção, remove_chave, o nó com dois
// filhos recebe a chave do ANTECESSOR (o maior da subárvore esquerda), que
// é removido dali; o rebalanceamento acontece na volta da recursão.
// Insira 40, 20, 60, 10, 30, 50, 70, 25, 35, remova o 40 e depois o 20,
// mostrando a pré-ordem a cada passo e, no fim, a altura.
//
//   Saída esperada:
//   início:  pré 40 20 10 30 25 35 60 50 70
//   tira 40: pré 35 20 10 30 25 60 50 70
//   tira 20: pré 35 25 10 30 60 50 70
//   altura final: 2
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, altura;
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}
