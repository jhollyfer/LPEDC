// Lista · Módulo 01 · Fundamentos de C
// Exercício P0118 · ★★☆ · A playlist da viagem

#include <stdio.h>

int main(void) {
    int m1 = 3, s1 = 45;
    int m2 = 4, s2 = 12;
    int m3 = 5, s3 = 3;

    int total = (m1 * 60 + s1) + (m2 * 60 + s2) + (m3 * 60 + s3);
    int media = total / 3;

    printf("Total: %d:%02d\n", total / 60, total % 60);
    printf("Média por música: %d:%02d\n", media / 60, media % 60);
    return 0;
}
