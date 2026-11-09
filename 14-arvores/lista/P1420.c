// Lista · Módulo 14 · Árvores
// Exercício P1420 · ★★☆ · Em ordem sem recursão
//
// A recursão da em ordem usa a pilha de chamadas do C. Troque por uma pilha
// sua: escreva void em_ordem_iterativa(const No *r) com const No *pilha[32].
// O laço: desça para a esquerda empilhando cada nó; quando chegar em NULL,
// desempilhe, imprima e vá para a direita do desempilhado. Repita enquanto
// houver nó atual ou pilha não vazia. Mostre também o maior tamanho que a
// pilha alcançou.
//
// O main insere os códigos 41, 20, 65, 11, 29, 50, 91, 32, 72, 99.
//
//   Saída esperada:
//   em ordem: 11 20 29 32 41 50 65 72 91 99
//   pilha chegou a 3 nós
//
// Dicas:
// 1. while (p != NULL || topo > 0) { while (p != NULL) { empilha; p = p->esq; } ... }
// 2. A pilha nunca passa de altura + 1 nós. Esta árvore tem altura 3, mas
//    o caminho mais fundo (41, 20, 29, 32) sobe à direita, e quem vai à
//    direita é desempilhado antes: o máximo fica em 3.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int codigos[] = {41, 20, 65, 11, 29, 50, 91, 32, 72, 99};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, codigos[i]);
    }

    libera(raiz);
    return 0;
}
