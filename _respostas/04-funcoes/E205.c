// 0035 · Pré-processador: macros e #ifdef
// Exercício E205 · ★☆☆

#include <stdio.h>

#define DOBRO(x) ((x) + (x)) // agora 3 * DOBRO(4) vira 3 * ((4) + (4))
#define METADE(x) ((x) / 2)
#define TAXA 10
#define TRIPLO(x) ((x) * 3)

int main(void) {
    printf("DOBRO(4) = %d\n", DOBRO(4));
    printf("3 * DOBRO(4) = %d\n", 3 * DOBRO(4));
    printf("METADE(10 + 4) = %d\n", METADE(10 + 4));
    printf("100 + TAXA * 2 = %d\n", 100 + TAXA * 2);
    printf("TRIPLO(2 + 1) = %d\n", TRIPLO(2 + 1));
    return 0;
}
