// 0076 · Eficiência: contar passos
// Exercício E456 · ★★★
//
// No assunto 0038 você viu que o Fibonacci recursivo é lento. Agora meça o
// quanto. Escreva:
//
// - fib_rec(n): a versão recursiva (fib(0) = 0, fib(1) = 1), somando 1 num
// contador global "chamadas" a cada vez que a função é chamada;
// - fib_it(n): a versão com laço, somando 1 num contador "somas" a cada soma.
//
// Mostre a tabela para n = 10, 20 e 30. Use long para os contadores.
//
//   Saída esperada:
//    n     fib  chamadas  somas
//   10      55       177      9
//   20    6765     21891     19
//   30  832040   2692537     29
//
// Depois responda: quando n aumenta 1, as chamadas da recursiva se
// multiplicam por quanto, mais ou menos?
//
// Dicas:
// 1. Zere os contadores antes de cada n.
// 2. A versão com laço guarda os dois últimos valores e anda n - 1 vezes.
// 3. fib_rec(n) chama fib_rec(n - 1) e fib_rec(n - 2): o fib(28) é calculado
//    do zero 2 vezes, o fib(27) 3 vezes, o fib(26) 5 vezes...
// 4. Resposta esperada: a tabela acima. A cada +1 no n, as chamadas
//    multiplicam por cerca de 1,618 (a razão áurea): de n = 10 para 20 elas
//    crescem 21891 / 177 ≈ 124 vezes, e 1,618 elevado a 10 ≈ 123. Isso é
//    crescimento exponencial.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
