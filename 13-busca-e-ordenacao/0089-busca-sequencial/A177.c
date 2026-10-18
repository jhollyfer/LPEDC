// A177 · Quantas vezes o aluno passou na catraca

#include <stdio.h>

// procura x a partir da posição inicio; devolve o índice ou -1
int busca_a_partir(const int v[], int n, int x, int inicio, int *comparacoes) {
    for (int i = inicio; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    // registro do dia: cada número é uma passagem pela catraca, em ordem
    int passagens[] = {3305, 4172, 3305, 8821, 1290, 3305, 7034, 4172};
    int n = sizeof passagens / sizeof passagens[0];
    int procuradas[] = {3305, 1290, 5567};

    for (int k = 0; k < 3; k++) {
        int x = procuradas[k];
        int comparacoes = 0, vezes = 0;
        printf("%d passou nas posições:", x);
        // cada achado vira o ponto de partida da próxima busca
        int pos = busca_a_partir(passagens, n, x, 0, &comparacoes);
        while (pos != -1) {
            printf(" %d", pos);
            vezes++;
            pos = busca_a_partir(passagens, n, x, pos + 1, &comparacoes);
        }
        printf("%s -> %d vez(es), %d comparações\n",
               vezes == 0 ? " nenhuma" : "", vezes, comparacoes);
    }
    return 0;
}
// Saída:
// 3305 passou nas posições: 0 2 5 -> 3 vez(es), 8 comparações
// 1290 passou nas posições: 4 -> 1 vez(es), 8 comparações
// 5567 passou nas posições: nenhuma -> 0 vez(es), 8 comparações
