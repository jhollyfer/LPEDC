// 0066 · Vetor de structs
// Exercício E391 · ★☆☆

#include <stdio.h>

typedef struct {
    char nome[20];
    int qtd;
    double preco;
} Item;

int main(void) {
    Item lista[] = {
        {"Arroz 5kg", 2, 27.90},
        {"Feijão", 3, 8.49},
        {"Café", 1, 18.90},
        {"Óleo", 4, 7.99},
    };
    int n = sizeof lista / sizeof lista[0];
    double total = 0;
    int mais_caro = 0;

    for (int i = 0; i < n; i++) {
        double sub = lista[i].qtd * lista[i].preco;
        printf("%s: R$ %.2f\n", lista[i].nome, sub);
        total += sub;
        if (sub > lista[mais_caro].qtd * lista[mais_caro].preco) {
            mais_caro = i;
        }
    }
    printf("Total: R$ %.2f\n", total);
    printf("Mais caro: %s\n", lista[mais_caro].nome);
    return 0;
}
