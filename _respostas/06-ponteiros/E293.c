// 0049 · Ponteiro para ponteiro
// Exercício E293 · ★★★

#include <stdio.h>

void troca_ptr(int **a, int **b) {
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int j1 = 9, j2 = 7, j3 = 10, j4 = 8;
    int *ordem[4] = {&j1, &j2, &j3, &j4};

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (*ordem[j] < *ordem[i]) {
                troca_ptr(&ordem[i], &ordem[j]);
            }
        }
    }

    printf("Em ordem:");
    for (int i = 0; i < 4; i++) {
        printf(" %d", *ordem[i]);
    }
    printf("\nOriginais: j1=%d j2=%d j3=%d j4=%d\n", j1, j2, j3, j4);
    return 0;
}
