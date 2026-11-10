// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2615 · ★★☆ · Os passos do crivo
//
// O crivo de Eratóstenes marca os múltiplos de cada primo p a partir de
// p * p. Escreva o crivo com um vetor de char alocado com malloc (n + 1
// posições), conte as marcações (um passo por múltiplo marcado, mesmo que
// já estivesse marcado) e os primos, para n = 100, 10000 e 1000000. Mostre
// também a razão marcações / (n ln ln n):
//
//   Saída esperada:
//   n =     100:     25 primos,     104 marcações, razão 0.681
//   n =   10000:   1229 primos,   16981 marcações, razão 0.765
//   n = 1000000:  78498 primos, 2122048 marcações, razão 0.808
//
// Dicas:
// 1. O laço de fora vai enquanto p * p <= n; o de dentro anda de p em p.
// 2. A soma n/2 + n/3 + n/5 + ... sobre os primos cresce como n ln ln n:
//    quase linear.
// 3. log de <math.h> é o ln. O vetor tem n + 1 bytes: Θ(n) de espaço. Não
//    esqueça o free.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    return 0;
}
