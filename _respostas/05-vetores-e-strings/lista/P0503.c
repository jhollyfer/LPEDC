// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0503 · ★☆☆ · A fila ao contrário

#include <stdio.h>

void inverter(int v[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i; // o par de i, contado do fim
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

void mostrar(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
    }
}

int main(void) {
    int senhas[] = {101, 102, 105, 108, 110, 113, 117};
    int n = sizeof senhas / sizeof senhas[0];

    printf("Antes:  ");
    mostrar(senhas, n);
    inverter(senhas, n);
    printf("Depois: ");
    mostrar(senhas, n);
    return 0;
}
