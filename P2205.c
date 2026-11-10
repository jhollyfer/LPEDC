// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2205 · ★☆☆ · Quantas páginas a busca lê
//
// O cartório guarda os números de protocolo numa árvore B com grau mínimo
// t = 2 (cada nó tem de 1 a 3 chaves). Num disco, cada nó é uma PÁGINA, e
// ler uma página é o que custa caro. O programa abaixo já insere os
// protocolos 5, 10, 15, ..., 100. Escreva busca(x, k, &paginas): ela
// procura k a partir do nó x, conta cada nó visitado e devolve 1 se achou.
// Procure 40, 60, 42 e 100.
//
//   Saída esperada:
//   Protocolo 40: achado (páginas lidas: 1)
//   Protocolo 60: achado (páginas lidas: 2)
//   Protocolo 42: não existe (páginas lidas: 4)
//   Protocolo 100: achado (páginas lidas: 4)
//
// Dicas:
// 1. Em cada nó: (*paginas)++; ache o primeiro i com k <= chave[i]. Se
//    i < n e chave[i] == k, achou.
// 2. Se não achou e o nó é folha, k não está na árvore; senão, desça para
//    filho[i].
// 3. Resposta esperada: o 40 está na raiz (1 página) e o 60 no nível de
//    baixo (2); o 42 não existe e o 100 está numa folha: 4 páginas cada, o
//    número de níveis da árvore.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define T 2
#define MAXC (2 * T - 1)

typedef struct NoB {
    int n;
    int chave[MAXC];
    struct NoB *filho[MAXC + 1];
    bool folha;
} NoB;

NoB *novo_no(bool folha) {
    NoB *x = malloc(sizeof *x);
    if (x == NULL) {
        exit(1);
    }
    x->n = 0;
    x->folha = folha;
    for (int i = 0; i <= MAXC; i++) {
        x->filho[i] = NULL;
    }
    return x;
}

// o filho i de x está cheio: a chave do meio sobe para x
void divide(NoB *x, int i) {
    NoB *y = x->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = T - 1;
    for (int j = 0; j < T - 1; j++) {
        z->chave[j] = y->chave[j + T];
    }
    if (!y->folha) {
        for (int j = 0; j < T; j++) {
            z->filho[j] = y->filho[j + T];
        }
    }
    y->n = T - 1;
    for (int j = x->n; j > i; j--) {
        x->filho[j + 1] = x->filho[j];
    }
    x->filho[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }
    x->chave[i] = y->chave[T - 1];
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
    if (x->filho[i]->n == MAXC) {
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
    if (r->n == MAXC) {
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
    if (x == NULL) {
        return;
    }
    for (int i = 0; i <= x->n; i++) {
        libera(x->filho[i]);
    }
    free(x);
}

int busca(const NoB *x, int k, int *paginas) {
    (void)x;
    (void)k;
    (void)paginas;
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    NoB *r = NULL;
    for (int k = 5; k <= 100; k += 5) {
        r = insere(r, k);
    }
    const int procura[4] = {40, 60, 42, 100};
    for (int i = 0; i < 4; i++) {
        int paginas = 0;
        int achou = busca(r, procura[i], &paginas);
        printf("Protocolo %d: %s (páginas lidas: %d)\n", procura[i], achou ? "achado" : "não existe", paginas);
    }
    libera(r);
    return 0;
}
