// 0166 · O, Ω e Θ de verdade
// Exercício E995 · ★★★

#include <stdio.h>

#define LIMITE 1000

// operações para montar a rodada do torneio com n times;
// com n ímpar, um time folga e o sistema refaz a tabela (30n a mais)
long custo(long n) {
    long base = 2 * n * n;
    if (n % 2 == 1) {
        base += 30 * n;
    }
    return base;
}

// O bug: a versão antiga devolvia o PRIMEIRO n em que valia (n = 2).
// O certo é empurrar o n0 para depois de cada falha.
long acha_n0(long c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) > c * n * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    long n0 = acha_n0(3);
    printf("custo(n) <= 3n² a partir de n0 = %ld\n", n0);

    int falhas = 0;
    for (long n = n0; n <= LIMITE; n++) {
        if (custo(n) > 3 * n * n) {
            falhas++;
        }
    }
    printf("falhas de n0 até %d: %d\n", LIMITE, falhas);
    return 0;
}
