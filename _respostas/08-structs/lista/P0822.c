// Lista · Módulo 08 · Tipos compostos
// Exercício P0822 · ★★★ · O conjunto de bits dos assentos

#include <stdio.h>
#include <stdbool.h>

#define LUGARES 100
#define BYTES ((LUGARES + 7) / 8)

typedef struct {
    unsigned char bits[BYTES];
} Conjunto;

void inserir(Conjunto *c, int k) {
    c->bits[k / 8] |= (unsigned char) (1u << (k % 8));
}

void remover(Conjunto *c, int k) {
    c->bits[k / 8] &= (unsigned char) ~(1u << (k % 8));
}

bool contem(const Conjunto *c, int k) {
    return (c->bits[k / 8] >> (k % 8)) & 1u;
}

int tamanho(const Conjunto *c) {
    int total = 0;
    for (int i = 0; i < BYTES; i++) {
        for (unsigned x = c->bits[i]; x != 0; x >>= 1) {
            total += x & 1u;
        }
    }
    return total;
}

Conjunto uniao(const Conjunto *a, const Conjunto *b) {
    Conjunto r;
    for (int i = 0; i < BYTES; i++) {
        r.bits[i] = a->bits[i] | b->bits[i];
    }
    return r;
}

Conjunto intersecao(const Conjunto *a, const Conjunto *b) {
    Conjunto r;
    for (int i = 0; i < BYTES; i++) {
        r.bits[i] = a->bits[i] & b->bits[i];
    }
    return r;
}

void mostrar(const char *nome, const Conjunto *c) {
    printf("%s (%d):", nome, tamanho(c));
    for (int k = 0; k < LUGARES; k++) {
        if (contem(c, k)) {
            printf(" %d", k);
        }
    }
    printf("\n");
}

int main(void) {
    int app_a[8] = {3, 7, 12, 40, 41, 42, 77, 98};
    int app_b[6] = {7, 15, 40, 63, 98, 99};
    Conjunto a = {0}, b = {0};

    for (int i = 0; i < 8; i++) {
        inserir(&a, app_a[i]);
    }
    for (int i = 0; i < 6; i++) {
        inserir(&b, app_b[i]);
    }
    mostrar("App A", &a);
    mostrar("App B", &b);
    Conjunto u = uniao(&a, &b);
    Conjunto in = intersecao(&a, &b);
    mostrar("Vendidos", &u);
    mostrar("Vendidos duas vezes", &in);
    printf("Livres: %d de %d (em %d bytes)\n", LUGARES - tamanho(&u), LUGARES, BYTES);

    remover(&a, 7);
    in = intersecao(&a, &b);
    mostrar("Depois do cancelamento, duas vezes", &in);
    return 0;
}
