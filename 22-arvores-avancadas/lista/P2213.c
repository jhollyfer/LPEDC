// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2213 · ★★☆ · Quantas divisões custa encher a árvore B
//
// O programa abaixo tem a árvore B do assunto 0146 com o grau mínimo t
// numa variável (até 4), e insere os códigos 1 a 40, em ordem. Estenda-o:
// conte as DIVISÕES de nó, conte os nós da árvore pronta e calcule a altura
// (em arestas), e rode para t = 2, 3 e 4.
//
//   Saída esperada:
//   t = 2: 31 divisões, 36 nós, altura 4
//   t = 3: 15 divisões, 18 nós, altura 2
//   t = 4: 10 divisões, 13 nós, altura 2
//
// Dicas:
// 1. Um contador global divisoes++ dentro de divide().
// 2. nos(x) = 1 + soma de nos dos filhos; a altura é quantas vezes dá para
//    descer pelo filho[0] até uma folha.
// 3. Resposta esperada: com t maior, menos divisões, menos nós e uma
//    árvore mais baixa (veja os números). É por isso que árvores B de
//    disco usam t na casa das centenas.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXT 4
#define MAXK (2 * MAXT - 1)

int t; // grau mínimo atual

typedef struct NoB {
    int n;
    int chave[MAXK];
    struct NoB *filho[MAXK + 1];
    bool folha;
} NoB;

NoB *novo_no(bool folha) {
    NoB *x = calloc(1, sizeof *x);
    if (x == NULL) {
        exit(1);
    }
    x->folha = folha;
    return x;
}

void divide(NoB *x, int i) {
    NoB *y = x->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        z->chave[j] = y->chave[j + t];
    }
    if (!y->folha) {
        for (int j = 0; j < t; j++) {
            z->filho[j] = y->filho[j + t];
        }
    }
    y->n = t - 1;
    for (int j = x->n; j > i; j--) {
        x->filho[j + 1] = x->filho[j];
    }
    x->filho[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }
    x->chave[i] = y->chave[t - 1];
    x->n++;
}

void insere_nao_cheio(NoB *x, int k) {
    int i = x->n - 1;
    if (x->folha) {
        while (i >= 0 && k < x->chave[i]) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        x->chave[i + 1] = k;
        x->n++;
        return;
    }
    while (i >= 0 && k < x->chave[i]) {
        i--;
    }
    i++;
    if (x->filho[i]->n == 2 * t - 1) {
        divide(x, i);
        if (k > x->chave[i]) {
            i++;
        }
    }
    insere_nao_cheio(x->filho[i], k);
}

NoB *insere(NoB *r, int k) {
    if (r == NULL) {
        r = novo_no(true);
    }
    if (r->n == 2 * t - 1) {
        NoB *s = novo_no(false);
        s->filho[0] = r;
        divide(s, 0);
        insere_nao_cheio(s, k);
        return s;
    }
    insere_nao_cheio(r, k);
    return r;
}

void libera(NoB *x) {
    if (x != NULL) {
        for (int i = 0; i <= x->n; i++) {
            libera(x->filho[i]);
        }
        free(x);
    }
}

int main(void) {
    for (t = 2; t <= MAXT; t++) {
        NoB *r = NULL;
        for (int k = 1; k <= 40; k++) {
            r = insere(r, k);
        }
        printf("t = %d: raiz com %d chave(s)\n", t, r->n);
        libera(r);
    }
    return 0;
}
