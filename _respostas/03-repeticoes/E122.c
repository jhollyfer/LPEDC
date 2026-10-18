// 0021 · Do-while
// Exercício E122 · ★☆☆
//
// Resposta: A mostra "| A terminou com n = 10" (zero voltas); B mostra
// "10 | B terminou com m = 11" (uma volta, mesmo com a condição falsa). Para
// o while imitar o do-while, é preciso copiar o corpo uma vez antes do laço.

#include <stdio.h>

int main(void) {
    // trecho A
    int n = 10;
    while (n < 5) {
        printf("%d ", n);
        n++;
    }
    printf("| A terminou com n = %d\n", n);

    // trecho B
    int m = 10;
    do {
        printf("%d ", m);
        m++;
    } while (m < 5);
    printf("| B terminou com m = %d\n", m);
    return 0;
}
