// Lista · Módulo 08 · Tipos compostos
// Exercício P0817 · ★★☆ · Conserte a promoção da vitrine

#include <stdio.h>

typedef struct {
    char nome[20];
    double preco;
} Produto;

void promocao(Produto *v, int n) {
    for (int i = 0; i < n; i++) {
        Produto *p = &v[i]; // aponta para o original, não copia
        p->preco *= 0.85;
    }
}

double total(const Produto *v, int n) {
    double soma = 0;
    for (const Produto *p = v; p < v + n; p++) { // v + n não pode ser lido
        soma += p->preco;
    }
    return soma;
}

int main(void) {
    Produto vitrine[4] = {{"Rede de dormir", 120.00}, {"Cuia pintada", 35.00},
                          {"Colar de sementes", 48.00}, {"Farinha 1 kg", 14.00}};

    promocao(vitrine, 4);
    for (int i = 0; i < 4; i++) {
        printf("%-18s R$ %6.2f\n", vitrine[i].nome, vitrine[i].preco);
    }
    printf("%-18s R$ %6.2f\n", "Total", total(vitrine, 4));
    return 0;
}
