// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1016 · ★★☆ · Crescer de um em um ou dobrar?
//
// Um vetor que cresce com realloc precisa, quando enche, copiar os itens
// para um bloco maior. Quanto custa inserir n itens, um de cada vez, com
// cada estratégia? Simule SEM alocar nada, só contando as cópias:
//
//   long copias_mais_um(int n)  // capacidade começa em 1 e cresce de 1 em 1
//   long copias_dobra(int n)    // capacidade começa em 1 e dobra
//
// Em ambas: quando o vetor tem tam == cap itens e chega mais um, ele cresce
// e copia os tam itens que já tinha. Mostre para n = 1000 e n = 2000, e a
// média de cópias por inserção com n = 2000.
//
//   Saída esperada:
//   n = 1000: +1 copia 499500, dobrando copia 1023
//   n = 2000: +1 copia 1999000, dobrando copia 2047
//   Por inserção (n = 2000): +1 = 999.5, dobrando = 1.0
//
// Dicas:
// 1. Simule com duas variáveis, tam e cap: para cada inserção, se tam ==
//    cap, some tam às cópias e aumente cap; depois, tam++.
// 2. Crescendo de 1 em 1: 1 + 2 + ... + (n - 1) = n (n - 1) / 2 cópias,
//    O(n²) no total. Dobrando: 1 + 2 + 4 + ... < 2n, O(n) no total, O(1)
//    por inserção "em média" (o custo amortizado).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
