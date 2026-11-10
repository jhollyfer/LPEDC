// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2207 · ★☆☆ · As redes da comunidade
//
// Na comunidade ribeirinha, 10 casas (0 a 9) estão ganhando internet por
// rádio, e cada enlace liga duas casas. Escreva do zero um union-find com
// UNIÃO POR POSTO (rank) e COMPRESSÃO DE CAMINHO: acha(x) devolve a raiz e
// pendura todo o caminho direto nela; une(a, b) liga a raiz de posto menor
// embaixo da de posto maior (no empate, a de b embaixo da de a, e o posto
// de a sobe 1). Processe os enlaces e mostre quantas redes separadas
// sobraram e as casas de cada uma.
//
//   Enlaces: 0-1  2-3  1-4  5-6  3-7  4-8  6-9  0-8
//
//   Saída esperada:
//   Redes: 3
//     { 0 1 4 8 }
//     { 2 3 7 }
//     { 5 6 9 }
//
// Dicas:
// 1. pai[i] = i e posto[i] = 0 no começo. Componentes começa em 10 e cai
//    1 a cada une que junta duas raízes diferentes.
// 2. Para listar, percorra as raízes (pai[r] == r) e, para cada uma, as
//    casas x com acha(x) == r.
// 3. Resposta esperada: 3 redes: {0 1 4 8}, {2 3 7} e {5 6 9}.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
