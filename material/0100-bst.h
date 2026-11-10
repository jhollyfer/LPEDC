// bst.h · interface do TAD árvore binária de busca (chaves int)
#ifndef BST_H
#define BST_H

// a struct fica à mostra no .h porque os exercícios andam pelos nós
typedef struct No {
    int chave;
    struct No *esq; // chaves menores
    struct No *dir; // chaves maiores
} No;

// insere a chave como folha e devolve a raiz (repetida é ignorada)
No *bst_insere(No *r, int chave);

// devolve o nó com a chave, ou NULL se não achar
No *bst_busca(No *r, int chave);

// remove a chave (se existir) e devolve a nova raiz
No *bst_remove(No *r, int chave);

void bst_em_ordem(const No *r); // mostra as chaves em ordem crescente
int bst_altura(const No *r);    // vazia: -1; só a raiz: 0

// libera tudo e devolve NULL: use r = bst_libera(r);
No *bst_libera(No *r);

#endif
