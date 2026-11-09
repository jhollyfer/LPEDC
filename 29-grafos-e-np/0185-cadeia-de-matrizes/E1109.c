// 0185 · Cadeia de matrizes
// Exercício E1109 · ★★★
//
// Ache o bug. Este programa calcula a cadeia do texto (p = 10, 30, 5, 60,
// 10), mas preenche a tabela linha por linha. Ele diz que dá para fazer
// tudo com 2000 multiplicações, menos do que o ótimo de verdade:
//
//   Saída que aparece:
//   m[1][3] = 4500
//   m[1][4] = 2000 (corte em k = 2)
//
//   Saída esperada:
//   m[1][3] = 4500
//   m[1][4] = 5000 (corte em k = 2)
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte-o
// mudando só a ordem dos laços (a recorrência está certa).
//
// Dicas:
// 1. Ao calcular m[1][4] com k = 2, o programa precisa de m[3][4]. Em que
//    momento a linha 3 é preenchida?
// 2. Casas ainda não calculadas valem 0 (a matriz é global): elas fingem
//    que a metade de baixo é de graça.
// 3. Resposta esperada: a saída esperada acima. Percorra as linhas de
//    baixo para cima (i de N até 1) ou faça o laço externo pelo tamanho.
//
// Escreva sua resposta abaixo (conserte o código):

#include <limits.h>
#include <stdio.h>

#define N 4

const int p[N + 1] = {10, 30, 5, 60, 10};
long m[N + 1][N + 1];
int s[N + 1][N + 1];

int main(void) {
    for (int i = 1; i <= N; i++) {       // linha por linha...
        for (int j = i + 1; j <= N; j++) { // ...e coluna por coluna
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long custo = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (custo < m[i][j]) {
                    m[i][j] = custo;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("m[1][3] = %ld\n", m[1][3]);
    printf("m[1][4] = %ld (corte em k = %d)\n", m[1][4], s[1][4]);
    return 0;
}
