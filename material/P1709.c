// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1709 · ★☆☆ · A função que se chama duas vezes à toa
//
// Um colega escreveu a função do esqueleto para calcular a meta de vendas do
// mês n de uma loja: a meta dobra todo mês, e a de janeiro (n = 1) é R$ 100.
// Ela funciona, mas chama meta(n - 1) DUAS vezes com o mesmo argumento:
//
//   C(1) = 1,  C(n) = 2 C(n - 1) + 1  =>  C(n) = 2^n - 1 chamadas
//
// Acrescente um contador de chamadas, escreva meta_boa(n), que chama
// meta_boa(n - 1) uma vez só e guarda o resultado numa variável (C(n) =
// C(n - 1) + 1 = n), e mostre, para n = 1, 5, 10, 20 e 25, a meta e as
// chamadas das duas versões, junto com 2^n - 1.
//
//   Saída esperada:
//    n        meta  ruim: chamadas     2^n-1  boa: chamadas
//    1         100                1         1              1
//    5        1600               31        31              5
//   10       51200             1023      1023             10
//   20    52428800          1048575   1048575             20
//   25  1677721600         33554431  33554431             25
//
// Dicas:
// 1. Use long para a meta: 100 · 2^24 passa de 1,6 bilhão.
// 2. A árvore de recursão da versão ruim é uma árvore binária cheia de
//    altura n - 1: 2^n - 1 nós.
// 3. 2^n - 1 dá para calcular com (1L << n) - 1.
// 4. Resposta esperada: com n = 25, a meta é 1677721600, a versão ruim faz
//    33554431 chamadas e a boa, 25.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

long meta(int n) {
    if (n == 1) return 100;
    return meta(n - 1) + meta(n - 1); // dobra a meta do mês anterior
}

int main(void) {
    printf("Meta do mês 12: R$ %ld\n", meta(12));
    return 0;
}
