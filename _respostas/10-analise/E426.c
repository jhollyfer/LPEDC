// 0071 · Eficiência: contar passos
// Exercício E426 · ★★★
//
// Resposta: chamadas 177, 21891 e 2692537; somas 9, 19 e 29. A cada +1 no n,
// as chamadas multiplicam por cerca de 1,618: crescimento exponencial.

#include <stdio.h>

long chamadas = 0;
long somas = 0;

long fib_rec(int n) {
    chamadas++;
    if (n < 2) {
        return n;
    }
    return fib_rec(n - 1) + fib_rec(n - 2);
}

long fib_it(int n) {
    if (n < 2) {
        return n;
    }
    long anterior = 0, atual = 1;
    for (int i = 2; i <= n; i++) {
        long proximo = anterior + atual;
        somas++;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

int main(void) {
    int valores[3] = {10, 20, 30};

    printf("%2s %7s %9s %6s\n", "n", "fib", "chamadas", "somas");
    for (int k = 0; k < 3; k++) {
        int n = valores[k];
        chamadas = 0;
        somas = 0;
        long a = fib_rec(n);
        long b = fib_it(n);
        if (a != b) {
            printf("as duas versões discordam!\n");
        }
        printf("%2d %7ld %9ld %6ld\n", n, a, chamadas, somas);
    }
    return 0;
}
