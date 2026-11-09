// 0166 · O, Ω e Θ de verdade
// Exercício E994 · ★★☆
//
// Refute com um programa: n log₂ n NÃO é O(n). Para cada c em 2, 4, 8 e
// 16, ache o último n de 1 até 200000 em que n * log2(n) <= c * n, e
// mostre a partir de onde a desigualdade quebra de vez:
//
//   Saída esperada:
//   c =  2: falha de n = 5 em diante
//   c =  4: falha de n = 17 em diante
//   c =  8: falha de n = 257 em diante
//   c = 16: falha de n = 65537 em diante
//
// Dicas:
// 1. log2 está em <math.h>; o rodar já liga a biblioteca matemática.
// 2. Guarde ultimo_ok = n sempre que a desigualdade valer; a quebra
//    começa em ultimo_ok + 1.
// 3. n log n <= c n é o mesmo que log n <= c, isto é, n <= 2^c. Para
//    qualquer c, o n = 2^c + 1 quebra o teto. Nenhum c serve.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
