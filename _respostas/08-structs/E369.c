// 0062 · Ponteiro para struct
// Exercício E369 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titular[30];
    double saldo;
} Conta;

Conta *conta_criar(const char *titular, double saldo) {
    Conta *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    strncpy(c->titular, titular, sizeof c->titular - 1);
    c->titular[sizeof c->titular - 1] = '\0';
    c->saldo = saldo;
    return c;
}

bool transferir(Conta *de, Conta *para, double valor) {
    if (de->saldo < valor) {
        return false;
    }
    de->saldo -= valor;
    para->saldo += valor;
    return true;
}

void conta_destruir(Conta *c) {
    free(c);
}

void tentar(Conta *de, Conta *para, double valor) {
    bool ok = transferir(de, para, valor);
    printf("%s -> %s, R$ %.2f: %s\n", de->titular, para->titular, valor,
           ok ? "ok" : "saldo insuficiente");
}

int main(void) {
    Conta *ana = conta_criar("Ana", 500.00);
    Conta *beto = conta_criar("Beto", 120.00);
    if (ana == NULL || beto == NULL) {
        conta_destruir(ana); // free(NULL) não faz nada: é seguro
        conta_destruir(beto);
        return 1;
    }

    tentar(ana, beto, 200.00);
    tentar(beto, ana, 400.00);
    printf("%s: R$ %.2f | %s: R$ %.2f\n", ana->titular, ana->saldo, beto->titular, beto->saldo);

    conta_destruir(ana);
    conta_destruir(beto);
    return 0;
}
