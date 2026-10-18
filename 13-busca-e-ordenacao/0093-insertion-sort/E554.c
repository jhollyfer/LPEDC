// 0093 · Insertion sort
// Exercício E554 · ★☆☆
//
// No check-in, as malas (em kg) precisam ir para a esteira da mais leve para
// a mais pesada. O insertion sort abaixo está quase pronto: faltam DUAS
// linhas, marcadas com "complete". Do jeito que está, ele compila, roda e
// mostra o vetor bagunçado. Complete e confira.
//
//   Saída esperada (depois de completar):
//   8 15 19 23 30
//
// Dicas:
// 1. Dentro do while, a mala malas[i] é maior que x: ela anda uma casa para
//    a direita.
// 2. Quando o while termina, i aponta para alguém que NÃO é maior que x (ou
//    vale -1). O buraco está uma casa à direita de i.
// 3. Resposta esperada: malas[i + 1] = malas[i]; dentro do while e
//    malas[i + 1] = x; depois dele.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int malas[] = {23, 15, 30, 8, 19};   // kg
    int n = 5;

    for (int j = 1; j < n; j++) {
        int x = malas[j];
        int i = j - 1;
        while (i >= 0 && malas[i] > x) {
            // complete: empurre malas[i] uma casa para a direita
            i--;
        }
        // complete: encaixe x no buraco
    }

    for (int k = 0; k < n; k++) {
        printf("%d ", malas[k]);
    }
    printf("\n");
    return 0;
}
