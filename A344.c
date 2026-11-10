// A344 · A matriz grande vai para o heap

#include <stdio.h>
#include <stdlib.h>

// a função não sabe se a matriz veio da pilha ou do heap: tanto faz
long long somar(int l, int c, int m[l][c]) {
    long long soma = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            soma += m[i][j];
        }
    }
    return soma;
}

int main(void) {
    int l = 2000, c = 1000; // 2 milhões de int: 8 MB, a pilha inteira

    // int m[l][c]; aqui derrubaria o programa. No heap, cabe:
    // m é um ponteiro para linhas de c int (um tipo VLA)
    int (*m)[c] = malloc(l * sizeof *m);
    if (m == NULL) {
        printf("sem memória\n"); // o malloc avisa; o VLA não avisaria
        return 1;
    }
    printf("sizeof *m = %zu bytes por linha\n", sizeof *m);
    printf("total = %zu bytes\n", l * sizeof *m);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = i + j; // continua m[i][j], como numa matriz comum
        }
    }
    printf("m[1999][999] = %d\n", m[1999][999]);
    printf("soma = %lld\n", somar(l, c, m));

    free(m); // um malloc, um free: a matriz é um bloco só
    return 0;
}
// Saída:
// sizeof *m = 4000 bytes por linha
// total = 8000000 bytes
// m[1999][999] = 2998
// soma = 2998000000
