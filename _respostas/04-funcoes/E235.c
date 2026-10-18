// 0040 · Pré-processador: macros e #ifdef
// Exercício E235 · ★☆☆
//
// Resposta:
//   DOBRO(4)        -> 4 + 4               = 8
//   3 * DOBRO(4)    -> 3 * 4 + 4           = 16 (e não 24)
//   METADE(10 + 4)  -> ((10 + 4) / 2)      = 7
//   100 + TAXA * 2  -> 100 + 10 * 2        = 120

#include <stdio.h>

#define DOBRO(x) x + x
#define METADE(x) ((x) / 2)
#define TAXA 10

int main(void) {
    printf("%d\n", DOBRO(4));
    printf("%d\n", 3 * DOBRO(4));
    printf("%d\n", METADE(10 + 4));
    printf("%d\n", 100 + TAXA * 2);
    return 0;
}
