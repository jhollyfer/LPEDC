// Lista · Módulo 25 · Estruturas especiais
// Exercício P2506 · ★☆☆ · Quantos nós em cada andar
//
// Na skip list, cada nó novo começa com 1 andar e sobe mais um enquanto a
// moeda der cara. Sem montar a lista, simule o sorteio de 1000 nós com a
// moeda do esqueleto (semente fixa 2026, até 16 andares) e mostre, para
// cada andar, quantos nós chegam até ele, ao lado do esperado N / 2^a.
// Mostre também o total de ponteiros (cada nó tem um por andar) e a média
// por nó.
//
//   Saída esperada:
//   andar  0: 1000 nós (esperado 1000.0)
//   andar  1:  517 nós (esperado  500.0)
//   andar  2:  255 nós (esperado  250.0)
//   andar  3:  120 nós (esperado  125.0)
//   andar  4:   67 nós (esperado   62.5)
//   andar  5:   36 nós (esperado   31.2)
//   andar  6:   17 nós (esperado   15.6)
//   andar  7:   11 nós (esperado    7.8)
//   andar  8:    2 nós (esperado    3.9)
//   andar  9:    2 nós (esperado    2.0)
//   andar 10:    2 nós (esperado    1.0)
//   Ponteiros: 2029 (2.03 por nó)
//
// Dicas:
// 1. Guarde por_andar[a] = quantos nós têm exatamente a andares. Os que
//    chegam ao andar a - 1 são N menos os que têm menos de a andares.
// 2. A média de ponteiros por nó tende a 2 (1 + 1/2 + 1/4 + ...): a skip
//    list gasta, em média, só o dobro dos ponteiros de uma lista simples.
// 3. Resposta esperada: 517 nós no andar 1, 2029 ponteiros (2.03 por nó).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define MAX 16
#define N 1000

unsigned semente = 2026;

int moeda(void) {
    semente = semente * 1103515245u + 12345u;
    return (semente >> 16) & 1;
}

int main(void) {
    printf("primeira moeda: %d\n", moeda());
    return 0;
}
