// 0105 · A ideia e a função hash
// Exercício E628 · ★★☆

#include <stdio.h>

void distribui(const int codigos[], int n, int m) {
    int conta[11] = {0};
    for (int i = 0; i < n; i++) {
        conta[codigos[i] % m]++;
    }
    printf("m = %d\n", m);
    for (int b = 0; b < m; b++) {
        printf("%2d: ", b);
        for (int k = 0; k < conta[b]; k++) {
            printf("*");
        }
        printf("\n");
    }
    int vazios = 0;
    for (int b = 0; b < m; b++) {
        if (conta[b] == 0) {
            vazios++;
        }
    }
    printf("vazios: %d\n", vazios);
}

int main(void) {
    int codigos[] = {120, 350, 470, 590, 610, 230, 740, 860, 980, 440};
    distribui(codigos, 10, 10);
    distribui(codigos, 10, 11);
    return 0;
}
