// arvpai.h · TAD árvore binária de busca com ponteiro para o pai
#ifndef ARVPAI_H
#define ARVPAI_H

typedef struct NoP {
    int chave;
    struct NoP *esq;
    struct NoP *dir;
    struct NoP *pai; // NULL na raiz
} NoP;

// insere (repetida é ignorada) e devolve a raiz
NoP *ap_insere(NoP *raiz, int chave);
NoP *ap_busca(NoP *raiz, int chave); // NULL se não achar

NoP *ap_minimo(NoP *x);     // o mais à esquerda da subárvore de x
NoP *ap_maximo(NoP *x);     // o mais à direita
NoP *ap_sucessor(NoP *x);   // próxima chave em ordem; NULL se x é o maior
NoP *ap_antecessor(NoP *x); // chave anterior; NULL se x é o menor

// conceitos (altura e profundidade contam arestas)
int ap_grau(const NoP *x);         // filhos de x: 0, 1 ou 2
int ap_altura(const NoP *x);       // vazia: -1; folha: 0
int ap_profundidade(const NoP *x); // arestas até a raiz (o nível de x)
int ap_fator(const NoP *x);        // altura(esq) - altura(dir)

void ap_em_ordem(const NoP *raiz);
NoP *ap_libera(NoP *raiz);

#endif
