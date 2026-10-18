// 0148 · Union-find
// Exercício E888 · ★★★
//
// Teste de infiltração. Uma placa de 5x5 quadradinhos começa toda tapada, e
// o técnico fura um quadradinho por vez, na ordem c = (i * 9 + 7) % 25 para
// i = 0, 1, 2... (c = linha * 5 + coluna). A água jogada em cima passa para
// baixo quando existe um caminho de quadradinhos furados, vizinhos em cima,
// embaixo ou dos lados, da linha 0 até a linha 4. Descubra em qual furo a água
// passa e mostre a placa nesse momento (# furado, . tapado).
//
//   Saída esperada:
//   A água passou no passo 13 (13 de 25 abertas)
//   #.#.#
//   .##.#
//   .#.#.
//   ##.#.
//   #.#..
//
// Dicas:
// 1. Use o TAD (uniao.h) com 25 + 2 elementos: além dos quadradinhos, um
//    TOPO virtual (25), unido a todo furo da linha 0, e um FUNDO virtual
//    (26), unido a todo furo da linha 4. A água passou quando
//    uf_juntos(u, TOPO, FUNDO).
// 2. A cada furo, una o quadradinho com cada vizinho que já esteja furado
//    (guarde isso num bool aberta[25]). Cuidado com as bordas.
// 3. Resposta esperada: a saída acima. O caminho da água é (0,2), (1,2),
//    (1,1), (2,1), (3,1), (3,0), (4,0). Sem o TOPO e o FUNDO, você teria que
//    testar os 25 pares de quadradinhos de cima e de baixo a cada furo.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "uniao.h"

int main(void) {

    return 0;
}
