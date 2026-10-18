// A288 · A família vista como árvore binária

#include <stdio.h>
#include "arvgen.h"

// Lendo filho como "esquerdo" e irmão como "direito", o NoG vira um nó de
// árvore binária. As funções abaixo percorrem as DUAS leituras.

void pre_geral(const NoG *r) { // o nó, depois cada filho
    printf(" %s", r->nome);
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        pre_geral(p);
    }
}

void pos_geral(const NoG *r) { // cada filho, depois o nó
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        pos_geral(p);
    }
    printf(" %s", r->nome);
}

void pre_binaria(const NoG *r) { // raiz, esquerda (filho), direita (irmão)
    if (r != NULL) {
        printf(" %s", r->nome);
        pre_binaria(r->filho);
        pre_binaria(r->irmao);
    }
}

void em_ordem_binaria(const NoG *r) { // esquerda, raiz, direita
    if (r != NULL) {
        em_ordem_binaria(r->filho);
        printf(" %s", r->nome);
        em_ordem_binaria(r->irmao);
    }
}

int altura_binaria(const NoG *r) { // irmão conta como mais um nível aqui
    if (r == NULL) {
        return -1;
    }
    int he = altura_binaria(r->filho);
    int hd = altura_binaria(r->irmao);
    return 1 + (he > hd ? he : hd);
}

int main(void) {
    NoG *lucia = ag_cria("Lucia", 0);
    NoG *ana = ag_adiciona(lucia, "Ana", 0);
    ag_adiciona(ana, "Bia", 0);
    ag_adiciona(ana, "Caio", 0);
    ag_adiciona(lucia, "Davi", 0);
    NoG *eva = ag_adiciona(lucia, "Eva", 0);
    ag_adiciona(eva, "Fabio", 0);

    printf("Pré-ordem da geral:    ");
    pre_geral(lucia);
    printf("\nPré-ordem da binária:  ");
    pre_binaria(lucia);
    printf("\nPós-ordem da geral:    ");
    pos_geral(lucia);
    printf("\nEm ordem da binária:   ");
    em_ordem_binaria(lucia);
    printf("\nAltura da geral: %d | altura da binária: %d\n",
           ag_altura(lucia), altura_binaria(lucia));

    ag_libera(lucia);
    return 0;
}
// Saída:
// Pré-ordem da geral:     Lucia Ana Bia Caio Davi Eva Fabio
// Pré-ordem da binária:   Lucia Ana Bia Caio Davi Eva Fabio
// Pós-ordem da geral:     Bia Caio Ana Davi Fabio Eva Lucia
// Em ordem da binária:    Bia Caio Ana Davi Fabio Eva Lucia
// Altura da geral: 2 | altura da binária: 4
