// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2021 · ★★★ · Karatsuba contra os quatro produtos
//
// Para multiplicar x e y de n dígitos por divisão e conquista, escreva x =
// a·p + b e y = c·p + d, com p = 10^(n/2). O jeito direto faz QUATRO
// produtos menores (ac, ad, bc, bd): T(n) = 4T(n/2) + O(n), que é O(n²) e
// não ganha nada da escola. Karatsuba faz TRÊS (ac, bd e (a + b)(c + d)):
// T(n) = 3T(n/2) + O(n), O(n^1,59). Escreva do zero as duas versões,
// recursivas, com caso base "um dos números tem 1 dígito" (aí multiplica
// direto e conta 1), e compare as contagens para 12345678 × 87654321 e
// para 99999999 × 99999999.
//
//   Saída esperada:
//   12345678 x 87654321 = 1082152022374638
//     4 produtos: 64 multiplicações (resultado certo)
//     Karatsuba: 33 multiplicações (resultado certo)
//   99999999 x 99999999 = 9999999800000001
//     4 produtos: 64 multiplicações (resultado certo)
//     Karatsuba: 63 multiplicações (resultado certo)
//
// Dicas:
// 1. n é a quantidade de dígitos do MAIOR dos dois; p = 10^(n / 2).
// 2. Quatro produtos: ac·p² + (ad + bc)·p + bd. Karatsuba: meio =
//    (a + b)(c + d) - ac - bd no lugar de ad + bc.
// 3. Resposta esperada: os produtos certos e, para os números de 8
//    dígitos, 64 multiplicações de um dígito na versão de 4 produtos
//    (8 · 8, a mesma conta da escola). Karatsuba gasta 33 no primeiro e 63
//    no segundo: com os 9s, cada a + b ganha um dígito (99 + 99 = 198) e a
//    recursão desce um nível a mais.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
