// Lista · Módulo 08 · Tipos compostos
// Exercício P0827 · ★★★ · O crivo de primos em bits

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 1000

typedef struct {
    int n;
    unsigned char bits[(N + 1 + 7) / 8];
} Crivo;

void marcar(Crivo *c, int k) {
    c->bits[k / 8] |= (unsigned char) (1u << (k % 8));
}

bool eh_primo(const Crivo *c, int k) {
    return !((c->bits[k / 8] >> (k % 8)) & 1u);
}

void montar(Crivo *c, int n) {
    c->n = n;
    memset(c->bits, 0, sizeof c->bits);
    marcar(c, 0);
    marcar(c, 1);
    for (int i = 2; i * i <= n; i++) {
        if (eh_primo(c, i)) {
            for (int j = i * i; j <= n; j += i) {
                marcar(c, j); // múltiplo de i: composto
            }
        }
    }
}

int main(void) {
    Crivo c;
    montar(&c, N);

    int total = 0, anterior = 2, maior_salto = 0, de = 0, ate = 0;
    for (int k = 2; k <= N; k++) {
        if (!eh_primo(&c, k)) {
            continue;
        }
        total++;
        if (k - anterior > maior_salto) {
            maior_salto = k - anterior;
            de = anterior;
            ate = k;
        }
        anterior = k;
    }
    printf("Primos até %d: %d\n", N, total);
    printf("Entre 900 e 1000:");
    for (int k = 900; k <= 1000; k++) {
        if (eh_primo(&c, k)) {
            printf(" %d", k);
        }
    }
    printf("\nMaior intervalo: %d (de %d a %d)\n", maior_salto, de, ate);
    printf("Memória: %zu bytes de bits (com bool seriam %d)\n", sizeof c.bits, N + 1);
    return 0;
}
