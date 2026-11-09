// Lista · Módulo 12 · Pilhas e filas
// Exercício P1214 · ★★☆ · O jogo das cartas nas pontas

#include <stdbool.h>
#include <stdio.h>

#define CAP 16

typedef struct {
    int v[CAP];
    int inicio, n;
} Deque;

bool insere_fim(Deque *d, int x) {
    if (d->n == CAP) {
        return false;
    }
    d->v[(d->inicio + d->n) % CAP] = x;
    d->n++;
    return true;
}

int primeiro(const Deque *d) {
    return d->v[d->inicio];
}

int ultimo(const Deque *d) {
    return d->v[(d->inicio + d->n - 1) % CAP];
}

int retira_inicio(Deque *d) {
    int x = d->v[d->inicio];
    d->inicio = (d->inicio + 1) % CAP;
    d->n--;
    return x;
}

int retira_fim(Deque *d) {
    int x = ultimo(d);
    d->n--;
    return x;
}

int main(void) {
    int cartas[6] = {3, 9, 1, 2, 7, 5};
    Deque mesa = {.inicio = 0, .n = 0};
    for (int i = 0; i < 6; i++) {
        insere_fim(&mesa, cartas[i]);
    }
    const char *nome[2] = {"Ana", "Beto"};
    int pontos[2] = {0, 0}, vez = 0;
    while (mesa.n > 0) {
        int carta;
        const char *lado;
        if (primeiro(&mesa) >= ultimo(&mesa)) {
            carta = retira_inicio(&mesa);
            lado = "esquerda";
        } else {
            carta = retira_fim(&mesa);
            lado = "direita";
        }
        printf("%s pega %d (%s)\n", nome[vez], carta, lado);
        pontos[vez] += carta;
        vez = 1 - vez;
    }
    printf("Ana: %d pontos, Beto: %d pontos\n", pontos[0], pontos[1]);
    return 0;
}
