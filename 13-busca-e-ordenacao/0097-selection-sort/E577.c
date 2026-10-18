// 0097 · Selection sort
// Exercício E577 · ★☆☆
//
// Uma variação do selection: em vez de procurar o MENOR e pôr na frente,
// procure o MAIOR e ponha no FIM. A parte pronta cresce pela direita. Ordene
// os preços 89, 45, 120, 30, 75, 60 e mostre o vetor depois de cada passada
// (fim é a gaveta que recebe o maior).
//
//   Saída esperada:
//   fim = 5: 89 45 60 30 75 120
//   fim = 4: 75 45 60 30 89 120
//   fim = 3: 30 45 60 75 89 120
//   fim = 2: 30 45 60 75 89 120
//   fim = 1: 30 45 60 75 89 120
//
// Dicas:
// 1. O laço de fora: for (int fim = n - 1; fim > 0; fim--).
// 2. O de dentro procura o índice do maior em v[0..fim] (repare no <=).
// 3. Depois do laço de dentro, troque v[fim] com v[maior].
// 4. Resposta esperada: a saída acima. O vetor fica pronto em fim = 3, mas o
//    selection não tem como saber disso e continua.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
