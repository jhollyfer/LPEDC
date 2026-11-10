// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1704 · ★☆☆ · Contador binário: quantas vezes cada bit troca
//
// A catraca da academia conta os acessos num contador binário de 8 bits,
// guardado em int b[8] (b[0] é o bit menos significativo). Incrementar custa
// o número de bits trocados.
//
// Escreva int incrementa(int b[]) e um programa que faça 32 incrementos a
// partir de 00000000, mostrando os oito primeiros (o contador e o custo) e,
// no fim, quantas vezes CADA bit trocou, o total e o limite 2n da análise
// agregada.
//
//   Saída esperada:
//   00000001  custo 1
//   00000010  custo 2
//   00000011  custo 1
//   00000100  custo 3
//   00000101  custo 1
//   00000110  custo 2
//   00000111  custo 1
//   00001000  custo 4
//   bit 0: 32 trocas
//   bit 1: 16 trocas
//   bit 2:  8 trocas
//   bit 3:  4 trocas
//   bit 4:  2 trocas
//   bit 5:  1 trocas
//   bit 6:  0 trocas
//   bit 7:  0 trocas
//   Total: 63 trocas em 32 incrementos (limite 2n = 64)
//
// Dicas:
// 1. incrementa: enquanto b[i] == 1, zere b[i] e avance i (cada um é uma
//    troca); depois, se i < 8, b[i] = 1 (mais uma troca).
// 2. Some 1 em trocas[i] a cada troca do bit i: é a análise agregada do
//    Cormen olhando bit por bit.
// 3. O bit i troca a cada 2^i incrementos: n, n/2, n/4, ... A soma é menor
//    que 2n, então o custo amortizado é O(1) por incremento, mesmo com um
//    incremento isolado custando até 8.
// 4. Resposta esperada: o bit 0 troca 32 vezes, o bit 1 16, ..., o bit 5
//    uma vez; total 63, abaixo de 2n = 64.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define K 8

int incrementa(int b[]) {
    (void)b; // apague e escreva a função
    return 0;
}

int main(void) {
    int b[K] = {0};

    for (int i = K - 1; i >= 0; i--) printf("%d", b[i]);
    printf("\n");
    return 0;
}
