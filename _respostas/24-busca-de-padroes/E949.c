// 0159 · Horspool
// Exercício E949 · ★☆☆

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

void monta_saltos(const char *p, int m, int salto[]) {
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) p[j]] = m - 1 - j;   // a mais à direita vence
    }
}

int main(void) {
    int salto[ALFABETO];
    monta_saltos("PIPOCA", 6, salto);
    printf("P=%d I=%d O=%d C=%d A=%d outras=%d\n",
           salto['P'], salto['I'], salto['O'], salto['C'], salto['A'], salto['X']);
    monta_saltos("ARARA", 5, salto);
    printf("A=%d R=%d outras=%d\n", salto['A'], salto['R'], salto['X']);
    return 0;
}
