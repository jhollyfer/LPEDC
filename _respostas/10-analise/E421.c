// 0071 · Eficiência: contar passos
// Exercício E421 · ★☆☆

#include <stdio.h>

int main(void) {
    int passos;

    passos = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            passos++;
        }
    }
    printf("a) %d\n", passos);

    passos = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            passos++;
        }
    }
    printf("b) %d\n", passos);

    passos = 0;
    for (int i = 1; i < 100; i = i * 2) {
        passos++;
    }
    printf("c) %d\n", passos);

    passos = 0;
    int voltas = 0;
    for (int i = 0; i < 10; i++) {
        voltas++;
        if (i % 3 == 0) {
            passos++;
        }
    }
    printf("d) %d passos em %d voltas\n", passos, voltas);
    return 0;
}
