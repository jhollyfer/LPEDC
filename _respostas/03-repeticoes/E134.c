// 0023 · Break e continue
// Exercício E134 · ★☆☆

#include <stdio.h>

int main(void) {
    int pulos = 0;
    for (int i = 1; i <= 10; i++) {
        if (i % 4 == 0) {
            pulos++;
            continue;
        }
        if (i == 7) {
            break;
        }
        printf("%d ", i);
    }
    printf("(continue: %d vez)\n", pulos);

    pulos = 0;
    for (int i = 1; i <= 10; i++) {
        if (i % 4 == 0) {
            pulos++;
            continue; // pega o 8 antes do break
        }
        if (i == 8) {
            break;
        }
        printf("%d ", i);
    }
    printf("(continue: %d vezes)\n", pulos);
    return 0;
}
