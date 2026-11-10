// 0153 · Prim: a árvore que cresce
// Exercício E916 · ★★☆
//
// A operadora de internet vai levar fibra da Central a sete pontos do bairro.
// Os pontos (índices 0 a 7) são Central, Padaria, Escola, Igreja, Farmácia,
// Praça, Posto e Clínica. Os trechos possíveis, em km:
//
//   Central-Padaria 2   Central-Escola 4   Padaria-Escola 3   Padaria-Igreja 5
//   Escola-Farmácia 2   Igreja-Praça 1     Farmácia-Praça 6   Escola-Posto 7
//   Farmácia-Clínica 3  Posto-Clínica 2    Central-Posto 9
//
// Escreva o Prim a partir da Central, guardando o pai de cada ponto em pai[].
// Depois escreva a função recursiva mostra(v, nivel), que imprime a árvore como
// um organograma: cada ponto com 2 espaços de recuo por nível e, entre
// parênteses, os km da fibra que o liga ao pai. Os filhos de um ponto aparecem
// em ordem de índice, logo abaixo dele. Termine com o total.
//
//   Saída esperada:
//   Central
//     Padaria (2)
//       Escola (3)
//         Farmácia (2)
//           Clínica (3)
//             Posto (2)
//       Igreja (5)
//         Praça (1)
//   Total: 18 km
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define INFINITO INT_MAX

int main(void) {

    return 0;
}
