// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1001 · ★☆☆ · Quantas vezes dá para dividir
//
// O laço "while (n > 1) n = n / 2;" roda cerca de log₂ n vezes, e com
// "n = n / 3" roda cerca de log₃ n vezes. Escreva duas funções,
// int passos_metade(int n) e int passos_terco(int n), que rodam cada laço e
// devolvem quantas voltas ele deu. Mostre a tabela para n = 10, 100, 1000 e
// 1000000, com printf("%8d %4d %4d\n", ...) e o cabeçalho abaixo.
//
//   Saída esperada:
//          n   /2   /3
//         10    3    2
//        100    6    4
//       1000    9    6
//    1000000   19   12
//
// Dicas:
// 1. Conte uma volta a cada divisão; com n = 1 o laço nem começa (0 voltas).
// 2. O cabeçalho é printf("%8s %4s %4s\n", "n", "/2", "/3").
// 3. Repare: multiplicar n por 1000 só soma umas 10 voltas no /2. Trocar a
//    base do log muda a conta por uma constante (log₃ n = log₂ n / log₂ 3),
//    por isso as duas funções são O(log n).
// 4. Resposta esperada: a tabela acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
