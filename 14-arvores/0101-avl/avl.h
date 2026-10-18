// avl.h · interface do TAD árvore AVL (BST que se equilibra sozinha)
#ifndef AVL_H
#define AVL_H

typedef struct No {
    int chave;
    int altura; // altura do nó, guardada para não recalcular
    struct No *esq;
    struct No *dir;
} No;

// insere (repetida é ignorada), rebalanceia e devolve a nova raiz
No *avl_insere(No *r, int chave);

int avl_altura(const No *r); // vazia: -1
int avl_fator(const No *r);  // altura(esq) - altura(dir); na AVL fica em -1, 0 ou 1

void avl_pre_ordem(const No *r);
void avl_em_ordem(const No *r);

// quantas rotações simples já foram feitas (a dupla conta 2); para estudo
int avl_rotacoes(void);

No *avl_libera(No *r);

#endif
