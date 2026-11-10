// Lista · Módulo 21 · Programação dinâmica
// Exercício P2108 · ★☆☆ · A tabela da LCS na tela
//
// Para entender a LCS de verdade, vale ver a tabela. O programa abaixo
// calcula a LCS de ARARA e ARAPUA e mostra só o tamanho. Instrumente-o:
// mostre a tabela inteira, com as letras de B no cabeçalho e as de A na
// frente de cada linha, como na saída. A linha 0 e a coluna 0 (a palavra
// vazia) também aparecem.
//
//   Saída esperada:
//        -  A  R  A  P  U  A
//     -  0  0  0  0  0  0  0
//     A  0  1  1  1  1  1  1
//     R  0  1  2  2  2  2  2
//     A  0  1  2  3  3  3  3
//     R  0  1  2  3  3  3  3
//     A  0  1  2  3  3  3  4
//   LCS de ARARA e ARAPUA: 4 letras
//
// Dicas:
// 1. Cabeçalho: printf("   %3c", '-') faz a margem e a coluna vazia; depois,
//    cada letra de B com printf("%3c", b[j]).
// 2. Cada linha i começa com a letra a[i - 1] (ou '-' na linha 0) e segue
//    com t[i][j] em %3d.
// 3. Resposta esperada: a tabela de cima, com 4 no canto (ARAA, por
//    exemplo, é comum às duas).
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "ARARA", *b = "ARAPUA";
    int m = (int)strlen(a), n = (int)strlen(b);
    int t[8][8];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                t[i][j] = t[i - 1][j - 1] + 1;
            } else {
                t[i][j] = t[i - 1][j] > t[i][j - 1] ? t[i - 1][j] : t[i][j - 1];
            }
        }
    }
    printf("LCS de %s e %s: %d letras\n", a, b, t[m][n]);
    return 0;
}
