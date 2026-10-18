// 0123 · Quickselect
// Exercício E736 · ★★☆
//
// Quem cuida de servidores não olha a média do tempo de resposta, olha os
// PERCENTIS: o p90 é o tempo que 90% das requisições não ultrapassam. O
// programa abaixo gera 50 tempos (com alguns picos). Escreva
// int percentil(int v[], int n, int pct) com o quickselect e mostre p50,
// p90 e p99. Depois ordene com qsort e confira as posições 24, 44 e 49.
//
//   Saída esperada:
//   p50: 138 ms
//   p90: 630 ms
//   p99: 826 ms
//   conferindo: 138, 630 e 826
//
// Dicas:
// 1. Use a regra do "posto mais próximo": a posição do percentil pct é
//    teto(pct * n / 100) - 1. Com inteiros: (pct * n + 99) / 100 - 1.
//    Para n = 50: p50 fica na posição 24, p90 na 44 e p99 na 49.
// 2. Não precisa copiar o vetor entre um percentil e outro: o quickselect
//    só troca os valores de lugar, não muda quais valores existem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 50

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

int compara(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return (x > y) - (x < y);
}

int main(void) {
    int t[N]; // tempo de resposta do site, em milissegundos
    for (int i = 0; i < N; i++) {
        t[i] = 30 + (i * 37) % 50 * 4 + (i % 9 == 0 ? 600 : 0); // alguns picos
    }
    printf("primeiro tempo: %d ms\n", t[0]); // apague esta linha

    return 0;
}
