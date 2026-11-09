// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2927 · ★★★ · Rota mais curta que termina em casa
//
// O entregador da farmácia do 0189 não volta para a farmácia: depois da
// última entrega ele vai para casa, que fica no ponto do Gil (índice 7).
// Pontos (quarteirões): Farmácia (0,0), Ana (1,3), Bruno (4,4),
// Clara (6,3), Dênis (7,0), Edna (5,1), Fábio (2,6), Gil (3,1).
// Adapte o Held-Karp para CAMINHO hamiltoniano de 0 até 7: a resposta é
// dp[todos][7], sem volta. Reconstrua a rota com uma tabela ant[][] e
// compare com a volta fechada (28 quarteirões).
//
//   Saída esperada:
//   Caminho até a casa: 24 quarteirões
//   Farmácia -> Ana -> Fábio -> Bruno -> Clara -> Dênis -> Edna -> Gil
//   Volta fechada era 28; terminar no Gil economiza 4
//
// Dicas:
// 1. A PD é a mesma; só muda o fim: em vez de min sobre j de dp[todos][j] +
//    d[j][0], pegue dp[todos][7].
// 2. Reconstrução: do (todos, 7), ant diz o anterior; apague o bit e repita até
//    chegar ao 0.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
