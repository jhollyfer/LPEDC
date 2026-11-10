// Lista · Módulo 15 · Tabelas hash
// Exercício P1506 · ★☆☆ · O fator de carga subindo
//
// Uma tabela com encadeamento tem m = 5 baldes e h(k) = k % 5. Para estudar
// só os tamanhos, nem precisa de lista: guarde int tamanho[5] com o
// comprimento de cada corrente. Insira as senhas 12, 7, 30, 22, 15, 9, 41, 3,
// 17, 25 e, depois de cada inserção, mostre n, o fator de carga
// α = n / m e o tamanho da maior corrente.
//
//   Saída esperada:
//   n =  1: alfa = 0.2, maior corrente = 1
//   n =  2: alfa = 0.4, maior corrente = 2
//   n =  3: alfa = 0.6, maior corrente = 2
//   n =  4: alfa = 0.8, maior corrente = 3
//   n =  5: alfa = 1.0, maior corrente = 3
//   n =  6: alfa = 1.2, maior corrente = 3
//   n =  7: alfa = 1.4, maior corrente = 3
//   n =  8: alfa = 1.6, maior corrente = 3
//   n =  9: alfa = 1.8, maior corrente = 4
//   n = 10: alfa = 2.0, maior corrente = 4
//
// Dicas:
// 1. Divida em double: (double)n / M. Com int, 3 / 5 daria 0.
// 2. α é o tamanho MÉDIO das correntes: a busca sem sucesso custa
//    Θ(1 + α). Com encadeamento, α pode passar de 1.
// 3. A maior corrente é o pior caso. Ela cresce mais rápido que a média
//    quando as chaves se concentram (12, 7, 22, 17 caem todas no balde 2).
// 4. Use printf("n = %2d: alfa = %.1f, maior corrente = %d\n", ...).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 5

int main(void) {

    return 0;
}
