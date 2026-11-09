// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1718 · ★★☆ · O laço que dobra dentro da recursão
//
// A função do esqueleto organiza as filas de um evento: em cada pedaço de n
// pessoas, um laço for (i = 1; i < n; i *= 2) faz lg n passos, e depois a
// função se chama para as duas metades. A recorrência é
//
//   T(1) = 1,  T(n) = 2 T(n/2) + lg n
//
// Leia o código, ache a recorrência e aplique o teorema mestre: a = 2,
// b = 2, n^(log₂ 2) = n, e f(n) = lg n = O(n^(1 - ε)): caso 1, Θ(n). A
// árvore de recursão dá a fórmula exata para n potência de 2:
// T(n) = 3n - lg n - 2.
//
// Acrescente um contador global (1 por volta do laço e 1 no caso base) e
// mostre, para n = 1, 4, 16, ..., 2^20 (potências de 4), o custo contado, 3n - lg n - 2 e a
// razão custo / n.
//
//   Saída esperada:
//         n    custo  3n-lg n-2  custo/n
//         1        1          1   1.0000
//         4        8          8   2.0000
//        16       42         42   2.6250
//        64      184        184   2.8750
//       256      758        758   2.9609
//      1024     3060       3060   2.9883
//      4096    12274      12274   2.9966
//     16384    49136      49136   2.9990
//     65536   196590     196590   2.9997
//    262144   786412     786412   2.9999
//   1048576  3145706    3145706   3.0000
//
// Dicas:
// 1. Para ler a recorrência do código: duas chamadas com n/2 dão 2 T(n/2);
//    o laço com i *= 2 roda ⌈lg n⌉ vezes; o resto é constante.
// 2. Mesmo com o trabalho por chamada crescendo (lg n), a quantidade de
//    folhas (n) domina: o caso 1 diz que as folhas ganham.
// 3. A razão custo / n se aproxima de 3, a constante da fórmula.
// 4. Resposta esperada: o custo bate com 3n - lg n - 2 em todas as linhas;
//    com n = 2^20, 3145706.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void organiza(long n) {
    if (n == 1) return;
    for (long i = 1; i < n; i *= 2) {
        // um passo de organização
    }
    organiza(n / 2);
    organiza(n / 2);
}

int main(void) {
    organiza(1024);
    return 0;
}
