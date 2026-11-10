// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2726 · ★★★ · A tabela do campeonato com qsort
//
// Com typedef struct { char nome[16]; int pontos; int saldo; } Time; e
// typedef enum { POR_PONTOS, POR_NOME } Criterio;, escreva duas comparadoras
// para o qsort e uma função void ordenar(Time v[], int n, Criterio c) que
// escolhe a comparadora com um switch, guardando-a num ponteiro para função.
// Por pontos: mais pontos primeiro; no empate, maior saldo.
//
//   Times: Remo (10, +3), Paysandu (12, +5), Nacional (10, +6), Fast (7, -2)
//
//   Saída esperada:
//   por pontos: Paysandu 12, Nacional 10, Remo 10, Fast 7
//   por nome: Fast 7, Nacional 10, Paysandu 12, Remo 10
//
// Dicas:
// 1. A comparadora recebe const void *: converta com
//    const Time *x = a;
// 2. int (*cmp)(const void *, const void *) = NULL; e, no switch,
//    cmp = comparar_pontos;
// 3. Para "mais pontos primeiro", devolva y->pontos - x->pontos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
