// rubronegra.h · interface do TAD árvore rubro-negra esquerdista (LLRB)
#ifndef RUBRONEGRA_H
#define RUBRONEGRA_H

#include <stdbool.h>

typedef struct NoRN {
    int chave;
    bool vermelho;           // cor do link que liga o nó ao pai
    struct NoRN *esq;
    struct NoRN *dir;
} NoRN;

// insere (repetida é ignorada), conserta as cores e devolve a raiz (preta)
NoRN *rn_insere(NoRN *raiz, int chave);

bool rn_busca(const NoRN *r, int chave);
int rn_altura(const NoRN *r);        // em arestas; vazia: -1
int rn_altura_preta(const NoRN *r);  // nós pretos no caminho da raiz até um NULL

// pré-ordem; o nó vermelho sai com * (ex.: " 20 10* 30")
void rn_pre_ordem(const NoRN *r);
void rn_em_ordem(const NoRN *r);

// contadores para estudo: rotações (esquerda + direita) e inversões de cor
int rn_rotacoes(void);
int rn_inversoes(void);

NoRN *rn_libera(NoRN *r);

#endif
