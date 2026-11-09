// Lista · Módulo 11 · Listas
// Exercício P1130 · ★★★ · Somar matrizes esparsas

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int coluna;
    int valor;
    struct no *prox;
} No;

No *cria(int coluna, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No *insere(No *linha, int coluna, int valor) {
    No *novo = cria(coluna, valor);
    if (linha == NULL || coluna < linha->coluna) {
        novo->prox = linha;
        return novo;
    }
    No *p = linha;
    while (p->prox != NULL && p->prox->coluna < coluna) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return linha;
}

No *soma_linhas(const No *a, const No *b) {
    No *inicio = NULL, *fim = NULL;
    while (a != NULL || b != NULL) {
        int coluna, valor;
        if (b == NULL || (a != NULL && a->coluna < b->coluna)) {
            coluna = a->coluna;
            valor = a->valor;
            a = a->prox;
        } else if (a == NULL || b->coluna < a->coluna) {
            coluna = b->coluna;
            valor = b->valor;
            b = b->prox;
        } else { // mesma coluna
            coluna = a->coluna;
            valor = a->valor + b->valor;
            a = a->prox;
            b = b->prox;
        }
        if (valor != 0) {
            No *novo = cria(coluna, valor);
            if (fim == NULL) {
                inicio = novo;
            } else {
                fim->prox = novo;
            }
            fim = novo;
        }
    }
    return inicio;
}

void mostra_densa(No *m[], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        const No *p = m[i];
        for (int j = 0; j < colunas; j++) {
            if (p != NULL && p->coluna == j) {
                printf("%3d", p->valor);
                p = p->prox;
            } else {
                printf("%3d", 0);
            }
        }
        printf("\n");
    }
}

void libera(No *m[], int linhas) {
    for (int i = 0; i < linhas; i++) {
        No *p = m[i];
        while (p != NULL) {
            No *seguinte = p->prox;
            free(p);
            p = seguinte;
        }
        m[i] = NULL;
    }
}

int main(void) {
    int ta[5][3] = {{0, 1, 5}, {0, 4, 2}, {1, 0, 3}, {2, 2, -4}, {2, 3, 1}};
    int tb[5][3] = {{0, 1, -5}, {0, 2, 7}, {1, 0, 1}, {1, 4, 9}, {2, 3, 2}};
    No *a[3] = {NULL, NULL, NULL}, *b[3] = {NULL, NULL, NULL}, *s[3];
    for (int k = 0; k < 5; k++) {
        a[ta[k][0]] = insere(a[ta[k][0]], ta[k][1], ta[k][2]);
        b[tb[k][0]] = insere(b[tb[k][0]], tb[k][1], tb[k][2]);
    }
    int nao_nulos = 0;
    for (int i = 0; i < 3; i++) {
        s[i] = soma_linhas(a[i], b[i]);
        for (const No *p = s[i]; p != NULL; p = p->prox) {
            nao_nulos++;
        }
    }
    mostra_densa(s, 3, 5);
    printf("Não nulos: %d de 15\n", nao_nulos);
    libera(a, 3);
    libera(b, 3);
    libera(s, 3);
    return 0;
}
