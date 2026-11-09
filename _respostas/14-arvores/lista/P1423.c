// Lista · Módulo 14 · Árvores
// Exercício P1423 · ★★★ · A árvore da expressão

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No {
    char c;
    struct No *esq, *dir;
} No;

No *novo(char c, No *esq, No *dir) {
    No *p = malloc(sizeof(No));
    if (p == NULL) {
        exit(1);
    }
    p->c = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

// lê a posfixa com uma pilha de árvores
No *monta(const char *posfixa) {
    No *pilha[32];
    int topo = 0;
    for (const char *s = posfixa; *s != '\0'; s++) {
        if (*s == ' ') {
            continue;
        }
        if (isdigit((unsigned char)*s)) {
            pilha[topo++] = novo(*s, NULL, NULL);
        } else {
            No *d = pilha[--topo]; // o de cima é o operando da DIREITA
            No *e = pilha[--topo];
            pilha[topo++] = novo(*s, e, d);
        }
    }
    return pilha[0];
}

void infixa(const No *r) {
    if (r->esq == NULL) {
        printf("%c", r->c);
        return;
    }
    printf("(");
    infixa(r->esq);
    printf(" %c ", r->c);
    infixa(r->dir);
    printf(")");
}

void prefixa(const No *r) {
    if (r != NULL) {
        printf(" %c", r->c);
        prefixa(r->esq);
        prefixa(r->dir);
    }
}

int avalia(const No *r) {
    if (r->esq == NULL) {
        return r->c - '0';
    }
    int a = avalia(r->esq), b = avalia(r->dir);
    switch (r->c) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        return a / b;
    }
}

int altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura(r->esq), hd = altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    const char *contas[] = {"3 4 + 2 *", "9 5 - 8 2 / *", "6 2 3 * + 8 4 - /"};
    for (int i = 0; i < 3; i++) {
        No *r = monta(contas[i]);
        printf("posfixa: %s\n  infixa: ", contas[i]);
        infixa(r);
        printf("\n  prefixa:");
        prefixa(r);
        printf("\n  valor: %d, altura: %d\n", avalia(r), altura(r));
        libera(r);
    }
    return 0;
}
