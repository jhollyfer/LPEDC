// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2623 · ★★★ · Raiz contra logaritmo

#include <stdio.h>
#include <math.h>

#define LIMITE 1000000

int main(void) {
    int cs[] = {1, 2, 5, 10};
    for (int k = 0; k < 4; k++) {
        long ultimo_ok = 0;
        for (long n = 2; n <= LIMITE; n++) {
            if (sqrt((double)n) <= cs[k] * log2((double)n)) {
                ultimo_ok = n;
            }
        }
        printf("c = %2d: falha de n = %ld em diante\n", cs[k], ultimo_ok + 1);
    }
    printf("sqrt(n) / log2(n) em n = %d: %.1f\n", LIMITE, sqrt(LIMITE) / log2(LIMITE));
    return 0;
}
