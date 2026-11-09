// Lista · Módulo 12 · Pilhas e filas
// Exercício P1229 · ★★★ · De quem é a vez no Uno?

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int inicio, n;
} Deque;

void insere_inicio(Deque *d, int x) {
    d->inicio = (d->inicio - 1 + CAP) % CAP;
    d->v[d->inicio] = x;
    d->n++;
}

void insere_fim(Deque *d, int x) {
    d->v[(d->inicio + d->n) % CAP] = x;
    d->n++;
}

int retira_inicio(Deque *d) {
    int x = d->v[d->inicio];
    d->inicio = (d->inicio + 1) % CAP;
    d->n--;
    return x;
}

int retira_fim(Deque *d) {
    int x = d->v[(d->inicio + d->n - 1) % CAP];
    d->n--;
    return x;
}

int primeiro(const Deque *d) {
    return d->v[d->inicio];
}

void anda(Deque *d, bool horario) {
    if (horario) {
        insere_fim(d, retira_inicio(d));
    } else {
        insere_inicio(d, retira_fim(d));
    }
}

int main(void) {
    const char *nomes[4] = {"Ana", "Bia", "Caio", "Davi"};
    const char *cartas[8] = {"normal", "normal", "inverte", "normal", "pula", "normal", "inverte", "normal"};
    Deque roda = {.inicio = 0, .n = 0};
    for (int i = 0; i < 4; i++) {
        insere_fim(&roda, i);
    }
    bool horario = true;
    for (int k = 0; k < 8; k++) {
        int quem = primeiro(&roda);
        if (strcmp(cartas[k], "inverte") == 0) {
            horario = !horario;
            anda(&roda, horario);
        } else if (strcmp(cartas[k], "pula") == 0) {
            anda(&roda, horario);
            anda(&roda, horario);
        } else {
            anda(&roda, horario);
        }
        printf("%s joga %s; vez de %s\n", nomes[quem], cartas[k], nomes[primeiro(&roda)]);
    }
    return 0;
}
