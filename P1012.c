// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1012 · ★★☆ · Primos: dividir contra peneirar
//
// Para sortear senhas, o sistema precisa de todos os primos até N. Escreva
// dois jeitos de contar os primos de 2 a N, contando o trabalho de cada um:
//
//   int por_divisao(int n, long *ops)
//     para cada k de 2 a n, testa os divisores d = 2, 3, ... enquanto
//     d * d <= k, parando no primeiro que divide. Cada k % d é 1 operação.
//   int por_crivo(int n, long *ops)
//     o crivo de Eratóstenes: um vetor bool com todos "primo", e para cada
//     i primo com i * i <= n, marca i*i, i*i + i, ... como não primo. Cada
//     marcação é 1 operação.
//
// Mostre os dois para N = 100 e N = 10000 (use um vetor de 10001 bool).
//
//   Saída esperada:
//   N = 100: 25 primos | divisão: 236 ops | crivo: 104 ops
//   N = 10000: 1229 primos | divisão: 117527 ops | crivo: 16981 ops
//
// Dicas:
// 1. Na divisão, o laço de dentro é for (d = 2; d * d <= k; d++) e sai com
//    break quando k % d == 0.
// 2. No crivo, o laço de dentro começa em i * i porque os múltiplos menores
//    já foram marcados por primos menores que i.
// 3. A divisão custa perto de N·√N / log N; o crivo, N·log log N. Com N
//    100 vezes maior, a divisão ficou 500 vezes mais cara e o crivo, 160.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
