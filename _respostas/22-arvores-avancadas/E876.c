// 0146 · Árvore B
// Exercício E876 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define T 3               // grau mínimo: de 2 a 5 chaves por nó (a raiz pode ter 1)
#define MAX (2 * T - 1)

typedef struct Bloco {
    int n;
    int chave[MAX];
    struct Bloco *filho[MAX + 1];
    bool folha;
} Bloco;

Bloco *novo_bloco(bool folha) {
    Bloco *b = malloc(sizeof(Bloco));
    if (b == NULL) {
        exit(1);
    }
    b->n = 0;
    b->folha = folha;
    return b;
}

void divide(Bloco *pai, int i) {
    Bloco *y = pai->filho[i];
    Bloco *z = novo_bloco(y->folha);
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
    for (int j = pai->n; j > i; j--) {
        pai->filho[j + 1] = pai->filho[j];
    }
    pai->filho[i + 1] = z;
    for (int j = pai->n - 1; j >= i; j--) {
        pai->chave[j + 1] = pai->chave[j];
    }
    pai->chave[i] = y->chave[T - 1];
    pai->n++;
}

void insere_nao_cheio(Bloco *x, int chave) {
    int i = x->n - 1;
    if (x->folha) {
        while (i >= 0 && chave < x->chave[i]) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        x->chave[i + 1] = chave;
        x->n++;
        return;
    }
    while (i >= 0 && chave < x->chave[i]) {
        i--;
    }
    i++;
    if (x->filho[i]->n == MAX) {
        divide(x, i);
        if (chave > x->chave[i]) {
            i++;
        }
    }
    insere_nao_cheio(x->filho[i], chave);
}

Bloco *insere(Bloco *raiz, int chave) {
    if (raiz == NULL) {
        raiz = novo_bloco(true);
    }
    if (raiz->n == MAX) {
        Bloco *s = novo_bloco(false);
        s->filho[0] = raiz;
        divide(s, 0);
        raiz = s;
    }
    insere_nao_cheio(raiz, chave);
    return raiz;
}

int leituras(const Bloco *b, int chave, bool *achou) {
    int lidos = 0;
    *achou = false;
    while (b != NULL) {
        lidos++;
        int i = 0;
        while (i < b->n && chave > b->chave[i]) {
            i++;
        }
        if (i < b->n && chave == b->chave[i]) {
            *achou = true;
            break;
        }
        b = b->folha ? NULL : b->filho[i];
    }
    return lidos;
}

int altura(const Bloco *b) {
    int h = 0;
    while (!b->folha) {
        b = b->filho[0];
        h++;
    }
    return h;
}

void mostra_nivel(const Bloco *b, int nivel) {
    if (nivel == 0) {
        printf(" [");
        for (int i = 0; i < b->n; i++) {
            printf(i > 0 ? " %d" : "%d", b->chave[i]);
        }
        printf("]");
        return;
    }
    for (int i = 0; i <= b->n; i++) {
        mostra_nivel(b->filho[i], nivel - 1);
    }
}

void libera(Bloco *b) {
    if (!b->folha) {
        for (int i = 0; i <= b->n; i++) {
            libera(b->filho[i]);
        }
    }
    free(b);
}

int main(void) {
    Bloco *raiz = NULL;
    for (int i = 1; i <= 30; i++) {
        raiz = insere(raiz, i * 7 % 31); // 7, 14, 21, 28, 4, 11, ...
    }
    for (int d = 0; d <= altura(raiz); d++) {
        printf("nível %d:", d);
        mostra_nivel(raiz, d);
        printf("\n");
    }
    int procura[] = {23, 31};
    for (int k = 0; k < 2; k++) {
        bool achou;
        int lidos = leituras(raiz, procura[k], &achou);
        printf("busca %d: %s, %d blocos lidos\n", procura[k], achou ? "achou" : "não achou", lidos);
    }
    libera(raiz);
    return 0;
}
