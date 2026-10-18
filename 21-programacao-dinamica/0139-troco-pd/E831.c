// 0139 · Troco com programação dinâmica
// Exercício E831 · ★★☆
//
// Num jogo de celular, a loja vende pacotes de 1, 6 e 10 gemas, e você quer
// comprar exatamente 12 gemas com o menor número de pacotes. O programa
// abaixo já calcula o MÍNIMO, mas não diz QUAIS pacotes. Estenda-o:
//
// 1. acrescente o vetor ultimo[] e mostre os pacotes da solução de 12;
// 2. escreva int guloso(int v), que sempre pega o maior pacote que cabe, e
//    mostre, para v de 1 a 20, os valores em que o guloso usa MAIS pacotes
//    que a PD, no formato "v: guloso g, PD d".
//
//   Saída esperada:
//   12 gemas: 2 pacotes (6 6)
//   12: guloso 3, PD 2
//   13: guloso 4, PD 3
//   14: guloso 5, PD 4
//   15: guloso 6, PD 5
//   18: guloso 4, PD 3
//   19: guloso 5, PD 4
//
// Dicas:
// 1. ultimo[v] recebe pacote[p] dentro do mesmo if que atualiza dp[v].
// 2. Para mostrar os pacotes: for (v = 12; v > 0; v -= ultimo[v]).
// 3. O guloso: para cada pacote, do maior para o menor, enquanto couber,
//    some 1 e desconte o pacote.
// 4. Resposta esperada: a saída acima (12 = 6 + 6; o guloso faz 10 + 1 + 1).
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>

#define MAX 20

int pacote[] = {1, 6, 10};
int k = 3;

int main(void) {
    int inf = MAX + 1;
    int dp[MAX + 1];

    dp[0] = 0;
    for (int v = 1; v <= MAX; v++) {
        dp[v] = inf;
        for (int p = 0; p < k; p++) {
            if (pacote[p] <= v && dp[v - pacote[p]] + 1 < dp[v]) {
                dp[v] = dp[v - pacote[p]] + 1;
            }
        }
    }
    printf("12 gemas: %d pacotes\n", dp[12]);
    return 0;
}
