// 0117 · Limite inferior da ordenação
// Exercício E697 · ★☆☆
//
// Escreva teto_log2(x): o menor h tal que 2^h >= x, calculado só com
// inteiros (um laço que dobra uma variável até alcançar x). Use-a para
// mostrar o limite inferior ⌈log₂ n!⌉ de comparações para ordenar n
// elementos, com n de 1 a 20:
//
//   Saída esperada:
//    n                   n!  limite
//    1                    1       0
//    2                    2       1
//    3                    6       3
//    4                   24       5
//    5                  120       7
//    6                  720      10
//   ...
//   12            479001600      29
//   ...
//   20  2432902008176640000      62
//
// Dicas:
// 1. 20! não cabe em int nem em long de 32 bits: use unsigned long long e
//    %llu no printf.
// 2. teto_log2 começa com h = 0 e folhas = 1; enquanto folhas < x,
//    dobra folhas e soma 1 em h.
// 3. Calcule o fatorial acumulando no próprio laço do main (fat *= n).
// 4. Resposta esperada: a tabela acima. Nas linhas que não aparecem, o
//    limite é 13, 16, 19, 22 e 26 (n = 7 a 11) e 33, 37, 41, 45, 49, 53 e
//    57 (n = 13 a 19). Por que inteiros? Com log2 em double, um valor que
//    devia dar 3 exato pode sair 3.0000000000000004, e o teto erra por 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
