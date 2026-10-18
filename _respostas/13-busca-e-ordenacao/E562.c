// 0094 · Busca sequencial
// Exercício E562 · ★★☆

#include <stdio.h>

typedef struct {
    int codigo;
    char nome[20];
    double preco;
} Produto;

// devolve o endereço do produto dentro do vetor, ou NULL
Produto *busca_produto(Produto v[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (v[i].codigo == codigo) {
            return &v[i];
        }
    }
    return NULL;
}

int main(void) {
    Produto estoque[] = {
        {1010, "Arroz 5kg", 27.50},
        {2050, "Café 500g", 18.90},
        {3300, "Feijão 1kg", 8.40},
        {4120, "Leite 1L", 5.20},
    };
    int n = 4;

    Produto *p = busca_produto(estoque, n, 2050);
    if (p != NULL) {
        printf("%d %s R$ %.2f\n", p->codigo, p->nome, p->preco);
        p->preco = p->preco * 1.10; // reajuste pelo ponteiro
    }
    printf("No vetor: %s R$ %.2f\n", estoque[1].nome, estoque[1].preco);

    p = busca_produto(estoque, n, 9999);
    if (p == NULL) {
        printf("9999: não cadastrado\n");
    }
    return 0;
}
