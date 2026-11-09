// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2706 · ★☆☆ · Três idades em ordem

#include <stdio.h>

void trocar(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void ordenar3(int *a, int *b, int *c) {
    if (*a > *b) trocar(a, b);
    if (*b > *c) trocar(b, c);
    if (*a > *b) trocar(a, b);
}

int main(void) {
    int pai = 30, filha = 12, mae = 25;
    printf("antes: %d %d %d\n", pai, filha, mae);
    ordenar3(&pai, &filha, &mae);
    printf("depois: %d %d %d\n", pai, filha, mae);
    return 0;
}
