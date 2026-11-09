// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1714 · ★★☆ · Apertando √ na calculadora: T(n) = T(√n) + 1
//
// Na calculadora, você digita um número e aperta a tecla √ até o visor
// mostrar 2 ou menos. Quantas vezes? A função raizes(n) do enunciado faz
// isso recursivamente: se n <= 2, para; senão, chama raizes(⌊√n⌋). A
// recorrência é T(n) = T(√n) + 1.
//
// Ela não tem a forma a T(n/b) + f(n), mas a MUDANÇA DE VARIÁVEL resolve:
// com n = 2^m, fica S(m) = S(m/2) + 1, que é Θ(lg m). Voltando, T(n) =
// Θ(lg lg n). Para n = 2^(2^k) a conta é exata: k + 1 chamadas.
//
// Escreva raiz_inteira(n) (o maior r com r · r <= n, só com inteiros, por
// busca binária), teto_lg(n) (o menor h com 2^h >= n, só com inteiros) e
// raizes(n) com um contador de chamadas, e mostre as chamadas e
// ⌈lg ⌈lg n⌉⌉ + 1 para n = 4, 16, 256, 65536, 4294967296 e
// 18446744073709551615 (o maior unsigned long long, que não é potência de
// 2^(2^k)).
//
//   Saída esperada:
//                      n  chamadas  teto(lg teto(lg n)) + 1
//                      4         2            2
//                     16         3            3
//                    256         4            4
//                  65536         5            5
//             4294967296         6            6
//   18446744073709551615         7            7
//
// Dicas:
// 1. Use unsigned long long. Na busca binária, teste r <= n / r em vez de
//    r * r <= n: o produto estoura para n perto de 2^64.
// 2. teto_lg(n): conte quantos bits tem n - 1 (desloque para a direita até
//    zerar). Não use p *= 2 até passar de n: p estoura antes de 2^64.
// 3. Mesmo o maior número de 64 bits cai para 2 em 7 apertos: lg lg n cresce
//    devagar demais para ser visto na prática.
// 4. Resposta esperada: 2, 3, 4, 5 e 6 chamadas para as potências, e 7 para
//    o maior unsigned long long; a coluna da fórmula bate em todas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
