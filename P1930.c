// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1930 · ★★★ · Quantos caminhões?
//
// A transportadora precisa levar 9 cargas de 5, 4, 3, 3, 3, 3, 3, 3 e 2
// toneladas em caminhões de 10 toneladas. Este é o EMPACOTAMENTO (bin
// packing). Escreva do zero duas soluções e compare:
//
// (a) o guloso "primeiro que cabe, em ordem decrescente": cada carga vai
//     para o primeiro caminhão em que ainda cabe; se não cabe em nenhum,
//     abre um novo;
// (b) o backtracking com poda: cada carga tenta cada caminhão aberto e um
//     caminhão novo; corte o ramo quando o número de caminhões abertos já
//     não é menor que o melhor achado.
//
// Mostre quantos caminhões cada um usa e a divisão do ótimo.
//
//   Saída esperada:
//   Guloso: 4 caminhões
//   Ótimo: 3 caminhões
//   Caminhão 1: 5 3 2 (10 t)
//   Caminhão 2: 4 3 3 (10 t)
//   Caminhão 3: 3 3 3 (9 t)
//
// Dicas:
// 1. Comece o melhor com N (um caminhão por carga) e atualize quando a
//    carga N - 1 for colocada. Guarde a divisão em melhor_cam[].
// 2. A poda de simetria ajuda: se dois caminhões abertos têm a mesma
//    carga, tentar um ou outro dá na mesma.
// 3. Resposta esperada: o guloso usa 4 caminhões e o ótimo usa 3 (5 + 3 +
//    2, 4 + 3 + 3 e 3 + 3 + 3). Guloso rápido não garante o ótimo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
