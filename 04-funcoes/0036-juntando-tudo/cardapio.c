// cardapio.c · a implementação do cardápio
#include <stdio.h>

#include "cardapio.h"

static int vendidos = 0; // só este arquivo mexe

void mostrar_cardapio(void) {
    printf("1 X-salada   R$ 18.50\n");
    printf("2 Batata     R$ 12.00\n");
    printf("3 Suco       R$  7.90\n");
    printf("4 Açaí       R$ 15.00\n");
}

int preco_centavos(int codigo) {
    int preco = 0;
    switch (codigo) {
    case 1: preco = 1850; break;
    case 2: preco = 1200; break;
    case 3: preco = 790; break;
    case 4: preco = 1500; break;
    }
    if (preco > 0) {
        vendidos++;
    }
    return preco;
}

void mostrar_item(int codigo) {
    switch (codigo) {
    case 1: printf("X-salada"); break;
    case 2: printf("Batata"); break;
    case 3: printf("Suco"); break;
    case 4: printf("Açaí"); break;
    default: printf("?"); break;
    }
}

int itens_vendidos(void) {
    return vendidos;
}
