// 0115 · Teorema mestre
// Exercício E690 · ★★★
//
// Ache o bug. Este classificador do teorema mestre calcula o expoente
// c = log_b a com double e compara com k. Ele acerta quase tudo, mas erra
// três das sete recorrências do teste:
//
//   Saída que aparece:
//      2 T(n/2)  + n^1 -> empate
//      4 T(n/2)  + n^1 -> folhas
//      1 T(n/2)  + n^1 -> raiz
//    125 T(n/5)  + n^3 -> folhas
//   1000 T(n/10) + n^3 -> raiz
//    216 T(n/6)  + n^3 -> folhas
//      8 T(n/2)  + n^3 -> empate
//
//   Saída esperada:
//      2 T(n/2)  + n^1 -> empate
//      4 T(n/2)  + n^1 -> folhas
//      1 T(n/2)  + n^1 -> raiz
//    125 T(n/5)  + n^3 -> empate
//   1000 T(n/10) + n^3 -> empate
//    216 T(n/6)  + n^3 -> empate
//      8 T(n/2)  + n^3 -> empate
//
// Descubra por que (mostre c com %.17g para conferir) e conserte a função
// para que ela nunca dependa da precisão do double.
//
// Dicas:
// 1. 125 = 5³, 1000 = 10³ e 216 = 6³: nos três, log_b a deveria ser 3
//    exatamente. O que o printf com %.17g mostra?
// 2. log(125) / log(5) dá 3.0000000000000004. Os logaritmos são
//    arredondados para caber no double, e o == entre doubles quase nunca
//    é o que você quer.
// 3. O conserto mais limpo nem usa log: compare a com b^k, calculado com
//    inteiros num laço. a > b^k é folhas; a == b^k, empate; senão, raiz.
//    (Outra saída, pior: considerar iguais se fabs(c - k) < 1e-9.)
// 4. Resposta esperada: a saída esperada acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <math.h>
#include <stdio.h>

const char *classifica(int a, int b, int k) {
    double c = log(a) / log(b); // log_b a
    if (c > k) {
        return "folhas";
    }
    if (c == k) {
        return "empate";
    }
    return "raiz";
}

int main(void) {
    int r[][3] = {{2, 2, 1}, {4, 2, 1}, {1, 2, 1}, {125, 5, 3}, {1000, 10, 3}, {216, 6, 3}, {8, 2, 3}};
    for (int i = 0; i < 7; i++) {
        printf("%4d T(n/%d)%s + n^%d -> %s\n", r[i][0], r[i][1], r[i][1] < 10 ? " " : "",
               r[i][2], classifica(r[i][0], r[i][1], r[i][2]));
    }
    return 0;
}
