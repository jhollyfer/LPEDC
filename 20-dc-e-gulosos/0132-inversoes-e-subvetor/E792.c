// 0132 · Inversões e subvetor de soma máxima
// Exercício E792 · ★★★
//
// Este programa tem um erro de propósito. Ele conta as inversões de um vetor
// de 100 000 elementos em ordem decrescente, o pior caso. A resposta certa
// é n(n - 1)/2 = 4 999 950 000. Rode com o rodar: o compilador já dá um
// warning de "integer overflow" na linha da fórmula, o
// UndefinedBehaviorSanitizer acusa "signed integer overflow" durante a
// contagem, e os números mostrados são lixo (aqui saiu 704982704). Conserte os
// tipos para a contagem caber, sem mudar o algoritmo, e mostre a conta pela
// fórmula na segunda linha, também sem estourar.
//
//   Saída esperada depois do conserto:
//   Inversões: 4999950000
//   Fórmula:   4999950000
//
// Dicas:
// 1. Um int de 32 bits vai até 2 147 483 647. Siga o caminho da contagem:
//    inv, o retorno de intercala, os retornos de conta, total.
// 2. Na fórmula, N * (N - 1) é feito em int (os dois operandos são int)
//    ANTES de qualquer conversão. Converta um dos lados antes de
//    multiplicar: (long long)N * (N - 1) / 2.
// 3. Resposta esperada: inv, os retornos de intercala e conta, as variáveis
//    esq e dir e total viram long long; o printf usa %lld. O q - i continua
//    int (cabe), e a soma promove para long long sozinha.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define N 100000

int intercala(int v[], int w[], int p, int q, int r) {
    int inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

int conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    int esq = conta(v, w, p, q);
    int dir = conta(v, w, q, r);
    return esq + dir + intercala(v, w, p, q, r);
}

int main(void) {
    int *v = malloc(N * sizeof *v);
    int *w = malloc(N * sizeof *w);
    if (v == NULL || w == NULL) {
        free(v);
        free(w);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        v[i] = N - i; // 100000, 99999, ..., 1: o pior caso
    }
    int total = conta(v, w, 0, N);
    printf("Inversões: %d\n", total);
    printf("Fórmula:   %d\n", N * (N - 1) / 2);
    free(v);
    free(w);
    return 0;
}
