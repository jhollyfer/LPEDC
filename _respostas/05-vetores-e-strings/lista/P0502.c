// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0502 · ★☆☆ · Procurando o código no estoque

#include <stdio.h>

int buscar(const int v[], int n, int procurado) {
    for (int i = 0; i < n; i++) {
        if (v[i] == procurado) {
            return i; // a primeira que bate encerra a busca
        }
    }
    return -1;
}

int main(void) {
    int codigos[8] = {4410, 1270, 9031, 5588, 1270, 3302, 7745, 6120};
    int pedidos[3] = {5588, 1270, 2000};

    for (int k = 0; k < 3; k++) {
        int pos = buscar(codigos, 8, pedidos[k]);
        if (pos >= 0) {
            printf("Código %d: posição %d\n", pedidos[k], pos);
        } else {
            printf("Código %d: não cadastrado\n", pedidos[k]);
        }
    }
    return 0;
}
