// Lista · Módulo 21 · Programação dinâmica
// Exercício P2124 · ★★★ · A mochila quando a capacidade é enorme
//
// A tabela da mochila 0/1 tem n × W casas. Quando W é enorme (um caminhão
// de 100 000 kg) e os valores são pequenos, é melhor trocar de dimensão:
// menor_peso[v] é o MENOR peso para conseguir valor exatamente v, e a
// resposta é o maior v com menor_peso[v] <= W. Uma transportadora tem 6
// lotes (peso em kg, valor em mil reais) e um caminhão de 100 000 kg:
//
//   lote     1      2      3      4      5      6
//   kg     41000  23000  37000  18000  29000  52000
//   valor    12      7     11      5      9     15
//
// Escreva do zero essa PD (uma linha só, v de trás para a frente, como na
// mochila de uma linha) e reconstrua os lotes guardando, numa tabela
// pegou[i][v], se o lote i melhorou menor_peso[v].
//
//   Saída esperada:
//   Maior valor: 29 mil reais (99000 kg)
//   Lotes: 4 5 6
//   Posições da tabela: 60 (a mochila comum teria 100001)
//
// Dicas:
// 1. A soma dos valores é 59: o vetor tem 60 posições, contra 100 001 da
//    mochila comum. menor_peso[0] = 0 e o resto "infinito".
// 2. Para o lote i, de v = 59 até valor[i]: se menor_peso[v - valor[i]] +
//    peso[i] < menor_peso[v], atualize e marque pegou[i][v].
// 3. Resposta esperada: 29 mil reais com os lotes 4, 5 e 6 (99000 kg). Os
//    lotes 1, 2 e 3 valeriam 30, mas pesam 101000 kg.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
