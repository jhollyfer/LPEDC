// 0179 · Sondagem quadrática e dupla
// Exercício E1073 · ★★★
//
// Ache o bug. O guarda-volumes do supermercado tem 13 armários e usa
// sondagem quadrática: o armário do cartão k é (k % 13 + i*i) % 13, para
// i = 0, 1, 2... Os cartões 18, 31 e 44 entram (os três começam no 5). O
// cliente do 31 retira as compras e, logo depois, o caixa não acha mais o
// 44, que continua guardado. O erro está em retira(). Conserte e rode de
// novo.
//
//   Saída esperada:
//   armários: . . . . . 18 x . . 44 . . .
//   cartão 44: armário 9
//   cartão 31: não está
//
// Dicas:
// 1. Siga a busca do 44: armário 5 (18), armário 6 (era o 31), armário 9.
//    O que a busca faz quando encontra um armário LIVRE?
// 2. Um armário esvaziado no meio de uma sequência não pode parecer nunca
//    usado. É para isso que existe a terceira marca.
// 3. Resposta esperada: em retira, a marca tem que ser LAPIDE, não LIVRE
//    (a busca passa reto pela lápide). Com a correção, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

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
        a[j].estado = LIVRE;
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
