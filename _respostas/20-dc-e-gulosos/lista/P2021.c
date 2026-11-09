// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2021 · ★★★ · Karatsuba contra os quatro produtos

#include <stdio.h>

long long contagem;

int digitos(long long x) {
    int d = 1;
    while (x >= 10) {
        x /= 10;
        d++;
    }
    return d;
}

long long pot10(int k) {
    long long p = 1;
    while (k-- > 0) {
        p *= 10;
    }
    return p;
}

long long quatro(long long x, long long y) {
    if (x < 10 || y < 10) {
        contagem++;
        return x * y;
    }
    int n = digitos(x) > digitos(y) ? digitos(x) : digitos(y);
    long long p = pot10(n / 2);
    long long a = x / p, b = x % p, c = y / p, d = y % p;
    long long ac = quatro(a, c), ad = quatro(a, d), bc = quatro(b, c), bd = quatro(b, d);
    return ac * p * p + (ad + bc) * p + bd;
}

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        contagem++;
        return x * y;
    }
    int n = digitos(x) > digitos(y) ? digitos(x) : digitos(y);
    long long p = pot10(n / 2);
    long long a = x / p, b = x % p, c = y / p, d = y % p;
    long long ac = karatsuba(a, c), bd = karatsuba(b, d);
    long long meio = karatsuba(a + b, c + d) - ac - bd;
    return ac * p * p + meio * p + bd;
}

int main(void) {
    const long long xs[2] = {12345678, 99999999}, ys[2] = {87654321, 99999999};
    for (int i = 0; i < 2; i++) {
        contagem = 0;
        long long r4 = quatro(xs[i], ys[i]);
        long long c4 = contagem;
        contagem = 0;
        long long rk = karatsuba(xs[i], ys[i]);
        printf("%lld x %lld = %lld\n", xs[i], ys[i], rk);
        printf("  4 produtos: %lld multiplicações (resultado %s)\n", c4, r4 == xs[i] * ys[i] ? "certo" : "errado");
        printf("  Karatsuba: %lld multiplicações (resultado %s)\n", contagem, rk == xs[i] * ys[i] ? "certo" : "errado");
    }
    return 0;
}
