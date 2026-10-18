// pilha.h · interface do TAD pilha de inteiros
//
// Quem usa a pilha só enxerga estas funções. Como ela guarda os dados (vetor
// em 0087, lista encadeada em 0088) fica escondido no pilha.c.

#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct pilha Pilha; // tipo opaco: os campos ficam no pilha.c

Pilha *pilha_cria(void);                     // pilha vazia (NULL se faltar memória)
void pilha_libera(Pilha *p);                 // devolve toda a memória da pilha
bool pilha_vazia(const Pilha *p);            // true se não tem nada
int pilha_tamanho(const Pilha *p);           // quantos itens tem
bool pilha_empilha(Pilha *p, int valor);     // push: false se não coube
bool pilha_desempilha(Pilha *p, int *valor); // pop: false se estava vazia
bool pilha_topo(const Pilha *p, int *valor); // peek: olha o topo sem tirar

#endif
