// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2210 · ★☆☆ · A árvore B andar por andar
//
// O programa abaixo insere os códigos 1 a 12, em ordem, numa árvore B de
// grau mínimo t = 2. Para ver a forma da árvore, escreva mostra_niveis(r):
// um percurso em LARGURA com uma fila de ponteiros (um vetor basta), que
// mostra cada nó como [chaves] e põe cada nível numa linha.
//
//   Saída esperada:
//   Nível 0: [4]
//   Nível 1: [2] [6 8 10]
//   Nível 2: [1] [3] [5] [7] [9] [11 12]
//
// Dicas:
// 1. Fila: NoB *fila[64]; ini e fim. Para separar os níveis, guarde também
//    o nível de cada nó (outro vetor) e quebre a linha quando ele mudar.
// 2. Ao tirar um nó que não é folha, ponha na fila os seus n + 1 filhos.
// 3. Resposta esperada: 3 níveis, com [4] na raiz e [2] e [6 8 10] embaixo.
//    Todas as folhas ficam no mesmo nível: é a regra da árvore B.
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

void mostra_niveis(NoB *r) {
    (void)r;
    // COMPLETE AQUI
}

int main(void) {
    NoB *r = NULL;
    for (int k = 1; k <= 12; k++) {
        r = insere(r, k);
    }
    mostra_niveis(r);
    libera(r);
    return 0;
}
