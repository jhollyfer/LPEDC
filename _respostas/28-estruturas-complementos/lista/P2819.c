// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2819 · ★★☆ · Aniversários em duas passadas

#include <stdio.h>

typedef struct {
    char nome[8];
    int dia, mes;
} Pessoa;

int chave(const Pessoa *p, int qual) {
    return qual == 0 ? p->dia : p->mes;
}

// pigeonhole estável pela chave escolhida (valores de 1 a max)
void passada(Pessoa *v, int n, int qual, int max) {
    Pessoa saida[16];
    int k = 0;
    for (int casa = 1; casa <= max; casa++) {
        for (int i = 0; i < n; i++) {
            if (chave(&v[i], qual) == casa) {
                saida[k++] = v[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
}

void mostra(const char *rotulo, const Pessoa *v, int n) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %s %d/%d", v[i].nome, v[i].dia, v[i].mes);
    }
    printf("\n");
}

int main(void) {
    Pessoa v[] = {{"Ana", 15, 3}, {"Beto", 2, 11}, {"Cris", 28, 3}, {"Duda", 2, 3},
                  {"Enzo", 15, 1}, {"Fabio", 9, 11}, {"Gil", 1, 12}, {"Hana", 30, 1}};
    passada(v, 8, 0, 31);
    mostra("por dia:", v, 8);
    passada(v, 8, 1, 12);
    mostra("por mês:", v, 8);
    return 0;
}
