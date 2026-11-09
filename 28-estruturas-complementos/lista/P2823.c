// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2823 · ★★★ · O passo zero da dispersão dupla
//
// Ache o bug. O guarda-volumes usa dispersão dupla com m = 11: h1(k) =
// k mod 11 e um passo h2(k). Entram os cartões 21, 32, 10 e 43, todos com h1 = 10.
// O cartão 10 "não coube", com a tabela quase vazia. O erro está em UMA
// conta do passo. Conserte e rode de novo.
//
//   Saída esperada:
//   21: passo 2 -> 10
//   32: passo 3 -> 2
//   10: passo 1 -> 0
//   43: passo 4 -> 3
//   tabela: 10 . 32 43 . . . . . . 21
//
// Dicas:
// 1. Calcule o passo do cartão 10 com o código como está. O que acontece
//    com h1 + i · 0?
// 2. O passo nunca pode ser 0 e tem que ser primo com m.
// 3. Resposta esperada: o passo é 1 + k % (M - 1), não k % (M - 1). Com a
//    correção, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define M 11

int passo(int k) {
    return k % (M - 1);
}

int main(void) {
    int t[M];
    for (int j = 0; j < M; j++) {
        t[j] = -1;
    }
    int cartoes[] = {21, 32, 10, 43};
    for (int c = 0; c < 4; c++) {
        int k = cartoes[c];
        int guardado = 0;
        for (int i = 0; i < M && !guardado; i++) {
            int j = (k % M + i * passo(k)) % M;
            if (t[j] == -1) {
                t[j] = k;
                guardado = 1;
                printf("%2d: passo %d -> %d\n", k, passo(k), j);
            }
        }
        if (!guardado) {
            printf("%2d: passo %d -> não coube\n", k, passo(k));
        }
    }
    printf("tabela:");
    for (int j = 0; j < M; j++) {
        if (t[j] == -1) {
            printf(" .");
        } else {
            printf(" %d", t[j]);
        }
    }
    printf("\n");
    return 0;
}
