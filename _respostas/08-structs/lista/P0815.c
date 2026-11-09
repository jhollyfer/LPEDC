// Lista · Módulo 08 · Tipos compostos
// Exercício P0815 · ★★☆ · O estoque por categoria

#include <stdio.h>

typedef enum { HIDRAULICA, ELETRICA, PINTURA, FERRAGEM, N_CATEGORIAS } Categoria;

typedef struct {
    char nome[20];
    Categoria cat;
    int qtd;
    double preco;
} Produto;

int main(void) {
    const char *nome_cat[N_CATEGORIAS] = {"Hidráulica", "Elétrica", "Pintura", "Ferragem"};
    Produto v[7] = {
        {"Tubo PVC 25mm", HIDRAULICA, 40, 12.90},
        {"Fio 2,5mm (rolo)", ELETRICA, 15, 189.00},
        {"Tinta 18L", PINTURA, 8, 329.90},
        {"Registro 3/4", HIDRAULICA, 22, 45.50},
        {"Disjuntor 20A", ELETRICA, 30, 28.00},
        {"Parafuso (cento)", FERRAGEM, 60, 9.80},
        {"Rolo de lã", PINTURA, 25, 24.90},
    };
    int itens[N_CATEGORIAS] = {0};
    double valor[N_CATEGORIAS] = {0};

    for (int i = 0; i < 7; i++) {
        itens[v[i].cat] += v[i].qtd; // a categoria vira índice
        valor[v[i].cat] += v[i].qtd * v[i].preco;
    }
    Categoria maior = HIDRAULICA;
    for (Categoria c = HIDRAULICA; c < N_CATEGORIAS; c++) {
        printf("%3d itens  R$ %8.2f  %s\n", itens[c], valor[c], nome_cat[c]);
        if (valor[c] > valor[maior]) {
            maior = c;
        }
    }
    printf("Mais dinheiro parado: %s\n", nome_cat[maior]);
    return 0;
}
