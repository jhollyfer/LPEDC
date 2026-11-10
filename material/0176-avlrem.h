// avlrem.h · TAD árvore AVL com inserção e remoção
#ifndef AVLREM_H
#define AVLREM_H

typedef struct NoA {
    int chave;
    int altura; // folha: 0
    struct NoA *esq;
    struct NoA *dir;
} NoA;

// insere (repetida é ignorada), rebalanceia e devolve a nova raiz
NoA *avr_insere(NoA *r, int chave);

// remove (se não existe, nada muda), rebalanceia na volta e devolve a raiz
NoA *avr_remove(NoA *r, int chave);

int avr_altura(const NoA *r); // vazia: -1
int avr_fator(const NoA *r);  // altura(esq) - altura(dir)

void avr_pre_ordem(const NoA *r);
void avr_em_ordem(const NoA *r);

// contador de rotações simples (a dupla conta 2), para estudo
int avr_rotacoes(void);

NoA *avr_libera(NoA *r);

#endif
