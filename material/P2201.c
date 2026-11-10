// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2201 · ★☆☆ · Quantos níveis tem o organograma?
//
// O organograma da prefeitura está numa árvore geral guardada como
// filho-esquerdo/irmão-direito: cada nó aponta para o PRIMEIRO filho e para
// o PRÓXIMO irmão. Complete altura(r), que devolve o número de níveis
// (uma árvore só com a raiz tem 1 nível; vazia, 0). O main já monta a
// árvore e mostra a resposta.
//
//   Prefeito
//   ├── Saúde
//   │   ├── UBS Centro
//   │   └── UBS Norte
//   │       └── Farmácia
//   ├── Educação
//   │   └── Creche
//   └── Obras
//
//   Saída esperada:
//   Níveis: 4
//
// Dicas:
// 1. A altura de r é 1 + a MAIOR altura entre os filhos. Os filhos são
//    r->filho, r->filho->irmao, r->filho->irmao->irmao...
// 2. Um jeito curto: altura(r) = max(1 + altura(r->filho), altura(r->irmao)).
//    O irmão está no mesmo nível, por isso não ganha o + 1.
// 3. Resposta esperada: 4 níveis (Prefeito, Saúde, UBS Norte, Farmácia).
//
// Escreva sua resposta abaixo (complete o código):

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

// pendura f como ÚLTIMO filho de p
void filho(No *p, No *f) {
    if (p->filho == NULL) {
        p->filho = f;
        return;
    }
    No *x = p->filho;
    while (x->irmao != NULL) {
        x = x->irmao;
    }
    x->irmao = f;
}

void libera(No *r) {
    if (r == NULL) {
        return;
    }
    libera(r->filho);
    libera(r->irmao);
    free(r);
}

int altura(const No *r) {
    (void)r;
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    No *pref = novo("Prefeito"), *saude = novo("Saúde"), *norte = novo("UBS Norte"), *educ = novo("Educação");
    filho(pref, saude);
    filho(pref, educ);
    filho(pref, novo("Obras"));
    filho(saude, novo("UBS Centro"));
    filho(saude, norte);
    filho(norte, novo("Farmácia"));
    filho(educ, novo("Creche"));
    printf("Níveis: %d\n", altura(pref));
    libera(pref);
    return 0;
}
