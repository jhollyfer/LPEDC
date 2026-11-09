// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2614 · ★★☆ · A rede que triplica
//
// Uma corrente de mensagens: na rodada k, 3^k pessoas recebem a mensagem
// (1, 3, 9, 27, ...), e o sistema processa cada uma. Com o laço
// for (t = 1; t <= n; t *= 3) e um laço de dentro de 0 até t, conte o
// processamento total para n = 100, 1000 e 1000000. Mostre ao lado a
// fórmula da soma geométrica (3t - 1) / 2, onde t é a última potência de 3
// que entrou, e a razão total / n:
//
//   Saída esperada:
//   n =     100: total    121, fórmula    121, razão 1.210
//   n =    1000: total   1093, fórmula   1093, razão 1.093
//   n = 1000000: total 797161, fórmula 797161, razão 0.797
//
// Dicas:
// 1. 1 + 3 + 9 + ... + t = (3t - 1) / 2: a soma geométrica de razão 3.
// 2. A razão total / n fica sempre abaixo de 1,5: Θ(n), mesmo com dois laços.
// 3. Guarde a última potência de 3 usada numa variável fora do laço.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
