// conta.c · implementação do TAD Conta

#include <stdio.h>
#include <stdlib.h>

#include "conta.h"

// Invariante da struct: saldo >= 0. Só deposita e saca mexem no saldo, e as
// duas conferem antes de mexer.
struct conta {
    char titular[40];
    int saldo; // em centavos
};

Conta *conta_cria(const char *titular) {
    Conta *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    snprintf(c->titular, sizeof c->titular, "%s", titular); // copia e corta
    c->saldo = 0;
    return c;
}

void conta_libera(Conta *c) {
    free(c);
}

bool conta_deposita(Conta *c, int centavos) {
    if (centavos <= 0) {
        return false;
    }
    c->saldo += centavos;
    return true;
}

bool conta_saca(Conta *c, int centavos) {
    if (centavos <= 0 || centavos > c->saldo) {
        return false;
    }
    c->saldo -= centavos;
    return true;
}

int conta_saldo(const Conta *c) {
    return c->saldo;
}

const char *conta_titular(const Conta *c) {
    return c->titular;
}
