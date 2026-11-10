// 0044 · Memória e endereços
// Exercício E262 · ★★☆

#include <stdio.h>

int main(void) {
    int pedidos = 15;
    int *p = &pedidos;

    printf("Valor: %d\n", pedidos);
    printf("Endereço: %p\n", (void *)&pedidos);
    printf("Pelo ponteiro: %p\n", (void *)p);
    printf("Mesmo endereço: %s\n", p == &pedidos ? "sim" : "não");
    return 0;
}
