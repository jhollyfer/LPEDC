// Lista · Módulo 12 · Pilhas e filas
// Exercício P1203 · ★☆☆ · A pilha de livros da cabeceira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
    char titulo[32];
    int paginas;
    struct livro *prox;
} Livro;

Livro *empilha(Livro *topo, const char *titulo, int paginas) {
    Livro *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->titulo, titulo);
    novo->paginas = paginas;
    novo->prox = topo;
    return novo;
}

Livro *desempilha(Livro *topo, char *titulo, int *paginas) {
    if (topo == NULL) {
        return NULL;
    }
    strcpy(titulo, topo->titulo);
    *paginas = topo->paginas;
    Livro *novo_topo = topo->prox;
    free(topo);
    return novo_topo;
}

int total_paginas(const Livro *topo) {
    int total = 0;
    for (const Livro *p = topo; p != NULL; p = p->prox) {
        total += p->paginas;
    }
    return total;
}

int main(void) {
    Livro *cabeceira = NULL;
    cabeceira = empilha(cabeceira, "Dom Casmurro", 256);
    cabeceira = empilha(cabeceira, "Vidas Secas", 176);
    cabeceira = empilha(cabeceira, "Capitães da Areia", 280);
    printf("Topo: %s\n", cabeceira->titulo);
    printf("Páginas na pilha: %d\n", total_paginas(cabeceira));
    while (cabeceira != NULL) {
        char titulo[32];
        int paginas;
        cabeceira = desempilha(cabeceira, titulo, &paginas);
        printf("Pegou %s (%d páginas)\n", titulo, paginas);
    }
    return 0;
}
