// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2003 · ★☆☆ · Os três últimos dígitos de 3^200
//
// 3^200 tem 96 dígitos e não cabe em nenhum inteiro do C. Mas para saber
// só os três últimos dígitos basta fazer a conta módulo 1000, reduzindo
// depois de cada multiplicação: (a · b) % m = ((a % m) · (b % m)) % m.
// Complete potmod(b, e, m), a potência rápida recursiva do assunto 0131
// com o resto em cada passo, e conte as multiplicações. Mostre 3^200,
// 7^222 e 2^1000, todos módulo 1000.
//
//   Saída esperada:
//   3^200 termina em 001 (11 multiplicações)
//   7^222 termina em 049 (14 multiplicações)
//   2^1000 termina em 376 (16 multiplicações)
//
// Dicas:
// 1. potmod(b, 0, m) = 1 % m. Para e > 0: calcule meia = potmod(b, e / 2,
//    m); o resultado é meia · meia % m, e, se e for ímpar, mais uma vez
//    vezes b % m.
// 2. Use long long: 999 · 999 cabe folgado, mas o hábito evita estouro
//    quando m for grande.
// 3. Resposta esperada: 3^200 termina em 001, 7^222 em 049 e 2^1000 em
//    376; as multiplicações estão na saída de cima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int mult;

long long potmod(long long b, long long e, long long m) {
    (void)b;
    (void)e;
    (void)m;
    // COMPLETE AQUI
    return 0;
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
