// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2217 · ★★☆ · O cardápio entre parênteses

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    const char *nome;
    struct No *filho, *irmao;
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    n->nome = nome;
    n->filho = n->irmao = NULL;
    return n;
}

void filho(No *p, No *f) {
    No **x = &p->filho;
    while (*x != NULL) {
        x = &(*x)->irmao;
    }
    *x = f;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->filho);
        libera(r->irmao);
        free(r);
    }
}

void escreve(const No *r) {
    printf("%s", r->nome);
    if (r->filho != NULL) {
        printf("(");
        for (const No *f = r->filho; f != NULL; f = f->irmao) {
            escreve(f);
            if (f->irmao != NULL) {
                printf(" ");
            }
        }
        printf(")");
    }
}

int main(void) {
    No *card = novo("Cardápio"), *ent = novo("Entradas"), *pra = novo("Pratos"), *pei = novo("Peixe");
    filho(card, ent);
    filho(card, pra);
    filho(card, novo("Bebidas"));
    filho(ent, novo("Caldo"));
    filho(ent, novo("Bolinho"));
    filho(pra, pei);
    filho(pra, novo("Frango"));
    filho(pei, novo("Tambaqui"));
    filho(pei, novo("Pirarucu"));
    escreve(card);
    printf("\n");
    libera(card);
    return 0;
}
