// grafo.h · interface do TAD grafo (lista de adjacência, arestas dirigidas)
#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>

typedef struct Grafo Grafo; // os campos ficam escondidos em grafo.c

Grafo *grafo_criar(int vertices);                      // NULL se faltar memória
bool grafo_ligar(Grafo *g, int origem, int destino);   // aresta origem -> destino
int grafo_grau_saida(const Grafo *g, int v);           // quantas arestas saem de v
int grafo_grau_entrada(const Grafo *g, int v);         // quantas arestas chegam em v
void grafo_mostrar(const Grafo *g, const char *nomes[]);
void grafo_liberar(Grafo *g);

#endif
