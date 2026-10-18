// pix.c · implementação de pix.h
#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

void pix_gera(Pix v[], int n, unsigned semente) {
    for (int i = 0; i < n; i++) {
        semente = semente * 1103515245u + 12345u;
        unsigned a = semente >> 8;
        semente = semente * 1103515245u + 12345u;
        unsigned b = semente >> 8;
        v[i].id = (uint32_t) (i + 1);
        v[i].segundo = (int32_t) (a % PIX_SEGUNDOS);
        // muitos Pix pequenos, poucos grandes: até R$ 99,99 ou até R$ 9999,99
        v[i].centavos = (int32_t) (b % 8 == 0 ? 1 + b % 999999 : 1 + b % 9999);
    }
}

bool pix_por_horario(Pix v[], Pix aux[], int n) {
    int *c = calloc(PIX_SEGUNDOS, sizeof(int)); // 86400 contadores: 337 KB
    if (c == NULL) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        c[v[i].segundo]++;
    }
    for (int s = 1; s < PIX_SEGUNDOS; s++) {
        c[s] += c[s - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        aux[--c[v[i].segundo]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
    free(c);
    return true;
}

void pix_por_valor(Pix v[], Pix aux[], int n) {
    for (int b = 0; b < 4; b++) {
        int desloca = 8 * b;
        int c[256] = {0};
        for (int i = 0; i < n; i++) {
            c[((uint32_t) v[i].centavos >> desloca) & 0xFF]++;
        }
        for (int x = 1; x < 256; x++) {
            c[x] += c[x - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            aux[--c[((uint32_t) v[i].centavos >> desloca) & 0xFF]] = v[i];
        }
        Pix *t = v; // troca os papéis: 4 trocas, o resultado volta para v
        v = aux;
        aux = t;
    }
}

int pix_compara_valor(const void *a, const void *b) {
    int32_t x = ((const Pix *) a)->centavos;
    int32_t y = ((const Pix *) b)->centavos;
    return (x > y) - (x < y);
}

void pix_mostra(const Pix *p) {
    printf("#%07u %02d:%02d:%02d R$ %7d,%02d\n", (unsigned) p->id, p->segundo / 3600,
           p->segundo / 60 % 60, p->segundo % 60, p->centavos / 100, p->centavos % 100);
}
