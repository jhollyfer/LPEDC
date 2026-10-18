// contador.h · interface do TAD Contador
//
// Um contador que vai de 0 até um limite: vagas de estacionamento, lugares
// no ônibus, pessoas na academia. Quem usa só enxerga estas funções; a struct
// fica escondida em contador.c (tipo opaco).

#ifndef CONTADOR_H
#define CONTADOR_H

#include <stdbool.h>

typedef struct contador Contador; // tipo opaco: os campos ficam no contador.c

// Cria um contador zerado que aceita até "limite" (limite >= 1).
// Devolve NULL se limite < 1 ou se faltar memória.
Contador *contador_cria(int limite);

// Devolve a memória do contador. Aceita NULL (não faz nada).
void contador_libera(Contador *c);

// Soma 1. Devolve true se somou; false se já estava no limite.
bool contador_incrementa(Contador *c);

// Tira 1. Devolve true se tirou; false se já estava em 0.
bool contador_decrementa(Contador *c);

// Volta o contador para 0.
void contador_zera(Contador *c);

// Valor atual (sempre entre 0 e o limite) e o limite.
int contador_valor(const Contador *c);
int contador_limite(const Contador *c);

#endif
