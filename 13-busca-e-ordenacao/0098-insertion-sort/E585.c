// 0098 · Insertion sort
// Exercício E585 · ★★☆
//
// O fliperama guarda os 5 maiores recordes, do maior para o menor. Hoje o
// ranking tem 4: 9800, 8750, 7200, 6100. Escreva
//
//   void novo_recorde(int top[], int *n, int cap, int pontos)
//
// que encaixa a nova pontuação no lugar certo, como UM passo do insertion
// sort. Se o ranking já está cheio (n == cap), o último sai; se a pontuação
// não supera o último de um ranking cheio, ela nem entra. Teste com 7500,
// 4000 e 9900, nessa ordem, e mostre o ranking depois de cada uma.
//
//   Saída esperada:
//   7500: 9800 8750 7500 7200 6100
//   4000: não entrou no ranking
//   9900: 9900 9800 8750 7500 7200
//
// Dicas:
// 1. Com espaço sobrando, comece a empurrar de i = n - 1 e aumente n no fim.
// 2. Cheio: o último vai ser descartado mesmo, então comece de i = n - 2 (o
//    empurrão escreve por cima de top[n - 1]).
// 3. O ranking é decrescente: empurre enquanto top[i] < pontos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define CAP 5

int main(void) {

    return 0;
}
