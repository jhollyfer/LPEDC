// 0031 · A pilha de chamadas
// Exercício E182 · ★☆☆

#include <stdio.h>

void c(void) {
    static int vezes = 0;
    vezes++;
    printf("c (vez %d)\n", vezes);
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
