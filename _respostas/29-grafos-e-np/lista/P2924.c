// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2924 · ★★★ · Código de Gray: um ciclo hamiltoniano no hipercubo

#include <stdbool.h>
#include <stdio.h>

#define D 4
#define N (1 << D)

bool um_bit(int x, int y) {
    int z = x ^ y;
    return z != 0 && (z & (z - 1)) == 0;
}

int main(void) {
    int seq[N];
    for (int i = 0; i < N; i++) seq[i] = i ^ (i >> 1);
    for (int i = 0; i < N; i++) {
        for (int b = D - 1; b >= 0; b--) printf("%d", (seq[i] >> b) & 1);
        printf(i % 8 == 7 ? "\n" : " ");
    }
    bool visto[N] = {false}, ok = true;
    for (int i = 0; i < N; i++) {
        if (visto[seq[i]] || !um_bit(seq[i], seq[(i + 1) % N])) ok = false;
        visto[seq[i]] = true;
    }
    printf("Ciclo hamiltoniano: %s\n", ok ? "sim" : "não");
    return 0;
}
