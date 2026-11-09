// Lista · Módulo 11 · Listas
// Exercício P1103 · ★☆☆ · Reajuste de preço achando o nó

#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    int codigo;
    double preco;
    struct produto *prox;
} Produto;

Produto *insere_inicio(Produto *inicio, int codigo, double preco) {
    Produto *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->codigo = codigo;
    novo->preco = preco;
    novo->prox = inicio;
    return novo;
}

void imprime(const char *rotulo, const Produto *inicio) {
    printf("%s", rotulo);
    for (const Produto *p = inicio; p != NULL; p = p->prox) {
        printf(" %d: %.2f |", p->codigo, p->preco);
    }
    printf("\n");
}

void libera(Produto *inicio) {
    while (inicio != NULL) {
        Produto *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

Produto *busca(Produto *inicio, int codigo) {
    for (Produto *p = inicio; p != NULL; p = p->prox) {
        if (p->codigo == codigo) {
            return p;
        }
    }
    return NULL;
}

void reajusta(Produto *inicio, int codigo, double fator) {
    Produto *p = busca(inicio, codigo);
    if (p == NULL) {
        printf("Código %d: não encontrado\n", codigo);
        return;
    }
    double antes = p->preco;
    p->preco = antes * fator; // muda o nó que está na lista
    printf("Código %d: %.2f -> %.2f\n", codigo, antes, p->preco);
}

int main(void) {
    Produto *lista = NULL;
    lista = insere_inicio(lista, 40, 6.00);
    lista = insere_inicio(lista, 30, 8.50);
    lista = insere_inicio(lista, 20, 3.20);
    lista = insere_inicio(lista, 10, 12.00);

    imprime("Antes: ", lista);
    reajusta(lista, 30, 1.10);
    reajusta(lista, 99, 1.10);
    imprime("Depois:", lista);
    libera(lista);
    return 0;
}
