// 0097 · Selection sort
// Exercício E582 · ★★★

#include <stdio.h>

typedef struct {
    int codigo;
    double preco;
    char descricao[200];   // o que deixa a struct "pesada"
} Produto;

int main(void) {
    Produto loja[] = {
        {11, 249.90, "Fone sem fio"},
        {12, 89.90, "Mouse"},
        {13, 1299.00, "Monitor 24"},
        {14, 159.90, "Teclado"},
        {15, 49.90, "Mousepad"},
    };
    int n = 5;
    int ordem[5] = {0, 1, 2, 3, 4};   // ordem[k] = qual produto vem em k-ésimo
    int trocas = 0;

    // selection sort no vetor de índices, comparando os preços
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (loja[ordem[j]].preco < loja[ordem[menor]].preco) {
                menor = j;
            }
        }
        if (menor != i) {
            int aux = ordem[i];
            ordem[i] = ordem[menor];
            ordem[menor] = aux;
            trocas++;
        }
    }

    printf("Do mais barato ao mais caro:\n");
    for (int k = 0; k < n; k++) {
        const Produto *p = &loja[ordem[k]];
        printf("%d %-13s R$ %7.2f\n", p->codigo, p->descricao, p->preco);
    }
    printf("loja[0] continua sendo: %s\n", loja[0].descricao);
    printf("%d trocas de %zu bytes, em vez de %zu bytes\n",
           trocas, sizeof(int), sizeof(Produto));
    return 0;
}
