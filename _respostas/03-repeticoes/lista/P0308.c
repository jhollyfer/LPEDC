// Lista · Módulo 03 · Laços
// Exercício P0308 · ★☆☆ · O jogo do PIM

#include <stdio.h>

int main(void) {
    for (int n = 1; n <= 20; n++) {
        if (n % 4 == 0 || n % 10 == 4) {
            printf("PIM\n");
        } else {
            printf("%d\n", n);
        }
    }
    return 0;
}
