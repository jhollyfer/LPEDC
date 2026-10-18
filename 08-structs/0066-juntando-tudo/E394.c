// 0066 · Juntando tudo: o cardápio
// Exercício E394 · ★★☆
//
// Este programa compila sem aviso, mas tem três bugs. O AddressSanitizer
// pega dois deles (um de cada vez: conserte e rode de novo); o terceiro é de
// lógica e só aparece comparando com a saída esperada. Ache e conserte os
// três.
//
//   Saída esperada (depois de consertado):
//   X-Burger R$ 28.90
//   Suco de caju R$ 9.00 [destaque]
//   Pudim R$ 12.00 [destaque]
//   -- tira o destaque do suco --
//   X-Burger R$ 28.90
//   Suco de caju R$ 9.00
//   Pudim R$ 12.00 [destaque]
//
// Dicas:
// 1. Leia a primeira linha do relatório do ASan: heap-buffer-overflow aponta
//    para uma leitura além do fim do vetor. Confira a condição do laço.
// 2. "detected memory leaks" quer dizer um malloc sem free.
// 3. Para desligar um bit, o E é com o inverso da máscara.
// 4. Resposta esperada: i <= n vira i < n; falta free(itens) no fim;
//    itens[1].tags &= DESTAQUE vira itens[1].tags &= ~DESTAQUE.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESTAQUE (1u << 0)
#define VEGANO   (1u << 1)

typedef struct {
    char nome[20];
    double preco;
    unsigned tags;
} Item;

void listar(const Item *itens, int n) {
    for (int i = 0; i <= n; i++) {
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
    itens[1].tags &= DESTAQUE;
    listar(itens, n);
    return 0;
}
