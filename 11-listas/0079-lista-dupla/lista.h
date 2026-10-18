// lista.h · lista duplamente encadeada de inteiros
//
// Cada nó conhece o anterior e o próximo. A lista guarda as duas pontas
// (inicio e fim) e o tamanho, numa struct que pode morar no main:
//   Lista trem;
//   lista_inicia(&trem);

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *ant;  // o anterior, ou NULL no primeiro
    struct no *prox; // o próximo, ou NULL no último
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

// deixa a lista vazia (chame antes de usar)
void lista_inicia(Lista *l);

// põe "valor" na frente / atrás; false se faltar memória
bool lista_insere_inicio(Lista *l, int valor);
bool lista_insere_fim(Lista *l, int valor);

// devolve o primeiro nó com "valor", ou NULL
No *lista_busca(const Lista *l, int valor);

// tira o nó p (que precisa estar na lista) e devolve a memória dele: O(1)
void lista_remove_no(Lista *l, No *p);

// mostra do início para o fim / do fim para o início: 98 <-> 105 <-> 87
void lista_imprime(const Lista *l);
void lista_imprime_reverso(const Lista *l);

// devolve a memória de todos os nós e deixa a lista vazia
void lista_libera(Lista *l);

#endif
