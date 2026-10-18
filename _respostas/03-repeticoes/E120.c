// 0020 · While
// Exercício E120 · ★★★
//
// Resposta: A mostra "1 2 3 4 5 | 6" (a pergunta falsa, 5 < 5, ainda soma 1);
// B mostra "1 4" (100, 33, 11, 3, 1); C mostra "10": o corpo roda zero vezes,
// porque o while pergunta antes.

#include <stdio.h>

int main(void) {
    // trecho A
    int i = 0;
    while (i++ < 5) {
        printf("%d ", i);
    }
    printf("| %d\n", i);

    // trecho B
    int n = 100, voltas = 0;
    while (n > 1) {
        n = n / 3;
        voltas++;
    }
    printf("%d %d\n", n, voltas);

    // trecho C
    int k = 10;
    while (k < 10) {
        k++;
    }
    printf("%d\n", k);
    return 0;
}
