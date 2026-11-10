// Lista · Módulo 21 · Programação dinâmica
// Exercício P2102 · ★☆☆ · A escada com degraus quebrados
//
// A escada do mirante tem 12 degraus, e você sobe de 1 ou de 2 degraus por
// vez. Os degraus 4 e 7 estão quebrados: não dá para pisar neles. De
// quantos jeitos dá para chegar ao degrau 12, saindo do chão (degrau 0)?
// Escreva do zero a tabela de baixo para cima: formas[0] = 1 e, para cada
// degrau i, formas[i] = formas[i - 1] + formas[i - 2], menos nos quebrados,
// que ficam com 0. Mostre a tabela e a resposta.
//
//   Saída esperada:
//   degrau  0: 1
//   degrau  1: 1
//   degrau  2: 2
//   degrau  3: 3
//   degrau  4: 0
//   degrau  5: 3
//   degrau  6: 3
//   degrau  7: 0
//   degrau  8: 3
//   degrau  9: 3
//   degrau 10: 6
//   degrau 11: 9
//   degrau 12: 15
//   Jeitos de chegar ao topo: 15
//
// Dicas:
// 1. Cuidado com o degrau 1: só dá para chegar nele vindo do 0 (i - 2 seria
//    negativo).
// 2. Um vetor bool quebrado[13] deixa o teste simples.
// 3. Resposta esperada: 15 jeitos. Sem degraus quebrados seriam 233.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
