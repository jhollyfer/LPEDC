// 0158 · KMP
// Exercício E945 · ★★☆

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

int main(void) {
    const char *padrao = "erro";
    int m = (int) strlen(padrao);
    int pi[MAX];
    calcula_pi(padrao, m, pi);

    int c;                 // int, para caber o EOF
    int k = 0, linha = 1, coluna = 0, total = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            linha++;
            coluna = 0;
            k = 0;         // a palavra não atravessa a quebra de linha
            continue;
        }
        coluna++;
        while (k > 0 && c != padrao[k]) {
            k = pi[k - 1];
        }
        if (c == padrao[k]) {
            k++;
        }
        if (k == m) {
            printf("linha %d, coluna %d\n", linha, coluna - m + 1);
            total++;
            k = pi[k - 1];
        }
    }
    printf("%d ocorrências\n", total);
    return 0;
}
