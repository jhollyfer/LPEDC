// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2922 · ★★★ · A dimensão trocada
//
// A cadeia tem quatro matrizes, p = 8, 20, 4, 30, 6 (Ai é p[i-1] x p[i]).
// O programa abaixo segue a recorrência do 0185, mas devolve um custo e
// uma ordem errados.
//
//   Saída que aparece:
//   Custo: 3600
//   Ordem: (A1 ((A2 A3) A4))
//
//   Saída esperada:
//   Custo: 1552
//   Ordem: ((A1 A2) (A3 A4))
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte-o.
//
// Dicas:
// 1. Juntar (Ai..Ak) com (Ak+1..Aj) é multiplicar uma matriz de quantas linhas
//    por quantas colunas?
// 2. A cadeia Ai..Aj começa com as linhas de Ai, que são p[i-1], não p[i].
// 3. Resposta esperada: a saída esperada acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <limits.h>
#include <stdio.h>

#define N 4

const int p[N + 1] = {8, 20, 4, 30, 6};
long m[N + 1][N + 1];
int s[N + 1][N + 1];

void mostra(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    mostra(i, s[i][j]);
    printf(" ");
    mostra(s[i][j] + 1, j);
    printf(")");
}

int main(void) {
    for (int t = 2; t <= N; t++)
        for (int i = 1; i + t - 1 <= N; i++) {
            int j = i + t - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long c = m[i][k] + m[k + 1][j] + (long)p[i] * p[k] * p[j];
                if (c < m[i][j]) m[i][j] = c, s[i][j] = k;
            }
        }
    printf("Custo: %ld\nOrdem: ", m[1][N]);
    mostra(1, N);
    printf("\n");
    return 0;
}
