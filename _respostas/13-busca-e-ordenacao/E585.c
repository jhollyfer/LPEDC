// 0098 · Insertion sort
// Exercício E585 · ★★☆

#include <stdio.h>

#define CAP 5

// top[0..n-1] está em ordem decrescente; encaixa pontos mantendo a ordem
void novo_recorde(int top[], int *n, int cap, int pontos) {
    if (*n == cap && pontos <= top[*n - 1]) {
        printf("%d: não entrou no ranking\n", pontos);
        return;
    }
    // se está cheio, o último sai: começamos a empurrar a partir do penúltimo
    int i = (*n == cap) ? *n - 2 : *n - 1;
    while (i >= 0 && top[i] < pontos) {
        top[i + 1] = top[i];
        i--;
    }
    top[i + 1] = pontos;
    if (*n < cap) {
        (*n)++;
    }
    printf("%d:", pontos);
    for (int k = 0; k < *n; k++) {
        printf(" %d", top[k]);
    }
    printf("\n");
}

int main(void) {
    int top[CAP] = {9800, 8750, 7200, 6100};
    int n = 4;

    novo_recorde(top, &n, CAP, 7500);
    novo_recorde(top, &n, CAP, 4000);
    novo_recorde(top, &n, CAP, 9900);
    return 0;
}
