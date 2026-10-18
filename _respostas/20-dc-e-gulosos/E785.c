// 0131 · Divisão e conquista
// Exercício E785 · ★★★

#include <stdio.h>

typedef struct {
    long long a, b, c, d; // | a b |
                          // | c d |
} Matriz;

static int produtos = 0;

Matriz multiplica(Matriz x, Matriz y) {
    produtos++;
    Matriz r;
    r.a = x.a * y.a + x.b * y.c;
    r.b = x.a * y.b + x.b * y.d;
    r.c = x.c * y.a + x.d * y.c;
    r.d = x.c * y.b + x.d * y.d;
    return r;
}

// m elevada a n, com a mesma ideia da potência rápida
Matriz potencia(Matriz m, int n) {
    if (n == 0) {
        return (Matriz){1, 0, 0, 1};    // identidade: o "1" das matrizes
    }
    Matriz metade = potencia(m, n / 2);
    Matriz r = multiplica(metade, metade);
    if (n % 2 == 1) {
        r = multiplica(r, m);
    }
    return r;
}

// F(n) é o elemento b de [[1 1] [1 0]]^n
long long fib(int n) {
    Matriz base = {1, 1, 1, 0};
    return potencia(base, n).b;
}

int main(void) {
    int pedidos[] = {10, 50, 90};
    for (int i = 0; i < 3; i++) {
        produtos = 0;
        long long f = fib(pedidos[i]);
        printf("F(%d) = %lld (%d produtos de matriz)\n", pedidos[i], f, produtos);
    }
    return 0;
}
