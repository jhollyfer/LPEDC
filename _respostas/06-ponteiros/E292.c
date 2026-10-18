// 0049 · Memória e endereços
// Exercício E292 · ★★☆
//
// Resposta: %d interpreta parte do endereço como int (número cortado, às
// vezes negativo); %x mostra só os 4 bytes de baixo; %p sem cast recebe um
// int *, mas o padrão pede void *. O certo é %p com (void *).

#include <stdio.h>

int main(void) {
    int pedidos = 15;

    printf("Endereço: %p\n", (void *)&pedidos);
    printf("Endereço: %p\n", (void *)&pedidos);
    printf("Endereço: %p\n", (void *)&pedidos);
    return 0;
}
