// 0133 · Algoritmos gulosos
// Exercício E795 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int crescente(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int peso[] = {60, 95, 80, 120, 45, 70, 100, 55};
    int n = 8;
    int limite = 150;

    qsort(peso, n, sizeof peso[0], crescente);
    int leve = 0, pesado = n - 1, barcos = 0;
    while (leve <= pesado) {
        barcos++;
        if (leve < pesado && peso[leve] + peso[pesado] <= limite) {
            printf("Barco %d: %d + %d\n", barcos, peso[pesado], peso[leve]);
            leve++;
        } else {
            printf("Barco %d: %d\n", barcos, peso[pesado]);
        }
        pesado--; // o mais pesado sempre vai neste barco
    }
    printf("Total: %d barcos\n", barcos);
    return 0;
}
