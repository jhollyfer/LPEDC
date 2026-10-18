// 0071 · Eficiência: contar passos
// Exercício E426 · ★★★
//
// No assunto 0033 você viu que o Fibonacci recursivo é lento. Agora meça o
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
// Depois acrescente uma segunda tabela: para n de 20 a 25, as chamadas da
// recursiva e a razão entre as chamadas de n e as de n - 1.
//
//   n = 20:  21891 chamadas, razão 1.618
//   n = 21:  35421 chamadas, razão 1.618
//   n = 22:  57313 chamadas, razão 1.618
//   n = 23:  92735 chamadas, razão 1.618
//   n = 24: 150049 chamadas, razão 1.618
//   n = 25: 242785 chamadas, razão 1.618
//
// Dicas:
// 1. Zere os contadores antes de cada n.
// 2. A versão com laço guarda os dois últimos valores e anda n - 1 vezes.
// 3. fib_rec(n) chama fib_rec(n - 1) e fib_rec(n - 2): o fib(28) é calculado
//    do zero 2 vezes, o fib(27) 3 vezes, o fib(26) 5 vezes...
// 4. Na segunda tabela, comece medindo n = 19 e guarde as chamadas numa
//    variável "anterior"; a razão é (double)chamadas / anterior.
// 5. Resposta esperada: as duas tabelas acima. A cada +1 no n, as chamadas
//    multiplicam por cerca de 1,618 (a razão áurea): crescimento
//    exponencial.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
