// vermelhopreto.h · TAD árvore rubro-negra clássica (Cormen, com sentinela T.nil)
#ifndef VERMELHOPRETO_H
#define VERMELHOPRETO_H

#include <stdbool.h>

typedef enum { VERMELHO, PRETO } Cor;

typedef struct NoVP {
    int chave;
    Cor cor;
    struct NoVP *esq;
    struct NoVP *dir;
    struct NoVP *pai;
} NoVP;

typedef struct {
    NoVP *raiz; // &nil quando a árvore está vazia
    NoVP nil;   // a sentinela: preta; faz o papel de todo NULL (folhas e pai da raiz)
    int rotacoes;
    int casos[4]; // casos[1], casos[2], casos[3]: quantas vezes cada caso do conserto rodou
} ArvVP;

ArvVP *vp_cria(void);

// insere (repetida é ignorada) e conserta as cores
void vp_insere(ArvVP *T, int chave);

NoVP *vp_busca(ArvVP *T, int chave); // &T->nil se não achar

int vp_altura(const ArvVP *T);       // em arestas; vazia: -1
int vp_altura_negra(const ArvVP *T); // pretos da raiz (exclusive) até a folha nil (inclusive)

// confere as cinco propriedades; devolve true se todas valem
bool vp_confere(const ArvVP *T);

// pré-ordem; o nó vermelho sai com * (ex.: " 20 10* 30*")
void vp_pre_ordem(const ArvVP *T);
void vp_em_ordem(const ArvVP *T);

void vp_libera(ArvVP *T);

#endif
