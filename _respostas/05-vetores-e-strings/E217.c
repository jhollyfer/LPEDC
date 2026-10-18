// 0037 · Vetores
// Exercício E217 · ★☆☆

#include <stdio.h>

int main(void) {
    int max[7] = {19, 23, 21, 17, 15, 18, 22};

    for (int i = 6; i >= 0; i--) {
        printf("Dia %d: %d graus\n", i + 1, max[i]);
    }
    return 0;
}
