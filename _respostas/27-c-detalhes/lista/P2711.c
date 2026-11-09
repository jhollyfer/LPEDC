// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2711 · ★★☆ · O estoque que não fica negativo

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char nome[20];
    unsigned qtd;
    double preco;
} Produto;

bool vender(Produto *p, unsigned q) {
    if (q > p->qtd) {
        return false; // confere antes: unsigned não fica negativo
    }
    p->qtd -= q;
    return true;
}

double valor_estoque(const Produto v[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += v[i].qtd * v[i].preco;
    }
    return total;
}

int main(void) {
    Produto v[] = {{"café", 10, 18.00}, {"açúcar", 4, 5.50}, {"leite", 12, 6.00}};
    unsigned pedidos[] = {3, 5, 12};
    for (int i = 0; i < 3; i++) {
        unsigned antes = v[i].qtd;
        if (vender(&v[i], pedidos[i])) {
            printf("vender %u %s: ok\n", pedidos[i], v[i].nome);
        } else {
            printf("vender %u %s: recusada (só %u)\n", pedidos[i], v[i].nome, antes);
        }
    }
    printf("%s: %u, %s: %u, %s: %u\n", v[0].nome, v[0].qtd, v[1].nome, v[1].qtd, v[2].nome, v[2].qtd);
    printf("valor em estoque: R$ %.2f\n", valor_estoque(v, 3));
    return 0;
}
