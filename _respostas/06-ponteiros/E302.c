// 0051 · void * e cast
// Exercício E302 · ★☆☆

#include <stdio.h>

int main(void) {
    int pontos[2] = {300, 450}; // pontos do cartão em dois meses
    void *p = pontos;

    printf("L1: %d\n", *(int *)p);                 // converta antes de ler
    int *q = p;                                     // void * vira int * sem cast
    printf("L2: %d\n", q[1]);
    p = (int *)p + 1;                               // anda um int, não um byte
    printf("L3: %d\n", *(int *)p);
    printf("L4: %.1f\n", (double)*(int *)p);        // lê o int, depois converte

    printf("pontos[0] = %d\n", pontos[0]);
    return 0;
}
