// 0101 · AVL: balanceamento e rotações
// Exercício E601 · ★☆☆
//
// O main monta à mão esta BST (sem campo de altura, com o struct Arv do
// próprio arquivo):
//
//   50
//   ├── esq: 30
//   │   ├── esq: 20
//   │   │   └── esq: 10
//   │   └── dir: 40
//   └── dir: 70
//       └── dir: 80
//           └── dir: 90
//
// Complete altura(r) e relatorio(r). A relatorio mostra, em pré-ordem, a
// altura e o fator de balanceamento (altura da esquerda menos altura da
// direita) de cada nó, e marca com "<- desequilibrado" quem tem fator fora
// de -1..1. No fim, o main diz se a árvore é AVL.
//
//   Saída esperada:
//   50: altura 3, fator 0
//   30: altura 2, fator 1
//   20: altura 1, fator 1
//   10: altura 0, fator 0
//   40: altura 0, fator 0
//   70: altura 2, fator -2 <- desequilibrado
//   80: altura 1, fator -1
//   90: altura 0, fator 0
//   É AVL? não
//
// Dicas:
// 1. altura: vazia devolve -1; senão, 1 + a maior altura entre os filhos.
// 2. relatorio devolve quantos nós desequilibrados achou (o do nó mais os
//    das duas subárvores); a árvore é AVL quando o total é 0.
// 3. Resposta esperada: a saída acima. O 70 cai no caso direita-direita.
//
// Escreva sua resposta abaixo (complete altura e relatorio):

#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esq, *dir;
} Arv;

Arv *no(int chave, Arv *esq, Arv *dir) {
    Arv *n = malloc(sizeof(Arv));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->esq = esq;
    n->dir = dir;
    return n;
}

void libera(Arv *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int altura(const Arv *r) {
    (void)r; // apague esta linha quando escrever a função
    return -1;
}

int relatorio(const Arv *r) {
    (void)r; // apague esta linha quando escrever a função
    return 0;
}

int main(void) {
    Arv *raiz = no(50, no(30, no(20, no(10, NULL, NULL), NULL), no(40, NULL, NULL)),
                   no(70, NULL, no(80, NULL, no(90, NULL, NULL))));

    int ruins = relatorio(raiz);
    printf("É AVL? %s\n", ruins == 0 ? "sim" : "não");
    libera(raiz);
    return 0;
}
