// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2623 · ★★★ · Raiz contra logaritmo
//
// Refute com um programa: √n NÃO é O(log n). Para c = 1, 2, 5 e 10, ache o
// último n de 2 até 1000000 em que sqrt(n) <= c * log2(n) e mostre a partir
// de onde a desigualdade quebra de vez. Mostre também, para cada c, a razão
// sqrt(n) / log2(n) em n = 1000000:
//
//   Saída esperada:
//   c =  1: falha de n = 17 em diante
//   c =  2: falha de n = 257 em diante
//   c =  5: falha de n = 3454 em diante
//   c = 10: falha de n = 20520 em diante
//   sqrt(n) / log2(n) em n = 1000000: 50.2
//
// Dicas:
// 1. Qualquer potência de n, por menor que seja o expoente, passa de qualquer
//    c log n.
// 2. A razão em 1 milhão é a mesma para todo c (uns 50): já passou de todos
//    os c testados.
// 3. sqrt e log2 estão em <math.h>.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
