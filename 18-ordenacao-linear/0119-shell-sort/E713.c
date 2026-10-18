// 0119 · Shell sort
// Exercício E713 · ★★★
//
// Ache os bugs. Este shell sort deveria ordenar as 13 senhas de atendimento
// do cartório, mas a saída sai fora de ordem. Não há erro de memória: o
// programa roda até o fim, só que errado. São DOIS erros, um em cada laço
// while. Conserte os dois e rode.
//
//   Saída esperada:
//   2 5 8 11 14 17 20 23 26 29 32 35 38
//
// Dicas:
// 1. Mostre o valor de h no começo de cada rodada. Quantas rodadas
//    acontecem? Qual devia ser a última?
// 2. Com o primeiro erro consertado, mostre o vetor depois de cada rodada.
//    Na rodada h = 1, o v[1] chega a ser comparado com o v[0]?
// 3. Compare as condições com as do shell_sort do texto.
// 4. Resposta esperada: o laço dos saltos tem que rodar também com h = 1
//    (while (h >= 1), e não while (h > 1)); e o laço de dentro tem que
//    andar enquanto j >= h, e não j > h. Consertado, sai a linha acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void shell_sort(int v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h > 1) {
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j > h && v[j - h] > x) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
        h /= 3;
    }
}

int main(void) {
    int senhas[] = {29, 8, 35, 14, 2, 23, 38, 11, 20, 5, 32, 17, 26};
    int n = 13;

    shell_sort(senhas, n);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", senhas[i]);
    }
    printf("\n");
    return 0;
}
