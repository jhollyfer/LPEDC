// 0098 · Insertion sort
// Exercício E587 · ★★★
//
// Resposta: (1) a condição está invertida: com i = -1, v[i] > x é avaliado
// ANTES de i >= 0 e lê v[-1], fora do vetor (o ASan acusa). O curto-circuito
// só protege se i >= 0 vier primeiro. (2) No fim, x vai para v[i], mas o
// buraco é v[i + 1]: i parou numa posição que NÃO foi empurrada. Com v[i] = x
// um valor é apagado e o vetor sai errado.

#include <stdio.h>

int main(void) {
    int idades[] = {31, 12, 45, 27, 8, 19};
    int n = 6;

    for (int j = 1; j < n; j++) {
        int x = idades[j];
        int i = j - 1;
        while (i >= 0 && idades[i] > x) {
            idades[i + 1] = idades[i];
            i--;
        }
        idades[i + 1] = x;
    }
    for (int k = 0; k < n; k++) {
        printf("%d ", idades[k]);
    }
    printf("\n");
    return 0;
}
