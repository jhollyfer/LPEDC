// Lista · Módulo 03 · Laços
// Exercício P0303 · ★☆☆ · As filas possíveis no banco

#include <stdio.h>

int main(void) {
    unsigned long long fat10 = 1;
    for (int i = 2; i <= 10; i++) {
        fat10 *= i;
    }

    unsigned long long fat20 = 1;
    for (int i = 2; i <= 20; i++) {
        fat20 *= i;
    }

    printf("10! = %llu\n", fat10);
    printf("20! = %llu\n", fat20);
    return 0;
}
