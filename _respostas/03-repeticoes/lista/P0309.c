// Lista · Módulo 03 · Laços
// Exercício P0309 · ★☆☆ · O mapa da sala de cinema

#include <stdio.h>

int main(void) {
    for (char fila = 'A'; fila <= 'E'; fila++) {
        for (int cadeira = 1; cadeira <= 6; cadeira++) {
            if (cadeira > 1) {
                printf(" ");
            }
            printf("%c%d", fila, cadeira);
        }
        printf("\n");
    }
    return 0;
}
