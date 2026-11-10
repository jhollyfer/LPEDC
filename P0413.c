// Lista · Módulo 04 · Funções e modularização
// Exercício P0413 · ★★☆ · Quantas chamadas custa uma combinação
//
// De quantas formas dá para escolher k pessoas de um grupo de n? É a
// combinação C(n, k), e ela tem uma definição recursiva: C(n, 0) = C(n, n) = 1
// e C(n, k) = C(n − 1, k − 1) + C(n − 1, k). Escreva essa função recursiva e
// conte, com uma variável global, quantas chamadas ela faz para C(5, 2),
// C(10, 5) e C(20, 10) (zere o contador antes de cada uma):
//
//   Saída esperada:
//   C(5, 2) = 10 com 19 chamadas
//   C(10, 5) = 252 com 503 chamadas
//   C(20, 10) = 184756 com 369511 chamadas
//
// Dicas:
// 1. A primeira linha da função é chamadas++;.
// 2. As chamadas são sempre 2 × C(n, k) − 1, porque cada folha da recursão
//    devolve 1.
// 3. Para C(60, 6), a combinação da Mega-Sena, seriam mais de 100 milhões de
//    chamadas: não rode.
// 4. Resposta esperada: 19, 503 e 369511 chamadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
