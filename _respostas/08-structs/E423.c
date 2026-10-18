// 0071 · Juntando tudo: o cardápio
// Exercício E423 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int qtd;
} Produto;

typedef struct {
    Produto *v;
    int n;
    int cap;
} Estoque;

bool estoque_adicionar(Estoque *e, const char *nome, int qtd) {
    if (e->n == e->cap) {
        int nova = e->cap == 0 ? 2 : 2 * e->cap;
        Produto *novo = realloc(e->v, nova * sizeof *novo);
        if (novo == NULL) {
            return false;
        }
        e->v = novo;
        e->cap = nova;
    }
    Produto *p = &e->v[e->n++];
    strncpy(p->nome, nome, sizeof p->nome - 1);
    p->nome[sizeof p->nome - 1] = '\0';
    p->qtd = qtd;
    return true;
}

bool estoque_remover(Estoque *e, const char *nome) {
    for (int i = 0; i < e->n; i++) {
        if (strcmp(e->v[i].nome, nome) == 0) {
            for (int j = i; j < e->n - 1; j++) {
                e->v[j] = e->v[j + 1];
            }
            e->n--;
            return true;
        }
    }
    return false;
}

void estoque_listar(const Estoque *e) {
    printf("%d produtos (capacidade %d):\n", e->n, e->cap);
    for (int i = 0; i < e->n; i++) {
        printf("  %s: %d\n", e->v[i].nome, e->v[i].qtd);
    }
}

void estoque_liberar(Estoque *e) {
    free(e->v);
    e->v = NULL;
    e->n = e->cap = 0;
}

void tentar_remover(Estoque *e, const char *nome) {
    printf("remover %s: %s\n", nome, estoque_remover(e, nome) ? "ok" : "não encontrado");
}

int main(void) {
    Estoque e = {NULL, 0, 0};
    const char *nomes[] = {"Arroz", "Feijão", "Café", "Açúcar", "Leite"};
    int qtds[] = {12, 30, 8, 15, 24};

    for (int i = 0; i < 5; i++) {
        if (!estoque_adicionar(&e, nomes[i], qtds[i])) {
            estoque_liberar(&e);
            return 1;
        }
    }
    tentar_remover(&e, "Feijão");
    tentar_remover(&e, "Macarrão");
    estoque_listar(&e);
    estoque_liberar(&e);
    return 0;
}
