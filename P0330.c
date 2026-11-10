// Lista · Módulo 03 · Laços
// Exercício P0330 · ★★★ · O triângulo de Pascal
//
// No triângulo de Pascal, cada número é a soma dos dois de cima. Sem vetor, dá
// para calcular cada linha da esquerda para a direita: o primeiro é 1, e o
// próximo é c = c * (n − k) / (k + 1), onde n é o número da linha (começando
// em 0) e k a posição. Escreva um programa que mostre as 7 primeiras linhas,
// centralizadas (2 espaços por linha que falta), cada número com %4d, e a soma
// de cada linha:
//
//   Saída esperada:
//                  1   (soma 1)
//                1   1   (soma 2)
//              1   2   1   (soma 4)
//            1   3   3   1   (soma 8)
//          1   4   6   4   1   (soma 16)
//        1   5  10  10   5   1   (soma 32)
//      1   6  15  20  15   6   1   (soma 64)
//
// Dicas:
// 1. Antes dos números, a linha n tem (6 - n) * 2 espaços.
// 2. Faça a multiplicação antes da divisão: c * (n - k) / (k + 1) sempre dá
//    exato nessa ordem.
// 3. A soma da linha n é 2 elevado a n: confira com a sua.
// 4. Resposta esperada: a última linha é 1 6 15 20 15 6 1, soma 64.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
