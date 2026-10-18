// fila.h · interface do TAD fila de inteiros
//
// Entra no fim, sai do início. Como a fila guarda os dados (vetor circular em
// 0090, lista encadeada em 0091) fica escondido no fila.c.

#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct fila Fila; // tipo opaco: os campos ficam no fila.c

Fila *fila_cria(void);                          // fila vazia (NULL se faltar memória)
void fila_libera(Fila *f);                      // devolve toda a memória da fila
bool fila_vazia(const Fila *f);                 // true se não tem ninguém
int fila_tamanho(const Fila *f);                // quantos estão na fila
bool fila_insere(Fila *f, int valor);           // entra no fim: false se não coube
bool fila_retira(Fila *f, int *valor);          // sai do início: false se vazia
bool fila_primeiro(const Fila *f, int *valor);  // olha quem é o próximo, sem tirar

#endif
