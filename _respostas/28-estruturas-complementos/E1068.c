// 0178 · Hash: divisão e multiplicação
// Exercício E1068 · ★★★

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    uint32_t chave;
    struct Item *prox;
} Item;

typedef struct {
    Item **balde;
    int p; // m = 2^p
    int n;
} Tabela;

int indice(uint32_t k, int p) {
    uint32_t produto = k * 2654435769u;
    return (int)(produto >> (32 - p));
}

Item **novos_baldes(int p) {
    Item **b = calloc((size_t)1 << p, sizeof(Item *));
    if (b == NULL) {
        exit(1);
    }
    return b;
}

// dobra m e redistribui os nós que já existem (sem malloc novo por item)
void dobra(Tabela *t) {
    int m_velho = 1 << t->p;
    Item **velhos = t->balde;
    t->p++;
    t->balde = novos_baldes(t->p);
    for (int i = 0; i < m_velho; i++) {
        Item *it = velhos[i];
        while (it != NULL) {
            Item *seguinte = it->prox;
            int j = indice(it->chave, t->p);
            it->prox = t->balde[j];
            t->balde[j] = it;
            it = seguinte;
        }
    }
    free(velhos);
    printf("dobrou: m = %d (n = %d)\n", 1 << t->p, t->n);
}

void insere(Tabela *t, uint32_t chave) {
    if (t->n + 1 > (1 << t->p)) { // fator de carga passaria de 1
        dobra(t);
    }
    Item *it = malloc(sizeof(Item));
    if (it == NULL) {
        exit(1);
    }
    int j = indice(chave, t->p);
    it->chave = chave;
    it->prox = t->balde[j];
    t->balde[j] = it;
    t->n++;
}

int maior_lista(const Tabela *t) {
    int maior = 0;
    for (int i = 0; i < (1 << t->p); i++) {
        int tam = 0;
        for (const Item *it = t->balde[i]; it != NULL; it = it->prox) {
            tam++;
        }
        if (tam > maior) {
            maior = tam;
        }
    }
    return maior;
}

void libera(Tabela *t) {
    for (int i = 0; i < (1 << t->p); i++) {
        Item *it = t->balde[i];
        while (it != NULL) {
            Item *seguinte = it->prox;
            free(it);
            it = seguinte;
        }
    }
    free(t->balde);
}

int main(void) {
    Tabela t = {novos_baldes(2), 2, 0}; // começa com m = 4
    for (uint32_t i = 1; i <= 100; i++) {
        insere(&t, 1000 * i); // matrículas 1000, 2000, ..., 100000
    }
    printf("fim: n = %d, m = %d, fator de carga %.2f, maior lista %d\n", t.n, 1 << t.p,
           (double)t.n / (1 << t.p), maior_lista(&t));
    libera(&t);
    return 0;
}
