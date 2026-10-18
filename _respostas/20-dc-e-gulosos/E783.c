// 0131 · Divisão e conquista
// Exercício E783 · ★★☆

#include <stdio.h>

static int chamadas = 0;

long long potencia(long long x, int n) {
    chamadas++;
    if (n == 0) {
        return 1;
    }
    long long metade = potencia(x, n / 2); // uma chamada só, guardada
    if (n % 2 == 0) {
        return metade * metade;
    }
    return metade * metade * x;
}

int main(void) {
    printf("3^20 = %lld\n", potencia(3, 20));
    printf("Chamadas: %d\n", chamadas);
    return 0;
}
