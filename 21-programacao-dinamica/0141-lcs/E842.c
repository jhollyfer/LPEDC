// 0141 · Maior subsequência comum (LCS)
// Exercício E842 · ★☆☆
//
// O programa abaixo monta a tabela da LCS de "PROGRAMAR" e "PAGAR" e mostra
// o tamanho. Complete o trecho marcado com COMPLETE AQUI: faça a volta pela
// tabela, de c[m][n] até a borda, preenchendo o vetor lcs de trás para a
// frente, e conte quantos passos (voltas do while) a volta deu.
//
//   Saída esperada:
//   Tamanho da LCS: 4
//   LCS: PGAR
//   Passos na volta: 10
//
// Dicas:
// 1. Letras iguais: a letra vai para lcs[--k] e você anda na diagonal
//    (i-- e j--).
// 2. Diferentes: se c[i - 1][j] >= c[i][j - 1], suba (i--); senão, vá para
//    a esquerda (j--). Use o mesmo >= da tabela.
// 3. O laço é while (i > 0 && j > 0); some 1 em passos a cada volta.
// 4. Resposta esperada: a saída acima. PAAR também tem 4 letras e é comum
//    às duas: a regra de desempate escolheu PGAR.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void) {
    const char *a = "PROGRAMAR";
    const char *b = "PAGAR";
    int m = strlen(a), n = strlen(b);
    int c[MAX + 1][MAX + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    printf("Tamanho da LCS: %d\n", c[m][n]);

    char lcs[MAX + 1];
    int k = c[m][n];
    lcs[k] = '\0';
    int i = m, j = n, passos = 0;
    // COMPLETE AQUI: a volta pela tabela

    printf("LCS: %s\n", lcs + k); // com a volta completa, k chega a 0
    printf("Passos na volta: %d\n", passos);
    (void) i; // tire estas duas linhas quando usar i e j
    (void) j;
    return 0;
}
