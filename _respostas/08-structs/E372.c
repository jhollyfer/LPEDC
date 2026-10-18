// 0062 · Ponteiro para struct
// Exercício E372 · ★★★

#include <stdio.h>

typedef struct Pessoa {
    char nome[10];
    int idade;
    struct Pessoa *amigo;
} Pessoa;

// segue as setas a partir de p, mostrando passos + 1 nomes
void seguir(const Pessoa *p, int passos) {
    printf("%s", p->nome);
    for (int i = 0; i < passos; i++) {
        p = p->amigo;
        printf(" -> %s", p->nome);
    }
    printf("\n");
}

// conta quantas pessoas há na roda até voltar para quem começou
int tamanho_da_roda(const Pessoa *inicio) {
    int n = 1;
    for (const Pessoa *p = inicio->amigo; p != inicio; p = p->amigo) {
        n++;
    }
    return n;
}

// anda pela roda procurando a pessoa mais velha
const Pessoa *mais_velha(const Pessoa *inicio) {
    const Pessoa *m = inicio;
    for (const Pessoa *p = inicio->amigo; p != inicio; p = p->amigo) {
        if (p->idade > m->idade) {
            m = p;
        }
    }
    return m;
}

int main(void) {
    Pessoa g[3] = {{"Ana", 30, NULL}, {"Bia", 25, NULL}, {"Caio", 41, NULL}};
    g[0].amigo = &g[2];
    g[1].amigo = &g[0];
    g[2].amigo = &g[1];

    seguir(&g[0], 4);
    printf("Roda da Ana: %d pessoas\n", tamanho_da_roda(&g[0]));
    const Pessoa *m = mais_velha(&g[1]);
    printf("Maior idade: %s (%d)\n", m->nome, m->idade);
    printf("sizeof(Pessoa) = %zu\n", sizeof(Pessoa));
    return 0;
}
