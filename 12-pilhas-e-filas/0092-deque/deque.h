// deque.h · interface do TAD deque (fila dupla) de inteiros
//
// Entra e sai pelas duas pontas. A implementação (vetor circular, no
// deque.c) fica escondida.

#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct deque Deque; // tipo opaco: os campos ficam no deque.c

Deque *deque_cria(void);                         // deque vazio (NULL se faltar memória)
void deque_libera(Deque *d);                     // devolve a memória do deque
bool deque_vazio(const Deque *d);                // true se não tem nada
int deque_tamanho(const Deque *d);               // quantos itens tem
bool deque_insere_inicio(Deque *d, int valor);   // entra na frente: false se cheio
bool deque_insere_fim(Deque *d, int valor);      // entra atrás: false se cheio
bool deque_retira_inicio(Deque *d, int *valor);  // sai da frente: false se vazio
bool deque_retira_fim(Deque *d, int *valor);     // sai de trás: false se vazio
bool deque_primeiro(const Deque *d, int *valor); // olha a frente, sem tirar
bool deque_ultimo(const Deque *d, int *valor);   // olha o fundo, sem tirar

#endif
