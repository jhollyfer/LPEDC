// 0092 · Deque
// Exercício E552 · ★★★
//
// As máximas de 8 dias foram 24, 27, 22, 25, 30, 21, 19 e 23 graus. Para
// cada janela de 3 dias seguidos, mostre a maior temperatura. O jeito óbvio
// olha os 3 dias de cada janela. O jeito esperto, com um deque, faz o
// trabalho todo em O(n), qualquer que seja o tamanho da janela.
//
// A ideia: o deque guarda ÍNDICES de dias, com as temperaturas em ordem
// decrescente da frente para o fundo. Para cada dia i:
//
// - enquanto a temperatura do índice no FUNDO for menor ou igual à do dia
// i, retire do fundo (esse dia nunca mais vai ser máximo);
// - insira i no fundo;
// - se o índice da FRENTE saiu da janela (i - frente >= 3), retire da
// frente;
// - a partir do dia 3 (i >= 2), a frente é a máxima da janela.
//
//   Saída esperada:
//   Dias 1-3: máxima 27
//   Dias 2-4: máxima 27
//   Dias 3-5: máxima 30
//   Dias 4-6: máxima 30
//   Dias 5-7: máxima 30
//   Dias 6-8: máxima 23
//
// Dicas:
// 1. Use deque_ultimo e deque_primeiro para olhar as pontas sem tirar.
// 2. O deque nunca guarda mais que 3 índices, então a capacidade 8 do
//    deque.c sobra.
// 3. Cada índice entra uma vez e sai no máximo uma vez: O(n) no total.
// 4. Resposta esperada: as seis linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "deque.h"

int main(void) {

    return 0;
}
