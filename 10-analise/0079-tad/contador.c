// contador.c · implementação do TAD Contador
//
// Só este arquivo conhece os campos da struct. Se amanhã ela mudar, nenhum
// cliente precisa ser reescrito: basta recompilar.

#include <stdlib.h>

#include "contador.h" // confere que as funções batem com os protótipos

// Invariante da struct: 0 <= valor <= limite e limite >= 1.
// Toda função que mexe nos campos tem de deixar isso verdadeiro.
struct contador {
    int valor;
    int limite;
};

Contador *contador_cria(int limite) {
    if (limite < 1) {
        return NULL;
    }
    Contador *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    c->valor = 0;
    c->limite = limite;
    return c;
}

void contador_libera(Contador *c) {
    free(c); // free(NULL) não faz nada
}

bool contador_incrementa(Contador *c) {
    if (c->valor == c->limite) {
        return false;
    }
    c->valor++;
    return true;
}

bool contador_decrementa(Contador *c) {
    if (c->valor == 0) {
        return false;
    }
    c->valor--;
    return true;
}

void contador_zera(Contador *c) {
    c->valor = 0;
}

int contador_valor(const Contador *c) {
    return c->valor;
}

int contador_limite(const Contador *c) {
    return c->limite;
}
