// 0056 · void * e cast
// Exercício E332 · ★☆☆
//
// Resposta:
// L1: não compila: *p com void * ("invalid use of void expression").
// L2: compila e mostra 300 (void * vira int * sem cast em C).
// L3: compila com aviso do -pedantic (aritmética com void * é extensão do
//     gcc, que anda 1 byte); depois disso, *(int *)p lê um int fora do
//     lugar e o rodar acusa "load of misaligned address".
// L4: compila, mas lê 8 bytes onde só existe um int de 4: lixo e
//     stack-buffer-overflow no AddressSanitizer.
// O programa abaixo deixa só a L2, que é a correta.

#include <stdio.h>

int main(void) {
    int pontos = 300;
    void *p = &pontos;

    int *q = p;
    printf("%d\n", *q);

    printf("pontos = %d\n", *(int *)p);
    return 0;
}
