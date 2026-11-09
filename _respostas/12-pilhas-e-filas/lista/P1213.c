// Lista · Módulo 12 · Pilhas e filas
// Exercício P1213 · ★★☆ · A caixa-preta que guarda só as últimas leituras

#include <stdio.h>

#define CAP 4

typedef struct {
    int v[CAP];
    int inicio, n;
} Buffer;

int sobrescritas = 0;

void registra(Buffer *b, int leitura) {
    if (b->n < CAP) {
        b->v[(b->inicio + b->n) % CAP] = leitura;
        b->n++;
    } else {
        b->v[b->inicio] = leitura; // a mais antiga dá lugar à nova
        b->inicio = (b->inicio + 1) % CAP;
        sobrescritas++;
    }
}

void mostra(const Buffer *b) {
    for (int k = 0; k < b->n; k++) {
        printf(k == 0 ? "%d" : " %d", b->v[(b->inicio + k) % CAP]);
    }
    printf("\n");
}

int main(void) {
    int leituras[7] = {60, 72, 80, 85, 90, 70, 65};
    Buffer caixa = {.inicio = 0, .n = 0};
    for (int i = 0; i < 7; i++) {
        registra(&caixa, leituras[i]);
        if (i == 3) {
            printf("depois de 4: ");
            mostra(&caixa);
        }
    }
    printf("no fim: ");
    mostra(&caixa);
    printf("sobrescritas: %d\n", sobrescritas);
    return 0;
}
