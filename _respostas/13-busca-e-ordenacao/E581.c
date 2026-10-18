// 0097 · Selection sort
// Exercício E581 · ★★★
//
// Resposta: "int menor = 0;" fica fora do laço externo e nunca volta a ser i.
// Na passada 0 o menor já é o 15, na gaveta 0, e menor continua 0. Na passada
// 1, menor ainda vale 0: nenhum v[j] de v[2..4] é menor que 15, e a troca
// manda o 15 para a gaveta 1 e o 40 para a gaveta 0, estragando a parte que
// já estava pronta. Conserto: declarar "int menor = i;" no começo de cada
// passada, dentro do for de fora.

#include <stdio.h>

int main(void) {
    int alturas[] = {15, 40, 28, 33, 21};   // mudas de planta, em cm
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (alturas[j] < alturas[menor]) {
                menor = j;
            }
        }
        int aux = alturas[i];
        alturas[i] = alturas[menor];
        alturas[menor] = aux;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", alturas[i]);
    }
    printf("\n");
    return 0;
}
