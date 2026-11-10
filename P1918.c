// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1918 · ★★☆ · A ordem das quadrilhas
//
// No arraial da escola, 5 quadrilhas vão se apresentar: Arrasta-Pé (A),
// Balancê (B), Caipira (C), Dendê (D) e Estrela (E). A organização tem
// duas regras: a Arrasta-Pé vem antes da Balancê (não precisa ser logo
// antes), e a Caipira e a Dendê não podem se apresentar uma logo depois da
// outra, porque dividem os mesmos sanfoneiros. Escreva do zero um
// backtracking que monta a ordem posição por posição e CORTA o ramo assim
// que uma regra é quebrada (sem esperar a ordem ficar completa). Mostre as
// 5 primeiras ordens válidas e o total.
//
//   Saída esperada:
//   ABCED
//   ABDEC
//   ACBDE
//   ACBED
//   ACEBD
//   Total: 36 ordens
//
// Dicas:
// 1. Para a regra 1, ao pôr B numa posição, confira se A já está usado.
//    Se não está, A viria depois de B: corte.
// 2. Para a regra 2, ao pôr C ou D na posição p > 0, olhe ordem[p - 1].
// 3. Resposta esperada: 36 ordens. Sem regras são 120; a regra 1 deixa 60
//    e a regra 2 tira mais 24.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
