// Lista · Módulo 04 · Funções e modularização
// Exercício P0411 · ★★☆ · O número do pedido ao contrário

#include <stdio.h>

int inverte(int n, int acumulado) {
    if (n == 0) {
        return acumulado;
    }
    return inverte(n / 10, acumulado * 10 + n % 10);
}

int main(void) {
    printf("12345 -> %d\n", inverte(12345, 0));
    printf("1200 -> %d\n", inverte(1200, 0));
    printf("7 -> %d\n", inverte(7, 0));
    return 0;
}
