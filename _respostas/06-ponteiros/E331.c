// 0056 · void * e cast
// Exercício E331 · ★☆☆

#include <stdio.h>

int main(void) {
    int idade = 41;
    double altura = 1.83;
    void *p;

    p = &idade;
    printf("idade: %d\n", *(int *)p);
    p = &altura;
    printf("altura: %.2f\n", *(double *)p);
    return 0;
}
