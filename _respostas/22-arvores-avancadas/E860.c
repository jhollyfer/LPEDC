// 0144 · Árvores gerais
// Exercício E860 · ★☆☆

#include <stdio.h>
#include "arvgen.h"

NoG *mais_caro(NoG *r) {
    if (r->filho == NULL) {
        return r; // folha: ela mesma é o item
    }
    NoG *melhor = NULL;
    for (NoG *p = r->filho; p != NULL; p = p->irmao) {
        NoG *c = mais_caro(p);
        if (melhor == NULL || c->valor > melhor->valor) {
            melhor = c;
        }
    }
    return melhor;
}

void mostra(const char *rotulo, NoG *r) {
    NoG *m = mais_caro(r);
    printf("Mais caro %s: %s (R$ %d)\n", rotulo, m->nome, m->valor);
}

int main(void) {
    NoG *lista = ag_cria("lista", 0);
    NoG *papelaria = ag_adiciona(lista, "papelaria", 0);
    ag_adiciona(papelaria, "caderno", 18);
    ag_adiciona(papelaria, "lapis", 3);
    ag_adiciona(papelaria, "estojo", 25);
    NoG *livros = ag_adiciona(lista, "livros", 0);
    ag_adiciona(livros, "gramatica", 89);
    ag_adiciona(livros, "atlas", 64);
    ag_adiciona(lista, "mochila", 120);

    mostra("da lista", lista);
    mostra("em livros", ag_busca(lista, "livros"));
    mostra("em papelaria", ag_busca(lista, "papelaria"));

    ag_libera(lista);
    return 0;
}
