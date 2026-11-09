// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2003 · ★☆☆ · Os três últimos dígitos de 3^200

#include <stdio.h>

int mult;

long long potmod(long long b, long long e, long long m) {
    if (e == 0) {
        return 1 % m;
    }
    long long meia = potmod(b, e / 2, m);
    long long r = meia * meia % m;
    mult++;
    if (e % 2 == 1) {
        r = r * (b % m) % m;
        mult++;
    }
    return r;
}

int main(void) {
    const long long base[3] = {3, 7, 2}, expo[3] = {200, 222, 1000};
    for (int i = 0; i < 3; i++) {
        mult = 0;
        long long r = potmod(base[i], expo[i], 1000);
        printf("%lld^%lld termina em %03lld (%d multiplicações)\n", base[i], expo[i], r, mult);
    }
    return 0;
}
