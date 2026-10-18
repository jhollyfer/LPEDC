// 0118 · Juntando tudo
// Exercício E707 · ★★★
//
// As bibliotecas de verdade não usam merge sort "puro": quando o pedaço
// fica pequeno, trocam para o insertion sort, que não tem recursão nem
// cópia para o rascunho. Estenda a função hibrido (hoje um merge sort
// comum): escreva insertion_trecho(v, p, r), que ordena só v[p..r-1], e
// faça hibrido chamá-la quando o pedaço tiver menos de limiar elementos.
// O main já mede comparações e tempo para vários limiares, com 200 mil
// números sorteados:
//
//   Saída esperada (os tempos variam; as comparações, não):
//   L =   1:  3272603 comparações,   54.5 ms
//   L =   8:  3315173 comparações,   51.0 ms
//   L =  16:  3478137 comparações,   49.7 ms
//   L =  32:  3925760 comparações,   49.8 ms
//   L =  64:  4963872 comparações,   54.2 ms
//   L = 256: 11917965 comparações,   97.4 ms
//
// Dicas:
// 1. insertion_trecho é o insertion de sempre, mas o laço vai de p + 1 até
//    r - 1 e o while para em j >= p (e não em j >= 0).
// 2. Use a função menor() nas comparações do insertion também, para a
//    contagem ser justa.
// 3. Resposta esperada: as comparações acima. Repare: as comparações SOBEM
//    com o limiar (o insertion compara mais que o merge), mas o tempo
//    costuma CAIR até uns 16 ou 32, porque cada comparação do insertion
//    sai mais barata que a recursão e a cópia do merge. Com 256, o Θ(n²)
//    dos pedaços já pesa. Comparações são um bom modelo, mas não são tudo.
//
// Escreva sua resposta abaixo (estenda hibrido):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 200000

long comparacoes = 0;
int limiar = 1; // pedaços com menos que isso vão para o insertion (ainda não usado)

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

void hibrido(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    hibrido(v, w, p, q);
    hibrido(v, w, q, r);
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        w[k++] = menor(v[j], v[i]) ? v[j++] : v[i++];
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    memcpy(v + p, w, (r - p) * sizeof *v);
}

int main(void) {
    int *original = malloc(N * sizeof *original), *v = malloc(N * sizeof *v), *w = malloc(N * sizeof *w);
    if (original == NULL || v == NULL || w == NULL) {
        return 1;
    }
    unsigned s = 11;
    for (int i = 0; i < N; i++) {
        s = s * 1103515245u + 12345u;
        original[i] = (int)(s >> 8);
    }
    int limiares[] = {1, 8, 16, 32, 64, 256};
    for (int t = 0; t < 6; t++) {
        limiar = limiares[t];
        memcpy(v, original, N * sizeof *v);
        comparacoes = 0;
        clock_t ini = clock();
        hibrido(v, w, 0, N);
        double ms = 1000.0 * (clock() - ini) / CLOCKS_PER_SEC;
        int ok = 1;
        for (int i = 1; i < N; i++) {
            if (v[i] < v[i - 1]) {
                ok = 0;
            }
        }
        printf("L = %3d: %8ld comparações, %6.1f ms%s\n", limiar, comparacoes, ms, ok ? "" : " ERRADO");
    }
    free(original);
    free(v);
    free(w);
    return 0;
}
