// sentinela.h · TAD lista dupla circular com nó sentinela (o L.nil do Cormen)
#ifndef SENTINELA_H
#define SENTINELA_H

typedef struct NoS {
    int chave;
    struct NoS *ant;
    struct NoS *prox;
} NoS;

typedef struct {
    NoS nil; // a sentinela: nil.prox é o primeiro, nil.ant é o último
    int n;   // quantos nós de verdade (a sentinela não conta)
} ListaS;

// cria a lista vazia: nil.prox e nil.ant apontam para a própria sentinela
ListaS *sent_cria(void);

// insere a chave num nó novo logo depois de y (y pode ser &L->nil)
NoS *sent_insere_apos(ListaS *L, NoS *y, int chave);
NoS *sent_insere_inicio(ListaS *L, int chave);
NoS *sent_insere_fim(ListaS *L, int chave);

// devolve o nó com a chave, ou &L->nil se não achar
NoS *sent_busca(ListaS *L, int chave);

// tira o nó x da lista e libera (x não pode ser a sentinela)
void sent_remove(ListaS *L, NoS *x);

void sent_mostra(const ListaS *L);         // do primeiro ao último
void sent_mostra_inverso(const ListaS *L); // do último ao primeiro
void sent_libera(ListaS *L);

#endif
