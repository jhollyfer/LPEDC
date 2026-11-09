// Lista · Módulo 14 · Árvores
// Exercício P1409 · ★☆☆ · Contando os nós pelo número de filhos
//
// Insira os preços 45, 22, 67, 10, 30, 55, 80, 5, 27, 90, 85 numa BST e
// escreva void conta_graus(const No *r, int grau[3]), que soma em grau[g]
// quantos nós têm g filhos (0, 1 ou 2). Mostre as três contagens, o total e
// confira a propriedade das árvores binárias: folhas = (nós com 2 filhos) + 1.
//
//   Saída esperada:
//   folhas (0 filhos): 4
//   com 1 filho: 4
//   com 2 filhos: 3
//   total: 11 nós
//   folhas = (2 filhos) + 1? sim
//
// Dicas:
// 1. (r->esq != NULL) + (r->dir != NULL) dá o número de filhos.
// 2. A propriedade vale para toda árvore binária não vazia: cada nó de grau 2
//    "abre" um caminho a mais, e os de grau 1 não mudam o número de folhas.
//    A prova cobra isso em questões de contar nós.
// 3. Resposta esperada: a saída acima.
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
