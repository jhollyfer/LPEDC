// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2227 · ★★★ · A busca que desce pelo filho errado
//
// Este programa tem um erro de propósito. A árvore B (t = 2) dos
// prontuários do hospital recebe os números de 10 a 200, de 10 em 10, e
// depois procura alguns. A inserção está certa; a busca tem UM erro. Ela
// compila sem aviso e roda limpo, mas dos 7 prontuários que existem só
// acha o 80. Conserte a busca.
//
//   Saída esperada:
//   Prontuário 10: achado
//   Prontuário 30: achado
//   Prontuário 80: achado
//   Prontuário 120: achado
//   Prontuário 150: achado
//   Prontuário 190: achado
//   Prontuário 200: achado
//   Prontuário 55: não existe
//   Achados: 7 de 8
//
// Dicas:
// 1. Instrumente: mostre as chaves de cada nó visitado. Procure 30 e
//    acompanhe a descida.
// 2. Num nó com chaves c[0] < c[1] < ... < c[n - 1], o filho i guarda as
//    chaves entre c[i - 1] e c[i]. Se o laço parou em i (o primeiro com k
//    <= c[i]), k está entre c[i - 1] e c[i]: qual filho é esse?
// 3. Resposta esperada: desça por x->filho[i], não x->filho[i + 1]. Com
//    isso, todos os prontuários de 10 a 200 são achados e o 55 não.
//
// Escreva sua resposta abaixo (conserte o código):

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

int busca(const NoB *x, int k) {
    while (x != NULL) {
        int i = 0;
        while (i < x->n && k > x->chave[i]) {
            i++;
        }
        if (i < x->n && x->chave[i] == k) {
            return 1;
        }
        if (x->folha) {
            return 0;
        }
        x = x->filho[i + 1];
    }
    return 0;
}

int main(void) {
    NoB *r = NULL;
    for (int k = 10; k <= 200; k += 10) {
        r = insere(r, k);
    }
    const int procura[8] = {10, 30, 80, 120, 150, 190, 200, 55};
    int achados = 0;
    for (int i = 0; i < 8; i++) {
        int a = busca(r, procura[i]);
        achados += a;
        printf("Prontuário %d: %s\n", procura[i], a ? "achado" : "não existe");
    }
    printf("Achados: %d de 8\n", achados);
    libera(r);
    return 0;
}
