// 0051 · Passagem por referência
// Exercício E306 · ★★★
//
// Resposta: "x = 9, y = 4" e depois "x = 0". Na segunda chamada a e b
// apontam para a mesma gaveta (aliasing). x vale 9: *a = 18; *b = 18 - 18 = 0 (zera x, que é *a também);
// *a = 0 - 0 = 0. A troca com tmp do A101 não tem o problema: com a e b
// iguais, tmp guarda 9, *a = 9, *b = 9.

#include <stdio.h>

void troca_sem_aux(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(void) {
    int x = 4, y = 9;

    troca_sem_aux(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    troca_sem_aux(&x, &x);
    printf("x = %d\n", x);
    return 0;
}
