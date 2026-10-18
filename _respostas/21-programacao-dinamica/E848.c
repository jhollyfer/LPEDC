// 0142 · Distância de edição
// Exercício E848 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 30

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int main(void) {
    const char *a = "PATO";
    const char *b = "SAPATO";
    int m = strlen(a), n = strlen(b);
    int d[MAX + 1][MAX + 1];

    for (int i = 0; i <= m; i++) {
        d[i][0] = i; // remover as i letras de a
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j; // inserir as j letras de b
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

    printf("   -");
    for (int j = 0; j < n; j++) {
        printf(" %c", b[j]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("%c ", i == 0 ? '-' : a[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf(" %d", d[i][j]);
        }
        printf("\n");
    }
    printf("distância: %d\n", d[m][n]);
    return 0;
}
