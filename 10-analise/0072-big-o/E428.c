// 0072 · Notação O: como o custo cresce
// Exercício E428 · ★☆☆
//
// Seis colegas contaram os passos dos seus algoritmos e chegaram nestas
// fórmulas. Para cada uma, aposte numa classe O (descarte constantes e fique
// com o termo que domina) e confira a aposta com um programa: escreva a
// fórmula como função double f(double n), a aposta como double g(double n),
// e mostre f(n) / g(n) para n = 10, 1000 e 1000000. Aposta certa: a razão não
// cresce sem parar; ela se acomoda perto de uma constante.
//
//   a) 3n² + 10n + 7      b) 500               c) n + log₂ n
//   d) 2n log₂ n + 50n    e) n³ / 1000 + n²    f) n(n + 1) / 2
//
//   Saída esperada:
//   fórmula             n=10     n=1000     n=10^6
//   a) O(n^2)          4.0700     3.0100     3.0000
//   b) O(1)          500.0000   500.0000   500.0000
//   c) O(n)            1.3322     1.0100     1.0000
//   d) O(n log n)     17.0515     7.0172     4.5086
//   e) O(n^3)          0.1010     0.0020     0.0010
//   f) O(n^2)          0.5500     0.5005     0.5000
//
// Dicas:
// 1. log2() está em <math.h> (o rodar já liga com -lm).
// 2. Para não repetir 18 printf, escreva uma função que recebe o rótulo, a
//    fórmula e a aposta como ponteiros para função (assunto 0050):
//    void linha(const char *rotulo, double (*f)(double), double (*g)(double)).
// 3. Formato: "%-14s" no rótulo e " %10.4f" em cada razão.
// 4. Resposta esperada: a tabela acima. No d), a razão cai devagar até 2
//    (o 50n perde força quando n cresce); se você apostasse O(n), ela
//    cresceria sem parar. Para ver isso, troque uma aposta e rode de novo.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
