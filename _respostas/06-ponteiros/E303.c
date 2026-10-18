// 0051 · Passagem por referência
// Exercício E303 · ★★☆

#include <stdio.h>

void extremos(const int v[], int n, int *menor, int *maior) {
    *menor = *maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *menor) {
            *menor = v[i];
        }
        if (v[i] > *maior) {
            *maior = v[i];
        }
    }
}

int main(void) {
    int temps[7] = {34, 37, 31, 39, 36, 33, 38};
    int menor, maior;

    extremos(temps, 7, &menor, &maior);
    printf("Menor: %d  Maior: %d  Amplitude: %d\n", menor, maior, maior - menor);
    return 0;
}
