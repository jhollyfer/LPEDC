// Lista · Módulo 03 · Laços
// Exercício P0325 · ★★★ · A rotina de Kaprekar

#include <stdio.h>

int main(void) {
    int n = 3524;
    int passos = 0;

    while (n != 6174) {
        int maior = 0, menor = 0;
        for (int v = 9; v >= 0; v--) {
            int resto = n;
            for (int k = 0; k < 4; k++) {
                if (resto % 10 == v) {
                    maior = maior * 10 + v;
                }
                resto /= 10;
            }
        }
        for (int v = 0; v <= 9; v++) {
            int resto = n;
            for (int k = 0; k < 4; k++) {
                if (resto % 10 == v) {
                    menor = menor * 10 + v;
                }
                resto /= 10;
            }
        }
        n = maior - menor;
        passos++;
        printf("%04d - %04d = %04d\n", maior, menor, n);
    }
    printf("Chegou em 6174 em %d passos\n", passos);
    return 0;
}
