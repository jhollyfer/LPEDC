// 0046 · Passagem por referência
// Exercício E276 · ★★★

#include <stdio.h>

void troca_sem_aux(int *a, int *b) {
    if (a == b) { // mesma gaveta: trocar com ela mesma não muda nada
        return;
    }
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
