// 0055 · Ponteiro para função
// Exercício E330 · ★★★

#include <stdio.h>
#include <stdlib.h>

static int alvo = 50;

int por_distancia(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    int dx = abs(x - alvo);
    int dy = abs(y - alvo);
    if (dx != dy) {
        return (dx > dy) - (dx < dy);
    }
    return (x > y) - (x < y);
}

void mostra(const int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void) {
    int precos[7] = {47, 58, 50, 39, 53, 61, 44};

    qsort(precos, 7, sizeof precos[0], por_distancia);
    mostra(precos, 7);

    alvo = 60;
    qsort(precos, 7, sizeof precos[0], por_distancia);
    mostra(precos, 7);
    return 0;
}
