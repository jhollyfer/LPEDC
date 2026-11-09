// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1924 · ★★★ · SEIS + SEIS = DOZE
//
// Na criptoaritmética, cada letra é um dígito, letras diferentes são
// dígitos diferentes e nenhuma palavra começa com 0. Resolva
//
//   SEIS + SEIS = DOZE
//
// Escreva do zero um backtracking que atribui dígitos às 6 letras (S, E, I,
// D, O, Z, nesta ordem), sem repetir dígito (vetor usado[10]), e confere a
// conta quando todas têm valor. Mostre todas as soluções no formato da
// saída e o total. Conte também quantas atribuições completas foram
// conferidas.
//
//   Saída esperada:
//   3643 + 3643 = 7286
//   4814 + 4814 = 9628
//   4854 + 4854 = 9708
//   4864 + 4864 = 9728
//   Soluções: 4
//   Atribuições conferidas: 120960
//
// Dicas:
// 1. Guarde o dígito de cada letra em val[6]. Uma função valor("SEIS")
//    monta o número trocando cada letra pelo seu dígito.
// 2. S e D não podem ser 0: corte na hora de atribuir.
// 3. Resposta esperada: 4 soluções e 120960 atribuições conferidas. Sem o
//    corte do zero seriam 10 · 9 · 8 · 7 · 6 · 5 = 151200.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
