// 0112 · Dijkstra: caminho mínimo
// Exercício E670 · ★★☆
//
// A cidade quer saber quanto tempo uma ambulância leva de cada bairro ATÉ o
// Hospital. As ruas são de mão única (grafo dirigido), em minutos:
//
//   Norte -> Hospital 9, Norte -> Leste 2, Leste -> Hospital 4,
//   Leste -> Oeste 1, Sul -> Oeste 3, Sul -> Norte 1,
//   Oeste -> Hospital 5, Hospital -> Sul 1
//
// Índices: Hospital 0, Norte 1, Sul 2, Leste 3, Oeste 4.
//
// Rodar Dijkstra uma vez a partir de cada bairro funciona, mas gasta 4
// execuções. Faça com UMA só: rode Dijkstra a partir do Hospital no grafo
// TRANSPOSTO (todas as setas invertidas). A distância do Hospital até X no
// grafo invertido é a distância de X até o Hospital no grafo original.
//
//   Saída esperada:
//   Norte: 6 min
//   Sul: 7 min
//   Leste: 4 min
//   Oeste: 5 min
//
// Dicas:
// 1. Transpor a matriz é trocar linha por coluna: inv[j][i] = rua[i][j].
// 2. Cuidado com a armadilha: Dijkstra no grafo ORIGINAL a partir do Hospital
//    responde outra pergunta (do Hospital até os bairros) e dá outros números.
// 3. Resposta esperada: a saída acima. Norte vai por Leste (2 + 4 = 6, e não
//    9 direto); Sul vai por Norte (1 + 6 = 7, e não 3 + 5 = 8 por Oeste).
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
