// 0131 · Divisão e conquista
// Exercício E786 · ★★★

#include <stdio.h>

static int mult = 0; // multiplicações de um dígito por um dígito

int digitos(long long x) {
    int d = 1;
    while (x >= 10) {
        x /= 10;
        d++;
    }
    return d;
}

long long potencia10(int k) {
    long long p = 1;
    for (int i = 0; i < k; i++) {
        p *= 10;
    }
    return p;
}

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        mult++;
        return x * y;                           // caso base: um dos dois tem 1 dígito
    }
    int n = digitos(x) > digitos(y) ? digitos(x) : digitos(y);
    long long p = potencia10(n / 2);
    long long a = x / p, b = x % p;             // x = a·p + b
    long long c = y / p, d = y % p;             // y = c·p + d
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long meio = karatsuba(a + b, c + d) - ac - bd; // = ad + bc
    return ac * p * p + meio * p + bd;
}

int main(void) {
    long long x = 4321, y = 8765;
    long long r = karatsuba(x, y);
    printf("%lld x %lld = %lld\n", x, y, r);
    printf("Conferindo: %lld\n", x * y);
    printf("Multiplicações de 1 dígito: %d (a conta da escola faz 16)\n", mult);
    return 0;
}
