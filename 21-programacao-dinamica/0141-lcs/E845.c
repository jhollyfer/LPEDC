// 0141 · Maior subsequência comum (LCS)
// Exercício E845 · ★★★
//
// Num jogo de anagramas, a nota de "parecido" entre duas palavras é o
// tamanho da LCS: quantas letras ficam na mesma ordem. O programa abaixo
// compila sem aviso e roda sem reclamação do sanitizer, mas algumas notas
// estão erradas. Hoje ele mostra:
//
//   AMOR x ROMA: 2
//   AMOR x MORA: 3
//   AMOR x RAMO: 3
//   AMOR x OMAR: 3
//   AMOR x AMOR: 4
//
// Em ROMA, nenhum par de letras de AMOR aparece na mesma ordem, então a
// nota certa é 1. Há UM erro de propósito, numa linha só. Ache e conserte.
//
//   Saída esperada (depois de consertar):
//   AMOR x ROMA: 1
//   AMOR x MORA: 3
//   AMOR x RAMO: 3
//   AMOR x OMAR: 2
//   AMOR x AMOR: 4
//
// Dicas:
// 1. Acrescente um printf que mostre a tabela inteira de AMOR x ROMA, com a
//    letra de cada linha, e confira a última célula.
// 2. A linha i da tabela fala do prefixo de tamanho i. Qual é a ÚLTIMA
//    letra desse prefixo?
// 3. Com i = m e j = n, o que valem a[i] e b[j]? Por que isso sempre "bate"?
// 4. Resposta esperada: a comparação usa a[i] == b[j], que olha uma letra
//    adiante (e, no fim, compara '\0' com '\0', ganhando 1 de graça). O
//    certo é a[i - 1] == b[j - 1].
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

#define MAX 50

int lcs(const char *a, const char *b) {
    int m = strlen(a), n = strlen(b);
    int c[MAX + 1][MAX + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (a[i] == b[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    return c[m][n];
}

int main(void) {
    const char *base = "AMOR";
    const char *anagrama[] = {"ROMA", "MORA", "RAMO", "OMAR", "AMOR"};
    for (int k = 0; k < 5; k++) {
        printf("%s x %s: %d\n", base, anagrama[k], lcs(base, anagrama[k]));
    }
    return 0;
}
