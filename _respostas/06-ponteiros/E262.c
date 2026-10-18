// 0044 · Memória e endereços
// Exercício E262 · ★★☆

#include <stdio.h>

int main(void) {
    int pedidos = 15;

    // %d e %x leem só 4 bytes; %p sem cast recebe int *, e o padrão pede void *
    printf("Endereço: %p\n", (void *)&pedidos);
    printf("Endereço: %p\n", (void *)&pedidos);
    printf("Endereço: %p\n", (void *)&pedidos);
    return 0;
}
