// Lista · Módulo 25 · Estruturas especiais
// Exercício P2508 · ★☆☆ · Os mais pedidos da lanchonete

#include <stdio.h>
#include <string.h>

#define N 5

typedef struct {
    const char *nome;
    int pedidos;
} Item;

// acha, soma 1 e sobe o item enquanto ele tiver mais pedidos que o da frente
int pede(Item v[], const char *nome) {
    for (int i = 0; i < N; i++) {
        if (strcmp(v[i].nome, nome) != 0) continue;
        v[i].pedidos++;
        while (i > 0 && v[i].pedidos > v[i - 1].pedidos) {
            Item t = v[i];
            v[i] = v[i - 1];
            v[i - 1] = t;
            i--;
        }
        return 1;
    }
    return 0;
}

int main(void) {
    Item cardapio[N] = {{"misto", 0}, {"coxinha", 0}, {"pastel", 0}, {"tapioca", 0}, {"suco", 0}};
    const char *dia[] = {"suco", "pastel", "suco", "coxinha", "pastel", "suco", "tapioca", "pastel", "pastel"};
    for (int k = 0; k < 9; k++) {
        pede(cardapio, dia[k]);
        printf("%-8s ->", dia[k]);
        for (int i = 0; i < N; i++) printf(" %s(%d)", cardapio[i].nome, cardapio[i].pedidos);
        printf("\n");
    }
    return 0;
}
