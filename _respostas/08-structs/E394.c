// 0066 · Juntando tudo: o cardápio
// Exercício E394 · ★★☆
//
// Resposta: (1) o laço de listar ia até i <= n e lia um item além do fim
// (heap-buffer-overflow): o certo é i < n; (2) faltava free(itens) (memory
// leak); (3) itens[1].tags &= DESTAQUE apagava todos os bits MENOS o
// destaque: para desligar, &= ~DESTAQUE.

#include <stdio.h>
#include <stdlib.h>

#define DESTAQUE (1u << 0)
#define VEGANO   (1u << 1)

typedef struct {
    char nome[20];
    double preco;
    unsigned tags;
} Item;

void listar(const Item *itens, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s R$ %.2f%s\n", itens[i].nome, itens[i].preco,
               (itens[i].tags & DESTAQUE) ? " [destaque]" : "");
    }
}

int main(void) {
    int n = 3;
    Item *itens = malloc(n * sizeof *itens);
    if (itens == NULL) {
        return 1;
    }
    itens[0] = (Item){"X-Burger", 28.90, 0};
    itens[1] = (Item){"Suco de caju", 9.00, DESTAQUE | VEGANO};
    itens[2] = (Item){"Pudim", 12.00, DESTAQUE};

    listar(itens, n);
    printf("-- tira o destaque do suco --\n");
    itens[1].tags &= ~DESTAQUE;
    listar(itens, n);
    free(itens);
    return 0;
}
