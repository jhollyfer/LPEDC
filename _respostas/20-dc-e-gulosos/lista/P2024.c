// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2024 · ★★★ · O máximo de entregas no prazo

#include <stdio.h>

#define N 7

int main(void) {
    const char nome[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    const int tempo[N] = {2, 4, 3, 1, 5, 2, 3};
    const int prazo[N] = {3, 5, 6, 7, 9, 10, 11};
    int aceito[N], na = 0, soma = 0;
    for (int i = 0; i < N; i++) {
        aceito[na++] = i;
        soma += tempo[i];
        if (soma > prazo[i]) {
            int m = 0;
            for (int k = 1; k < na; k++) {
                if (tempo[aceito[k]] > tempo[aceito[m]]) {
                    m = k;
                }
            }
            printf("Descarta %c (tempo %d)\n", nome[aceito[m]], tempo[aceito[m]]);
            soma -= tempo[aceito[m]];
            for (int k = m; k + 1 < na; k++) {
                aceito[k] = aceito[k + 1];
            }
            na--;
        }
    }
    int hora = 0;
    for (int k = 0; k < na; k++) {
        hora += tempo[aceito[k]];
        printf("%c pronto às %d (prazo %d)\n", nome[aceito[k]], hora, prazo[aceito[k]]);
    }
    printf("Pedidos no prazo: %d\n", na);
    return 0;
}
