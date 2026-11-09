// Lista · Módulo 03 · Laços
// Exercício P0317 · ★★☆ · A eleição do síndico

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int marta = 0, jorge = 0, nulos = 0;
    int voto;

    while (true) {
        printf("Voto (0 encerra): ");
        if (scanf("%d", &voto) != 1 || voto == 0) {
            break;
        }
        if (voto == 1) {
            marta++;
        } else if (voto == 2) {
            jorge++;
        } else {
            nulos++;
        }
    }

    int total = marta + jorge + nulos;
    printf("Marta: %d\n", marta);
    printf("Jorge: %d\n", jorge);
    printf("Nulos: %d (%.1f%%)\n", nulos, total > 0 ? nulos * 100.0 / total : 0.0);
    if (marta > jorge) {
        printf("Vencedor: Marta\n");
    } else if (jorge > marta) {
        printf("Vencedor: Jorge\n");
    } else {
        printf("Empate\n");
    }
    return 0;
}
