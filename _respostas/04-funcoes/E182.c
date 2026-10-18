// 0031 · A pilha de chamadas
// Exercício E182 · ★☆☆
//
// Resposta: a começa / b começa / c / b termina / c / a termina / c.
// No máximo 4 quadros ao mesmo tempo: main -> a -> b -> c.

#include <stdio.h>

void c(void) {
    printf("c\n");
}

void b(void) {
    printf("b começa\n");
    c();
    printf("b termina\n");
}

void a(void) {
    printf("a começa\n");
    b();
    c();
    printf("a termina\n");
}

int main(void) {
    a();
    c();
    return 0;
}
