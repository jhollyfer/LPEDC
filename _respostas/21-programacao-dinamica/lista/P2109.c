// Lista · Módulo 21 · Programação dinâmica
// Exercício P2109 · ★☆☆ · O maior trecho igual

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "GATTACAGGT", *b = "TTACCAGGTA";
    int m = (int)strlen(a), n = (int)strlen(b);
    int s[16][16], maior = 0, fim = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0 || a[i - 1] != b[j - 1]) {
                s[i][j] = 0;
            } else {
                s[i][j] = s[i - 1][j - 1] + 1;
                if (s[i][j] > maior) {
                    maior = s[i][j];
                    fim = i;
                }
            }
        }
    }
    printf("Maior trecho comum: %.*s (%d letras)\n", maior, a + fim - maior, maior);
    return 0;
}
