// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1025 · ★★★ · Os lugares do cinema num punhado de bits

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---- lugares.h ------------------------------------------------------------
typedef struct lugares Lugares;

Lugares *lugares_cria(void); // todos livres
void lugares_ocupa(Lugares *l, int k);
void lugares_libera_lugar(Lugares *l, int k);
bool lugares_ocupado(const Lugares *l, int k);
int lugares_conta(const Lugares *l); // quantos ocupados
Lugares *lugares_uniao(const Lugares *a, const Lugares *b);
Lugares *lugares_intersecao(const Lugares *a, const Lugares *b);
int lugares_bytes(void); // memória do vetor de bits
void lugares_libera(Lugares *l);

// ---- lugares.c ------------------------------------------------------------
#define LUGARES 256

struct lugares {
    unsigned char bits[LUGARES / 8];
};

Lugares *lugares_cria(void) {
    Lugares *l = malloc(sizeof *l);
    if (l != NULL) {
        for (int i = 0; i < LUGARES / 8; i++) {
            l->bits[i] = 0;
        }
    }
    return l;
}

void lugares_ocupa(Lugares *l, int k) {
    if (k >= 0 && k < LUGARES) {
        l->bits[k / 8] |= (unsigned char) (1u << (k % 8));
    }
}

void lugares_libera_lugar(Lugares *l, int k) {
    if (k >= 0 && k < LUGARES) {
        l->bits[k / 8] &= (unsigned char) ~(1u << (k % 8));
    }
}

bool lugares_ocupado(const Lugares *l, int k) {
    return k >= 0 && k < LUGARES && ((l->bits[k / 8] >> (k % 8)) & 1u);
}

int lugares_conta(const Lugares *l) {
    int total = 0;
    for (int i = 0; i < LUGARES / 8; i++) {
        unsigned char b = l->bits[i];
        while (b != 0) {
            b &= (unsigned char) (b - 1); // apaga o bit 1 mais baixo
            total++;
        }
    }
    return total;
}

Lugares *lugares_uniao(const Lugares *a, const Lugares *b) {
    Lugares *r = lugares_cria();
    if (r != NULL) {
        for (int i = 0; i < LUGARES / 8; i++) {
            r->bits[i] = a->bits[i] | b->bits[i];
        }
    }
    return r;
}

Lugares *lugares_intersecao(const Lugares *a, const Lugares *b) {
    Lugares *r = lugares_cria();
    if (r != NULL) {
        for (int i = 0; i < LUGARES / 8; i++) {
            r->bits[i] = a->bits[i] & b->bits[i];
        }
    }
    return r;
}

int lugares_bytes(void) {
    return (int) sizeof(struct lugares); // só aqui dentro a struct é conhecida
}

void lugares_libera(Lugares *l) {
    free(l);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    int tarde_v[7] = {0, 1, 2, 50, 99, 150, 199};
    int noite_v[5] = {2, 3, 50, 100, 199};
    Lugares *tarde = lugares_cria(), *noite = lugares_cria();
    if (tarde == NULL || noite == NULL) {
        lugares_libera(tarde);
        lugares_libera(noite);
        return 1;
    }
    for (int i = 0; i < 7; i++) {
        lugares_ocupa(tarde, tarde_v[i]);
    }
    for (int i = 0; i < 5; i++) {
        lugares_ocupa(noite, noite_v[i]);
    }
    printf("Tarde: %d ocupados\n", lugares_conta(tarde));
    printf("Noite: %d ocupados\n", lugares_conta(noite));

    Lugares *duas = lugares_intersecao(tarde, noite);
    Lugares *alguma = lugares_uniao(tarde, noite);
    if (duas != NULL && alguma != NULL) {
        printf("Ocupados nas duas:");
        for (int k = 0; k < 256; k++) {
            if (lugares_ocupado(duas, k)) {
                printf(" %d", k);
            }
        }
        printf("\nOcupados em alguma: %d\n", lugares_conta(alguma));
    }
    printf("Memória: %d bytes para 256 lugares\n", lugares_bytes());
    lugares_libera(tarde);
    lugares_libera(noite);
    lugares_libera(duas);
    lugares_libera(alguma);
    return 0;
}
