// 0093 · Insertion sort
// Exercício E557 · ★★★
//
// Este insertion sort deveria ordenar as idades do grupo de corrida:
// 31, 12, 45, 27, 8, 19. Ele tem DOIS erros, de propósito. O primeiro faz o
// sanitizer parar o programa; o segundo só aparece depois que você
// consertar o primeiro. Conserte os dois e rode de novo.
//
//   Saída esperada (depois de consertar):
//   8 12 19 27 31 45
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int idades[] = {31, 12, 45, 27, 8, 19};
    int n = 6;

    for (int j = 1; j < n; j++) {
        int x = idades[j];
        int i = j - 1;
        while (idades[i] > x && i >= 0) {
            idades[i + 1] = idades[i];
            i--;
        }
        idades[i] = x;
    }
    for (int k = 0; k < n; k++) {
        printf("%d ", idades[k]);
    }
    printf("\n");
    return 0;
}
