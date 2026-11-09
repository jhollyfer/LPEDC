// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1004 · ★☆☆ · Multiplicar somando, com invariante

#include <assert.h>
#include <stdio.h>

int multiplica(int a, int b) { // b >= 0
    int r = 0;
    int i;
    for (i = 0; i < b; i++) {
        assert(r == a * i); // invariante: a já foi somado i vezes
        r = r + a;
    }
    assert(i == b && r == a * b); // término
    return r;
}

int main(void) {
    int pares[3][2] = {{7, 6}, {12, 0}, {3, 15}};
    for (int k = 0; k < 3; k++) {
        printf("%d x %d = %d\n", pares[k][0], pares[k][1], multiplica(pares[k][0], pares[k][1]));
    }
    return 0;
}
