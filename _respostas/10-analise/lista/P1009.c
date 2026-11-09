// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1009 · ★☆☆ · O TAD da rifa da escola

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---- conjunto.h -----------------------------------------------------------
typedef struct conjunto Conjunto;

Conjunto *conj_cria(void);                   // NULL se faltar memória
bool conj_insere(Conjunto *c, int x);        // false se x fora de 0..63
void conj_remove(Conjunto *c, int x);
bool conj_pertence(const Conjunto *c, int x);
int conj_tamanho(const Conjunto *c);
void conj_libera(Conjunto *c);

// ---- conjunto.c -----------------------------------------------------------
// Invariante: n é o número de posições true em tem.
struct conjunto {
    bool tem[64];
    int n;
};

Conjunto *conj_cria(void) {
    Conjunto *c = malloc(sizeof *c);
    if (c != NULL) {
        for (int i = 0; i < 64; i++) {
            c->tem[i] = false;
        }
        c->n = 0;
    }
    return c;
}

bool conj_insere(Conjunto *c, int x) {
    if (x < 0 || x > 63) {
        return false;
    }
    if (!c->tem[x]) {
        c->tem[x] = true;
        c->n++;
    }
    return true;
}

void conj_remove(Conjunto *c, int x) {
    if (x >= 0 && x <= 63 && c->tem[x]) {
        c->tem[x] = false;
        c->n--;
    }
}

bool conj_pertence(const Conjunto *c, int x) {
    return x >= 0 && x <= 63 && c->tem[x];
}

int conj_tamanho(const Conjunto *c) {
    return c->n;
}

void conj_libera(Conjunto *c) {
    free(c);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    Conjunto *rifa = conj_cria();
    if (rifa == NULL) {
        printf("Sem memória (ou conj_cria ainda não foi escrita)\n");
        return 1;
    }
    conj_insere(rifa, 7);
    conj_insere(rifa, 13);
    conj_insere(rifa, 42);
    conj_insere(rifa, 7); // repetido
    conj_insere(rifa, 63);
    bool aceito = conj_insere(rifa, 64);
    conj_remove(rifa, 13);

    printf("Vendidos: %d\n", conj_tamanho(rifa));
    printf("42 vendido? %s\n", conj_pertence(rifa, 42) ? "sim" : "não");
    printf("13 vendido? %s\n", conj_pertence(rifa, 13) ? "sim" : "não");
    printf("64 aceito? %s\n", aceito ? "sim" : "não");
    conj_libera(rifa);
    return 0;
}
