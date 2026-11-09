// Lista · Módulo 15 · Tabelas hash
// Exercício P1506 · ★☆☆ · O fator de carga subindo

#include <stdio.h>

#define M 5

int main(void) {
    int tamanho[M] = {0}; // só o comprimento de cada corrente interessa aqui
    int senhas[] = {12, 7, 30, 22, 15, 9, 41, 3, 17, 25};
    int n = 0;

    for (int i = 0; i < 10; i++) {
        tamanho[senhas[i] % M]++;
        n++;
        int maior = 0;
        for (int b = 0; b < M; b++) {
            if (tamanho[b] > maior) {
                maior = tamanho[b];
            }
        }
        printf("n = %2d: alfa = %.1f, maior corrente = %d\n", n, (double)n / M, maior);
    }
    return 0;
}
