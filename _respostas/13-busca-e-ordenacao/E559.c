// 0094 · Busca sequencial
// Exercício E559 · ★☆☆

#include <stdio.h>

// procura de trás para frente: a primeira que achar é a última do vetor
int ultima_ocorrencia(const int v[], int n, int x, int *comparacoes) {
    *comparacoes = 0;
    for (int i = n - 1; i >= 0; i--) {
        (*comparacoes)++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int pix[] = {50, 120, 35, 50, 80, 50, 15};
    int n = sizeof pix / sizeof pix[0];
    int c;

    int pos = ultima_ocorrencia(pix, n, 50, &c);
    printf("Última de R$ 50: posição %d (%d comparações)\n", pos, c);
    pos = ultima_ocorrencia(pix, n, 200, &c);
    printf("Última de R$ 200: posição %d (%d comparações)\n", pos, c);
    return 0;
}
