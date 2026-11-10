// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2811 · ★★☆ · Sondagem quadrática
//
// Refaça o estacionamento do P2809 (m = 11, placas 23, 45, 12, 34, 56, 9 e
// 1) com sondagem quadrática: h(k, i) = (k mod 11 + i * i) mod 11. Mostre a
// vaga e as sondagens de cada placa, a tabela final e o total de sondagens.
// Compare com o P2809.
//
//   Saída esperada:
//   23 -> vaga  1 (1 sondagens)
//   45 -> vaga  2 (2 sondagens)
//   12 -> vaga  5 (3 sondagens)
//   34 -> vaga 10 (4 sondagens)
//   56 -> vaga  6 (5 sondagens)
//    9 -> vaga  9 (1 sondagens)
//    1 -> vaga  4 (6 sondagens)
//   tabela: . 23 45 . 1 12 56 . . 9 34
//   total de sondagens: 22
//
// Dicas:
// 1. A placa que começa no 1 tenta 1, 2, 5, 10, 6 (1 + 16 = 17), ...
// 2. O total é o mesmo da linear (22) neste caso. O bloco de vagas seguidas
//    some, mas todas as placas que começam no 1 seguem a mesma trilha
//    (agrupamento secundário).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
