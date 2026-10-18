// 0132 · Inversões e subvetor de soma máxima
// Exercício E787 · ★☆☆

#include <stdio.h>

int main(void) {
    // horário (em minutos depois das 18h) de cada entrega, na ordem da lista
    int horario[] = {14, 9, 17, 12, 20, 11, 15};
    int n = 7;
    int inversoes = 0;

    printf("Fora de ordem:");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (horario[i] > horario[j]) {
                printf(" (%d, %d)", horario[i], horario[j]);
                inversoes++;
            }
        }
    }
    printf("\nInversões: %d de %d pares\n", inversoes, n * (n - 1) / 2);
    return 0;
}
