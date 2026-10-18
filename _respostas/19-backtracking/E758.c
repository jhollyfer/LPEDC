// 0127 · Backtracking
// Exercício E758 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define N 6
#define VAO 100

const int larguras[N] = {45, 35, 30, 25, 20, 10};
bool leva[N];
int achadas = 0;

void tenta(int i, int soma) {
    if (soma > VAO) {
        return;
    }
    if (soma == VAO) {
        achadas++;
        int primeiro = 1;
        for (int j = 0; j < i; j++) {
            if (leva[j]) {
                printf(primeiro ? "%d" : " %d", larguras[j]);
                primeiro = 0;
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + larguras[i]);
    leva[i] = false;
    tenta(i + 1, soma);
}

int main(void) {
    tenta(0, 0);
    printf("%d combinações\n", achadas);
    return 0;
}
