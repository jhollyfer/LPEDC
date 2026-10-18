// 0076 · Eficiência: contar passos
// Exercício E454 · ★★☆
//
// Resposta: ingênuo 95, 995, 9971; esperto 8, 30, 98.

#include <stdbool.h>
#include <stdio.h>

int passos_ingenuo = 0;
int passos_esperto = 0;

bool primo_ingenuo(int n) {
    for (int d = 2; d < n; d++) {
        passos_ingenuo++;
        if (n % d == 0) {
            return false;
        }
    }
    return n >= 2;
}

bool primo_esperto(int n) {
    for (int d = 2; d * d <= n; d++) {
        passos_esperto++;
        if (n % d == 0) {
            return false;
        }
    }
    return n >= 2;
}

int main(void) {
    int numeros[3] = {97, 997, 9973};

    printf("    n  ingênuo  esperto\n"); // ê ocupa 2 bytes: cabeçalho fixo
    for (int k = 0; k < 3; k++) {
        passos_ingenuo = 0;
        passos_esperto = 0;
        primo_ingenuo(numeros[k]);
        primo_esperto(numeros[k]);
        printf("%5d %8d %8d\n", numeros[k], passos_ingenuo, passos_esperto);
    }
    return 0;
}
