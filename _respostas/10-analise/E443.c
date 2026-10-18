// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E443 · ★★★
//
// Resposta: 5/6, 1/2, -1/2, 1/3 e 1/0 não existe.

#include <stdio.h>
#include <stdlib.h>

// ---- racional.h -----------------------------------------------------------
typedef struct racional Racional;

Racional *racional_cria(int num, int den); // NULL se den == 0 ou sem memória
void racional_libera(Racional *r);
Racional *racional_soma(const Racional *a, const Racional *b);
Racional *racional_multiplica(const Racional *a, const Racional *b);
void racional_imprime(const Racional *r);

// ---- racional.c -----------------------------------------------------------
// Invariante: den > 0 e mdc(|num|, den) == 1.
struct racional {
    int num;
    int den;
};

static int mdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Racional *racional_cria(int num, int den) {
    if (den == 0) {
        return NULL;
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int m = mdc(num < 0 ? -num : num, den);
    Racional *r = malloc(sizeof *r);
    if (r == NULL) {
        return NULL;
    }
    r->num = num / m;
    r->den = den / m;
    return r;
}

void racional_libera(Racional *r) {
    free(r);
}

Racional *racional_soma(const Racional *a, const Racional *b) {
    return racional_cria(a->num * b->den + b->num * a->den, a->den * b->den);
}

Racional *racional_multiplica(const Racional *a, const Racional *b) {
    return racional_cria(a->num * b->num, a->den * b->den);
}

void racional_imprime(const Racional *r) {
    printf("%d/%d", r->num, r->den);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    Racional *meio = racional_cria(1, 2);
    Racional *terco = racional_cria(1, 3);
    Racional *dois_quartos = racional_cria(2, 4);
    Racional *negativo = racional_cria(3, -6);
    Racional *dois_tercos = racional_cria(2, 3);
    Racional *soma = NULL, *produto = NULL;

    if (meio && terco && dois_quartos && negativo && dois_tercos) {
        soma = racional_soma(meio, terco);
        produto = racional_multiplica(meio, dois_tercos);
    }
    if (soma && produto) {
        printf("1/2 + 1/3 = ");
        racional_imprime(soma);
        printf("\n2/4 vira ");
        racional_imprime(dois_quartos);
        printf("\n3/-6 vira ");
        racional_imprime(negativo);
        printf("\n1/2 * 2/3 = ");
        racional_imprime(produto);
        printf("\n");
    }

    Racional *invalido = racional_cria(1, 0);
    if (invalido == NULL) {
        printf("1/0: não existe\n");
    }

    racional_libera(meio);
    racional_libera(terco);
    racional_libera(dois_quartos);
    racional_libera(negativo);
    racional_libera(dois_tercos);
    racional_libera(soma);
    racional_libera(produto);
    return 0;
}
