// 0157 · Força bruta
// Exercício E937 · ★☆☆

#include <stdio.h>
#include <string.h>

// mostra as posições e devolve quantas vezes padrao aparece (sobrepostas contam)
int conta_ocorrencias(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int total = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
        }
        if (j == m) {
            printf(" %d", i);
            total++;
        }
    }
    return total;
}

int main(void) {
    const char *narracao = "gol gol golaco do gol";
    const char *padroes[] = {"gol", "o"};

    for (int k = 0; k < 2; k++) {
        printf("%s:", padroes[k]);
        int t = conta_ocorrencias(narracao, padroes[k]);
        printf(" (%d vezes)\n", t);
    }
    return 0;
}
