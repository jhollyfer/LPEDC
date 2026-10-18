// 0098 · Insertion sort
// Exercício E586 · ★★☆
//
// Os pedidos de uma lanchonete chegam com o tempo de preparo, em minutos:
// 6, 3, 8, 3, 1. SEM RODAR, escreva a saída exata do programa abaixo: o vetor
// depois de cada encaixe, quantos deslocamentos cada encaixe fez e o total.
// Depois rode e confira.
//
// Dicas:
// 1. Antes do j = 3, a parte arrumada é 3 6 8. Quem o segundo 3 empurra?
// 2. Ele para ao encontrar o primeiro 3, porque 3 > 3 é falso.
// 3. O 1 atravessa todo mundo.
// 4. Resposta esperada: j = 1: 3 6 8 3 1 (deslocou 1); j = 2: 3 6 8 3 1
//    (deslocou 0); j = 3: 3 3 6 8 1 (deslocou 2); j = 4: 1 3 3 6 8 (deslocou
//    4); total: 7.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {
    int preparo[] = {6, 3, 8, 3, 1};
    int n = 5, total = 0;

    for (int j = 1; j < n; j++) {
        int x = preparo[j];
        int i = j - 1;
        int d = 0;
        while (i >= 0 && preparo[i] > x) {
            preparo[i + 1] = preparo[i];
            i--;
            d++;
        }
        preparo[i + 1] = x;
        total += d;
        printf("j = %d:", j);
        for (int k = 0; k < n; k++) {
            printf(" %d", preparo[k]);
        }
        printf(" (deslocou %d)\n", d);
    }
    printf("total: %d\n", total);
    return 0;
}
