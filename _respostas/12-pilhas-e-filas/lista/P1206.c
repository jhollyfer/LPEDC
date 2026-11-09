// Lista · Módulo 12 · Pilhas e filas
// Exercício P1206 · ★☆☆ · Palíndromo pelas duas pontas do deque

#include <stdbool.h>
#include <stdio.h>

#define CAP 32

typedef struct {
    char v[CAP];
    int inicio, n;
} Deque;

bool insere_fim(Deque *d, char c) {
    if (d->n == CAP) {
        return false;
    }
    d->v[(d->inicio + d->n) % CAP] = c;
    d->n++;
    return true;
}

bool retira_inicio(Deque *d, char *c) {
    if (d->n == 0) {
        return false;
    }
    *c = d->v[d->inicio];
    d->inicio = (d->inicio + 1) % CAP;
    d->n--;
    return true;
}

bool retira_fim(Deque *d, char *c) {
    if (d->n == 0) {
        return false;
    }
    *c = d->v[(d->inicio + d->n - 1) % CAP];
    d->n--;
    return true;
}

int tamanho(const Deque *d) {
    return d->n;
}

bool palindromo(const char *palavra) {
    Deque d = {.inicio = 0, .n = 0};
    for (int i = 0; palavra[i] != '\0'; i++) {
        insere_fim(&d, palavra[i]);
    }
    while (tamanho(&d) > 1) {
        char a, b;
        retira_inicio(&d, &a);
        retira_fim(&d, &b);
        if (a != b) {
            return false;
        }
    }
    return true;
}

int main(void) {
    const char *palavras[5] = {"arara", "osso", "ovo", "casa", "a"};
    for (int i = 0; i < 5; i++) {
        printf("%s: %s\n", palavras[i], palindromo(palavras[i]) ? "sim" : "não");
    }
    return 0;
}
