// A179 · Um milhão de notas fiscais

#include <stdio.h>

#define N 1000000

int sequencial(const int v[], int n, int x, long *passos) {
    *passos = 0;
    for (int i = 0; i < n; i++) {
        (*passos)++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int binaria(const int v[], int n, int x, long *passos) {
    int ini = 0, fim = n - 1;
    *passos = 0;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        (*passos)++;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    static int notas[N];              // 4 MB: static, fora da pilha
    for (int i = 0; i < N; i++) {
        notas[i] = 500000 + 3 * i;    // números das notas, em ordem crescente
    }
    // a primeira, uma do meio, a última e uma que não existe
    int procuradas[] = {500000, 2000000, 3499997, 2000001};
    long ps, pb;

    printf("    nota   posição  sequencial  binária\n");
    for (int k = 0; k < 4; k++) {
        int pos = sequencial(notas, N, procuradas[k], &ps);
        binaria(notas, N, procuradas[k], &pb);
        printf("%8d  %8d  %10ld  %7ld\n", procuradas[k], pos, ps, pb);
    }
    return 0;
}
// Saída (a binária nunca passa de 20 voltas: 2^20 > 1 milhão):
//     nota   posição  sequencial  binária
//   500000         0           1       19
//  2000000    500000      500001       19
//  3499997    999999     1000000       20
//  2000001        -1     1000000       20
