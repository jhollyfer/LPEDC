// A283 · O corretor que sugere a palavra mais perto

#include <stdio.h>
#include <string.h>

#define MAX 30

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int distancia(const char *a, const char *b) {
    int m = strlen(a), n = strlen(b);
    int d[MAX + 1][MAX + 1];
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + menor3(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    return d[m][n];
}

int main(void) {
    // palavras sem acento: em UTF-8, "ç" e "ã" ocupam 2 bytes cada, e a
    // distância contaria bytes, não letras
    const char *dicionario[] = {"pessoa", "pesca", "peso", "lagoa", "pose",
                                "pessoal", "mesa", "proa", "passeio"};
    int n = 9;
    const char *digitadas[] = {"pesoa", "lagao", "pasoe"};

    for (int k = 0; k < 3; k++) {
        int melhor = MAX + 1;
        for (int p = 0; p < n; p++) {
            int dist = distancia(digitadas[k], dicionario[p]);
            if (dist < melhor) {
                melhor = dist;
            }
        }
        printf("%s -> distância %d:", digitadas[k], melhor);
        for (int p = 0; p < n; p++) {       // todas as que empatam no mínimo
            if (distancia(digitadas[k], dicionario[p]) == melhor) {
                printf(" %s", dicionario[p]);
            }
        }
        printf("\n");
    }
    return 0;
}
// Empates são comuns: corretores de verdade desempatam pela frequência de
// uso de cada palavra. E "lagao" trocou duas letras vizinhas de lugar, mas
// a distância conta 2: o A284 mostra como contar isso como 1.
// Saída:
// pesoa -> distância 1: pessoa pesca peso
// lagao -> distância 2: lagoa
// pasoe -> distância 2: peso pose
