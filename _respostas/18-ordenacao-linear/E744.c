// 0124 · Juntando tudo
// Exercício E744 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pix.h"

#define N 1000000

// radix pelo valor que pula as passadas inúteis: se todos os valores têm o
// mesmo byte b, a passada desse byte não muda nada. Devolve quantas fez
int radix_esperto(Pix v[], Pix aux[], int n) {
    Pix *origem = v, *destino = aux;
    int feitas = 0;
    for (int b = 0; b < 4; b++) {
        int desloca = 8 * b;
        int c[256] = {0};
        for (int i = 0; i < n; i++) {
            c[((uint32_t) origem[i].centavos >> desloca) & 0xFF]++;
        }
        bool inutil = false;
        for (int x = 0; x < 256; x++) {
            if (c[x] == n) {
                inutil = true;  // todo mundo no mesmo balde
            }
        }
        if (inutil) {
            continue;
        }
        for (int x = 1; x < 256; x++) {
            c[x] += c[x - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            destino[--c[((uint32_t) origem[i].centavos >> desloca) & 0xFF]] = origem[i];
        }
        Pix *t = origem;
        origem = destino;
        destino = t;
        feitas++;
    }
    if (origem != v) {          // número ímpar de passadas: o resultado está em aux
        memcpy(v, origem, n * sizeof(Pix));
    }
    return feitas;
}

bool mesmos_ids(const Pix a[], const Pix b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].id != b[i].id) {
            return false;
        }
    }
    return true;
}

void testa(const char *nome, Pix a[], Pix b[], Pix aux[], int n) {
    memcpy(b, a, n * sizeof(Pix));
    int feitas = radix_esperto(a, aux, n);
    pix_por_valor(b, aux, n);
    printf("%s %d passada%s de 4, igual ao pix_por_valor? %s\n", nome, feitas,
           feitas == 1 ? "" : "s", mesmos_ids(a, b, n) ? "sim" : "não");
}

int main(void) {
    Pix *a = malloc(N * sizeof(Pix));
    Pix *b = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    if (a == NULL || b == NULL || aux == NULL) {
        free(a);
        free(b);
        free(aux);
        return 1;
    }
    pix_gera(a, N, 2024);
    testa("valores do dia:     ", a, b, aux, N);

    pix_gera(a, N, 2024);
    for (int i = 0; i < N; i++) {
        a[i].centavos %= 256;   // só até R$ 2,55: cabe num byte
    }
    testa("valores até R$ 2,55:", a, b, aux, N);
    free(a);
    free(b);
    free(aux);
    return 0;
}
