// 0139 · Troco com programação dinâmica
// Exercício E833 · ★★★
//
// A loja de tintas vende uma cor especial só em latas de 4 L e de 7 L. O
// programa abaixo deveria mostrar, para cada quantidade de 1 a 15 litros, o
// menor número de latas que dá EXATAMENTE aquela quantidade, ou
// "impossível". Ele compila sem aviso, mas o rodar acusa várias vezes
// "runtime error: signed integer overflow", e a tabela que sai não é
// confiável. Há UM erro de propósito. Ache, conserte e rode até a saída
// ficar limpa.
//
//   Saída esperada (depois de consertar):
//    1 L: impossível
//    2 L: impossível
//    3 L: impossível
//    4 L: 1 lata
//    5 L: impossível
//    6 L: impossível
//    7 L: 1 lata
//    8 L: 2 latas
//    9 L: impossível
//   10 L: impossível
//   11 L: 2 latas
//   12 L: 3 latas
//   13 L: impossível
//   14 L: 2 latas
//   15 L: 3 latas
//
// Dicas:
// 1. Leia a mensagem do sanitizer: ela diz a linha e os dois números da
//    soma que estourou.
// 2. Quanto vale dp[1]? E o que acontece quando o laço calcula dp[5] e
//    olha para dp[5 - 4]?
// 3. Há dois jeitos de consertar: um infinito que aguenta o + 1 (como
//    TOTAL + 1) ou testar se o resto tem solução antes de somar.
// 4. Resposta esperada: o INF é INT_MAX, e dp[v - lata[c]] + 1 com
//    dp[...] == INT_MAX estoura. Teste dp[v - lata[c]] != INF antes de somar.
//
// Escreva sua resposta abaixo (conserte o código):

#include <limits.h>
#include <stdio.h>

#define TOTAL 15
#define INF INT_MAX // "impossível"

int main(void) {
    int lata[] = {4, 7};
    int k = 2;
    int dp[TOTAL + 1];

    dp[0] = 0;
    for (int v = 1; v <= TOTAL; v++) {
        dp[v] = INF;
        for (int c = 0; c < k; c++) {
            if (lata[c] <= v && dp[v - lata[c]] + 1 < dp[v]) {
                dp[v] = dp[v - lata[c]] + 1;
            }
        }
    }

    for (int v = 1; v <= TOTAL; v++) {
        if (dp[v] == INF) {
            printf("%2d L: impossível\n", v);
        } else {
            printf("%2d L: %d lata%s\n", v, dp[v], dp[v] > 1 ? "s" : "");
        }
    }
    return 0;
}
