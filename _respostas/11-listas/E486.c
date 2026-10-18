// 0081 · Juntando tudo
// Exercício E486 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct termo {
    int coef;
    int exp;
    struct termo *prox;
} Termo;

// põe coef·x^exp no lugar (expoentes decrescentes) e devolve o novo início
static Termo *insere_termo(Termo *inicio, int coef, int exp) {
    if (coef == 0) return inicio;
    Termo *ant = NULL;
    Termo *p = inicio;
    while (p != NULL && p->exp > exp) {
        ant = p;
        p = p->prox;
    }
    if (p != NULL && p->exp == exp) { // já existe: soma
        p->coef += coef;
        if (p->coef == 0) {           // zerou: o termo some
            if (ant == NULL) inicio = p->prox;
            else ant->prox = p->prox;
            free(p);
        }
        return inicio;
    }
    Termo *novo = malloc(sizeof(Termo));
    if (novo == NULL) exit(1);
    novo->coef = coef;
    novo->exp = exp;
    novo->prox = p;
    if (ant == NULL) return novo;
    ant->prox = novo;
    return inicio;
}

static Termo *soma(const Termo *p, const Termo *q) {
    Termo *r = NULL;
    for (; p != NULL; p = p->prox) r = insere_termo(r, p->coef, p->exp);
    for (; q != NULL; q = q->prox) r = insere_termo(r, q->coef, q->exp);
    return r;
}

static void imprime(const Termo *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    for (const Termo *t = p; t != NULL; t = t->prox) {
        int c = t->coef;
        if (t == p) {
            if (c < 0) printf("-");
        } else {
            printf(c < 0 ? " - " : " + ");
        }
        if (c < 0) c = -c;
        if (c != 1 || t->exp == 0) printf("%d", c);
        if (t->exp >= 1) printf("x");
        if (t->exp > 1) printf("^%d", t->exp);
    }
    printf("\n");
}

static long avalia(const Termo *p, int x) {
    long total = 0;
    for (; p != NULL; p = p->prox) {
        long potencia = 1;
        for (int i = 0; i < p->exp; i++) potencia *= x;
        total += p->coef * potencia;
    }
    return total;
}

static void libera(Termo *p) {
    while (p != NULL) {
        Termo *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}

int main(void) {
    Termo *p = NULL;
    p = insere_termo(p, -5, 0);
    p = insere_termo(p, 3, 4);
    p = insere_termo(p, 2, 2);
    Termo *q = NULL;
    q = insere_termo(q, 7, 1);
    q = insere_termo(q, -2, 2);
    q = insere_termo(q, 1, 4);

    printf("P(x) = ");
    imprime(p);
    printf("Q(x) = ");
    imprime(q);
    Termo *s = soma(p, q);
    printf("P + Q = ");
    imprime(s);
    printf("(P + Q)(2) = %ld\n", avalia(s, 2));

    libera(p);
    libera(q);
    libera(s);
    return 0;
}
