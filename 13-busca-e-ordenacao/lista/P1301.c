// Lista · Módulo 13 · Busca e ordenação
// Exercício P1301 · ★☆☆ · A placa no estacionamento, com sentinela
//
// A cancela do estacionamento guarda os números das placas que estão lá
// dentro, sem ordem: 4821, 1307, 9954, 2210, 6638, 7012, 3389, 5146.
//
// Escreva int busca_sentinela(int v[], int n, int x, int *comparacoes): ela
// copia x para v[n] (a sentinela) e anda com um while que só testa
// v[i] != x, sem testar i < n. No fim, devolve i se i < n, ou -1. Conte uma
// comparação para cada v[i] olhado, inclusive o da sentinela. O vetor tem que
// ter uma posição a mais (9 posições) para caber a sentinela.
//
// Procure 2210, 5146 e 1000.
//
//   Saída esperada:
//   Placa 2210: posição 3 (4 comparações)
//   Placa 5146: posição 7 (8 comparações)
//   Placa 1000: posição -1 (9 comparações)
//
// Dicas:
// 1. Declare int placas[9] = {4821, ..., 5146}; e use n = 8.
// 2. Comece com comparacoes = 1 (o primeiro v[0] != x) e some 1 a cada i++.
// 3. Quem não está no vetor custa n + 1 comparações: a última é a sentinela.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
