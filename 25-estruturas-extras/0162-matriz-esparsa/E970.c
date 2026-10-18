// 0162 · Matriz esparsa
// Exercício E970 · ★★☆
//
// Ache o bug. Este programa tem a sua própria versão de define (sem usar o
// esparsa.h) e grava as vendas de 2 vendedores em 7 dias da semana. A tela
// mostra só 2 vendas, o contador diz 5 e o AddressSanitizer acusa vazamento
// de memória (memory leak) no fim:
//
//   Saída que aparece:
//   Vendedor 0: 15  0  0  0  0  0  0
//   Vendedor 1:  0 12  0  0  0  0  0
//   Células: 5
//
//   Saída esperada (sem nenhum erro do sanitizer):
//   Vendedor 0: 15  0 20  0  0 30  0
//   Vendedor 1:  0 12  0  0 40  0  0
//   Células: 5
//
// Ache a linha errada, conserte e rode de novo.
//
// Dicas:
// 1. Repare quem sumiu: 30, 20 e 40. Os valores 20, 15 e 12 entram ANTES de
//    todas as células que já estavam na linha. Siga o caso ant == NULL.
// 2. Quando a célula nova vira a primeira da linha, para onde aponta
//    nova->prox? E o que acontece com as células que já estavam lá?
// 3. Resposta esperada: no caso ant == NULL falta nova->prox = m->linha[i]
//    (ou p) antes de m->linha[i] = nova. Sem isso, a linha antiga se perde.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int col, valor;
    struct Celula *prox;
} Celula;

typedef struct {
    int linhas, colunas, nao_zeros;
    Celula **linha;
} Esparsa;

Esparsa *cria(int linhas, int colunas) {
    Esparsa *m = malloc(sizeof(Esparsa));
    if (m == NULL) {
        exit(1);
    }
    m->linha = calloc(linhas, sizeof(Celula *)); // calloc: tudo NULL
    if (m->linha == NULL) {
        exit(1);
    }
    m->linhas = linhas;
    m->colunas = colunas;
    m->nao_zeros = 0;
    return m;
}

// só insere ou troca (este programa nunca grava zero)
void define(Esparsa *m, int i, int j, int valor) {
    Celula *ant = NULL;
    Celula *p = m->linha[i];
    while (p != NULL && p->col < j) {
        ant = p;
        p = p->prox;
    }
    if (p != NULL && p->col == j) {
        p->valor = valor;
        return;
    }
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        exit(1);
    }
    nova->col = j;
    nova->valor = valor;
    nova->prox = NULL;
    if (ant == NULL) {
        m->linha[i] = nova;
    } else {
        nova->prox = ant->prox;
        ant->prox = nova;
    }
    m->nao_zeros++;
}

void mostra_linha(const Esparsa *m, int i) {
    const Celula *p = m->linha[i];
    for (int j = 0; j < m->colunas; j++) {
        if (p != NULL && p->col == j) {
            printf("%3d", p->valor);
            p = p->prox;
        } else {
            printf("%3d", 0);
        }
    }
    printf("\n");
}

void libera(Esparsa *m) {
    for (int i = 0; i < m->linhas; i++) {
        while (m->linha[i] != NULL) {
            Celula *prox = m->linha[i]->prox;
            free(m->linha[i]);
            m->linha[i] = prox;
        }
    }
    free(m->linha);
    free(m);
}

int main(void) {
    Esparsa *vendas = cria(2, 7);
    define(vendas, 0, 5, 30);
    define(vendas, 1, 4, 40);
    define(vendas, 0, 2, 20);
    define(vendas, 1, 1, 12);
    define(vendas, 0, 0, 15);

    for (int i = 0; i < vendas->linhas; i++) {
        printf("Vendedor %d:", i);
        mostra_linha(vendas, i);
    }
    printf("Células: %d\n", vendas->nao_zeros);

    libera(vendas);
    return 0;
}
