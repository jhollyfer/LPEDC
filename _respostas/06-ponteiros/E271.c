// 0046 · Passagem por referência
// Exercício E271 · ★☆☆

#include <stdio.h>

void dobra(int *quantidade) {
    *quantidade = *quantidade * 2;
}

int main(void) {
    int ingressos = 3;

    printf("Antes: %d ingressos\n", ingressos);
    dobra(&ingressos);
    printf("Depois: %d ingressos\n", ingressos);
    return 0;
}
