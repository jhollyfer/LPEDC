// 0091 · Bubble sort
// Exercício E543 · ★★☆
//
// Este bubble sort deveria ordenar as idades da turma de natação: 34, 19,
// 27, 45, 22. Ele tem DOIS erros, de propósito. Rode: o sanitizer
// ("runtime error: index 5 out of bounds") acusa um deles. Conserte os dois
// e rode de novo até a saída bater com a esperada.
//
//   Saída esperada (depois de consertar):
//   19 22 27 34 45
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int idades[] = {34, 19, 27, 45, 22};
    int n = 5;

    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada + 1; j++) {
            if (idades[j] > idades[j + 1]) {
                idades[j] = idades[j + 1];
                idades[j + 1] = idades[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", idades[i]);
    }
    printf("\n");
    return 0;
}
