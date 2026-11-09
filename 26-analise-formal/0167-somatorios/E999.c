// 0167 · Somatórios que saem de laços
// Exercício E999 · ★★☆
//
// O condomínio quer saber quantas comissões de 3 moradores diferentes dá
// para formar (a ordem não importa). Escreva trios(n) com três laços
// dependentes, k < j < i, contando cada trio uma vez, e compare com a
// fórmula n(n-1)(n-2)/6 para n = 10, 30 e 100:
//
//   Saída esperada:
//     n   trios  n(n-1)(n-2)/6
//    10     120            120
//    30    4060           4060
//   100  161700         161700
//
// Dicas:
// 1. for i < n, for j < i, for k < j: cada trio aparece uma vez só, em
//    ordem decrescente de índice.
// 2. O somatório é a soma, para cada i, de i(i-1)/2 (os pares abaixo de
//    i). Isso dá n(n-1)(n-2)/6: três laços, Θ(n³), com constante 1/6.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
