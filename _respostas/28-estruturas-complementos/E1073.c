// 0179 · Sondagem quadrática e dupla
// Exercício E1073 · ★★★

#include <stdio.h>

#define M 13

enum { LIVRE, OCUPADO, LAPIDE };

typedef struct {
    int cartao, estado;
} Armario;

int posicao(int k, int i) {
    return (k % M + i * i) % M;
}

void guarda(Armario *a, int k) {
    for (int i = 0; i < M; i++) {
        int j = posicao(k, i);
        if (a[j].estado != OCUPADO) {
            a[j].cartao = k;
            a[j].estado = OCUPADO;
            return;
        }
    }
}

int acha(const Armario *a, int k) {
    for (int i = 0; i < M; i++) {
        int j = posicao(k, i);
        if (a[j].estado == LIVRE) {
            return -1;
        }
        if (a[j].estado == OCUPADO && a[j].cartao == k) {
            return j;
        }
    }
    return -1;
}

void retira(Armario *a, int k) {
    int j = acha(a, k);
    if (j >= 0) {
        a[j].estado = LAPIDE; // lápide: a busca passa reto
    }
}

void mostra_achado(const Armario *a, int k) {
    int j = acha(a, k);
    if (j >= 0) {
        printf("cartão %d: armário %d\n", k, j);
    } else {
        printf("cartão %d: não está\n", k);
    }
}

int main(void) {
    Armario a[M] = {{0, LIVRE}};
    guarda(a, 18);
    guarda(a, 31);
    guarda(a, 44);
    retira(a, 31);
    printf("armários:");
    for (int j = 0; j < M; j++) {
        if (a[j].estado == OCUPADO) {
            printf(" %d", a[j].cartao);
        } else {
            printf(" %s", a[j].estado == LIVRE ? "." : "x");
        }
    }
    printf("\n");
    mostra_achado(a, 44);
    mostra_achado(a, 31);
    return 0;
}
