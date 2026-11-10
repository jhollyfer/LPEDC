// 0187 · Reduções
// Exercício E1122 · ★★★
//
// Reduza 3-COLORAÇÃO a SAT: transforme um grafo numa fórmula que é
// satisfatível exatamente quando o grafo pode ser pintado com 3 cores sem
// vizinhos iguais. Use a variável var(v, c) = 3v + c + 1 para "o vértice v
// tem a cor c" (cores 0 vermelho, 1 verde, 2 azul) e três tipos de
// cláusula, nesta ordem:
//
//   para cada vértice v: (v tem cor 0 ou cor 1 ou cor 2)
//                        e, para cada par de cores a < b, (não a ou não b)
//   para cada aresta u-v e cada cor c: (não u tem c ou não v tem c)
//
// Depois resolva a fórmula por força bruta (2^12 atribuições) e traduza a
// primeira solução de volta para cores. Teste o losango (0-1, 0-2, 1-2,
// 1-3, 2-3) e o completo K4 (todas as 6 arestas entre 0, 1, 2, 3).
//
//   Saída esperada:
//   Losango: 12 variáveis, 31 cláusulas
//     vértice 0: vermelho
//     vértice 1: azul
//     vértice 2: verde
//     vértice 3: vermelho
//   Completo K4: 12 variáveis, 34 cláusulas
//     sem 3-coloração
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
