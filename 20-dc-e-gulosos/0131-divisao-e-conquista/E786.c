// 0131 · Divisão e conquista
// Exercício E786 · ★★★
//
// Multiplicação de Karatsuba. Na escola, 4321 x 8765 custa 16
// multiplicações de um dígito (cada dígito de cima com cada dígito de
// baixo). Divisão e conquista ajuda: com p = 10^(n/2), escreva
// x = a·p + b e y = c·p + d (4321 = 43·100 + 21). Então
//
//   x·y = ac·p² + (ad + bc)·p + bd
//
// São 4 produtos menores (ac, ad, bc, bd), o que não ganha nada. O truque
// de Karatsuba é que (a + b)(c + d) - ac - bd = ad + bc: bastam TRÊS
// produtos recursivos (ac, bd e (a + b)(c + d)).
//
// Complete a função karatsuba no lugar marcado com "COMPLETE AQUI". O caso
// base (um dos números com 1 dígito) multiplica direto e soma 1 em mult.
//
//   Saída esperada:
//   4321 x 8765 = 37873565
//   Conferindo: 37873565
//   Multiplicações de 1 dígito: 11 (a conta da escola faz 16)
//
// Dicas:
// 1. n é a quantidade de dígitos do MAIOR dos dois (use digitos) e
//    p = potencia10(n / 2). Depois, a = x / p, b = x % p, c = y / p,
//    d = y % p.
// 2. ac = karatsuba(a, c); bd = karatsuba(b, d);
//    meio = karatsuba(a + b, c + d) - ac - bd; resultado
//    ac * p * p + meio * p + bd.
// 3. Resposta esperada: a saída acima. São 11 e não 9 porque 87 + 65 = 152
//    tem 3 dígitos e gera um nível a mais. Para números de n dígitos o custo
//    é O(n^1,59), contra O(n²) da escola: é assim que se multiplicam números
//    com milhares de dígitos.
//
// Escreva sua resposta abaixo (complete o código):

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
        return x * y; // caso base: um dos dois tem 1 dígito
    }
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    long long x = 4321, y = 8765;
    long long r = karatsuba(x, y);
    printf("%lld x %lld = %lld\n", x, y, r);
    printf("Conferindo: %lld\n", x * y);
    printf("Multiplicações de 1 dígito: %d (a conta da escola faz 16)\n", mult);
    return 0;
}
