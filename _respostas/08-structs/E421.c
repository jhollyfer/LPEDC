// 0071 · Juntando tudo: o cardápio
// Exercício E421 · ★☆☆

#include <stdio.h>

typedef enum { HORTIFRUTI, LATICINIOS, PADARIA } Setor;

#define PROMO       (1u << 0)
#define ORGANICO    (1u << 1)
#define REFRIGERADO (1u << 2)

typedef struct {
    char nome[24];
    Setor setor;
    double preco;
    unsigned flags;
} Produto;

void etiqueta(const Produto *p) {
    const char *setores[] = {"hortifrúti", "laticínios", "padaria"};
    printf("%s (%s) R$ %.2f/kg", p->nome, setores[p->setor], p->preco);
    if (p->flags & PROMO) printf(" [promo]");
    if (p->flags & ORGANICO) printf(" [orgânico]");
    if (p->flags & REFRIGERADO) printf(" [refrigerado]");
    printf("\n");
}

int main(void) {
    Produto prateleira[] = {
        {"Banana prata", HORTIFRUTI, 6.99, ORGANICO},
        {"Iogurte natural", LATICINIOS, 4.50, PROMO | REFRIGERADO},
        {"Pão francês", PADARIA, 16.90, 0},
    };

    for (int i = 0; i < 3; i++) {
        etiqueta(&prateleira[i]);
    }
    return 0;
}
