// 0168 · Complexidade espacial
// Exercício E1005 · ★★☆
//
// Escreva a potência rápida recursiva (assunto 0131): x^e é o quadrado de
// x^(e/2), vezes x quando e é ímpar. Faça as contas módulo 1000000007
// (para não estourar o long) e meça a profundidade máxima da pilha, como
// no E1003, para 3^10, 3^1000, 3^1000000 e 3^1000000000:
//
//   Saída esperada:
//   3^10 mod p = 59049, profundidade 5
//   3^1000 mod p = 56888193, profundidade 11
//   3^1000000 mod p = 64935414, profundidade 21
//   3^1000000000 mod p = 235939645, profundidade 31
//
// Dicas:
// 1. #define MOD 1000000007L. Depois de cada multiplicação, faça % MOD:
//    meia * meia é menor que 10^18 e cabe num long de 8 bytes.
// 2. O e cai pela metade a cada chamada: 10, 5, 2, 1, 0 são 5 frames.
// 3. Profundidade floor(log2 e) + 2: Θ(log e) de pilha. Com a versão
//    do E1003, 3^1000000000 empilharia 1 bilhão de frames.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
