// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2817 · ★★☆ · Quem é estável?

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int num, bairro;
} Pedido;

void insercao(Pedido *v, int n) {
    for (int i = 1; i < n; i++) {
        Pedido x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].bairro > x.bairro) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void selecao(Pedido *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].bairro < v[m].bairro) {
                m = j;
            }
        }
        Pedido t = v[i];
        v[i] = v[m];
        v[m] = t;
    }
}

// pigeonhole com 3 casas: cada casa é percorrida na ordem de chegada
void pigeonhole(Pedido *v, int n) {
    Pedido saida[16];
    int k = 0;
    for (int casa = 1; casa <= 3; casa++) {
        for (int i = 0; i < n; i++) {
            if (v[i].bairro == casa) {
                saida[k++] = v[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
}

bool estavel(const Pedido *v, int n) {
    for (int i = 1; i < n; i++) {
        if (v[i].bairro == v[i - 1].bairro && v[i].num < v[i - 1].num) {
            return false;
        }
    }
    return true;
}

void testa(const char *nome, void (*ordena)(Pedido *, int)) {
    Pedido v[] = {{1, 2}, {2, 1}, {3, 2}, {4, 3}, {5, 1}, {6, 3}, {7, 2}, {8, 1}};
    ordena(v, 8);
    printf("%s", nome);
    for (int i = 0; i < 8; i++) {
        printf(" %d:%d", v[i].num, v[i].bairro);
    }
    printf(" | %s\n", estavel(v, 8) ? "estável" : "não estável");
}

int main(void) {
    testa("inserção:  ", insercao);
    testa("seleção:   ", selecao);
    testa("casas:     ", pigeonhole);
    return 0;
}
