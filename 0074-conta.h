// conta.h · interface do TAD Conta (conta bancária)
//
// Valores em centavos (int), para não sofrer com o arredondamento do double.
// Promessa do TAD: o saldo nunca fica negativo. Quem usa não consegue
// quebrar essa regra, porque não enxerga o campo saldo.

#ifndef CONTA_H
#define CONTA_H

#include <stdbool.h>

typedef struct conta Conta; // tipo opaco: os campos ficam no conta.c

// Abre uma conta com saldo 0 para "titular" (até 39 letras; o resto é
// cortado). Devolve NULL se faltar memória.
Conta *conta_cria(const char *titular);

// Fecha a conta e devolve a memória. Aceita NULL.
void conta_libera(Conta *c);

// Deposita "centavos" (> 0). Devolve false se o valor não for positivo.
bool conta_deposita(Conta *c, int centavos);

// Saca "centavos" (> 0). Devolve false, sem mexer em nada, se o valor não
// for positivo ou se o saldo não cobrir.
bool conta_saca(Conta *c, int centavos);

// Saldo atual em centavos (sempre >= 0) e nome do titular.
int conta_saldo(const Conta *c);
const char *conta_titular(const Conta *c);

#endif
