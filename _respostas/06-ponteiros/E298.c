// 0050 · Ponteiro para função
// Exercício E298 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alfabetica(const void *a, const void *b) {
    const char *x = *(const char * const *)a;
    const char *y = *(const char * const *)b;
    return strcmp(x, y);
}

int main(void) {
    const char *frutas[] = {"manga", "abacaxi", "caju", "banana", "acerola"};
    int n = (int)(sizeof frutas / sizeof frutas[0]);

    qsort(frutas, (size_t)n, sizeof frutas[0], alfabetica);
    for (int i = 0; i < n; i++) {
        printf("%s ", frutas[i]);
    }
    printf("\n");
    return 0;
}
