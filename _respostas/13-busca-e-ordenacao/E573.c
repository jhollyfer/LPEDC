// 0096 · Bubble sort
// Exercício E573 · ★★☆
//
// Resposta: (1) o laço interno vai até j < n - passada + 1; na passada 1 isso
// é j < n, e v[j + 1] lê v[n], fora do vetor (o ASan acusa). O certo é
// j < n - passada. (2) A troca sem auxiliar copia v[j + 1] por cima de v[j] e
// depois copia o mesmo valor de volta: os dois ficam iguais e um número some.

#include <stdio.h>

int main(void) {
    int idades[] = {34, 19, 27, 45, 22};
    int n = 5;

    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada; j++) {
            if (idades[j] > idades[j + 1]) {
                int aux = idades[j];
                idades[j] = idades[j + 1];
                idades[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", idades[i]);
    }
    printf("\n");
    return 0;
}
