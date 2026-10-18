// 0053 · Pilha e heap
// Exercício E316 · ★★☆
//
// O vetor ocupa 5.000.000 * 4 = 20.000.000 bytes. Como local, ele não cabe
// na pilha de 8 MiB: o ASan acusa stack-overflow. Com static, ele vai para os
// dados (.bss), reservado quando o programa carrega.

#include <stdio.h>

#define TOTAL 5000000

int main(void) {
    static int leituras[TOTAL]; // dados, não pilha
    long soma = 0;

    for (int i = 0; i < TOTAL; i++) {
        leituras[i] = i % 7;
    }
    for (int i = 0; i < TOTAL; i++) {
        soma += leituras[i];
    }
    printf("O vetor ocupa %zu bytes\n", sizeof leituras);
    printf("Soma das leituras: %ld\n", soma);
    return 0;
}
// Saída:
// O vetor ocupa 20000000 bytes
// Soma das leituras: 14999995
