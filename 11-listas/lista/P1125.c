// Lista · Módulo 11 · Listas
// Exercício P1125 · ★★★ · A lista dupla com três setas esquecidas
//
// A lista dupla abaixo compila sem aviso, e a impressão de ida até parece
// certa, mas a volta sai errada e o sanitizer acusa "heap-use-after-free".
// São TRÊS erros de propósito, todos de setas que deixaram de ser
// atualizadas: um em insere_inicio e dois em remove_valor. Conserte os três.
//
//   Saída esperada:
//   Ida:   1 2 3 4
//   Volta: 4 3 2 1
//   Depois de remover 4 e 1:
//   Ida:   2 3
//   Volta: 3 2
//
// Dicas:
// 1. Na lista dupla, cada inserção ou remoção mexe em até QUATRO setas
//    (prox e ant dos vizinhos) e nos ponteiros inicio e fim. Faça uma
//    tabela: para cada caso (primeiro, último, meio), quais mudam?
// 2. Depois de insere_inicio, o antigo primeiro tem que apontar (ant) para
//    o novo.
// 3. Ao remover o último, o fim tem que mudar. Ao remover o primeiro, o novo
//    primeiro não pode continuar com ant apontando para o nó liberado.
// 4. Resposta esperada: em insere_inicio, if (l->inicio != NULL)
//    l->inicio->ant = novo; em remove_valor, l->fim = p->ant quando p é o
//    último, e p->prox->ant = p->ant sempre que p->prox existe.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ant, *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Dupla;

No *cria_no(int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->ant = novo->prox = NULL;
    return novo;
}

void insere_inicio(Dupla *l, int valor) {
    No *novo = cria_no(valor);
    novo->prox = l->inicio;
    if (l->inicio == NULL) {
        l->fim = novo;
    }
    l->inicio = novo;
}

void insere_fim(Dupla *l, int valor) {
    No *novo = cria_no(valor);
    novo->ant = l->fim;
    if (l->fim != NULL) {
        l->fim->prox = novo;
    } else {
        l->inicio = novo;
    }
    l->fim = novo;
}

void remove_valor(Dupla *l, int valor) {
    No *p = l->inicio;
    while (p != NULL && p->valor != valor) {
        p = p->prox;
    }
    if (p == NULL) {
        return;
    }
    if (p->ant != NULL) {
        p->ant->prox = p->prox;
    } else {
        l->inicio = p->prox;
    }
    if (p->prox != NULL && p->ant != NULL) {
        p->prox->ant = p->ant;
    }
    free(p);
}

void mostra(const Dupla *l) {
    printf("Ida:  ");
    for (const No *p = l->inicio; p != NULL; p = p->prox) {
        printf(" %d", p->valor);
    }
    printf("\nVolta:");
    for (const No *p = l->fim; p != NULL; p = p->ant) {
        printf(" %d", p->valor);
    }
    printf("\n");
}

void libera(Dupla *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    l->inicio = l->fim = NULL;
}

int main(void) {
    Dupla l = {NULL, NULL};
    insere_inicio(&l, 3);
    insere_inicio(&l, 2);
    insere_inicio(&l, 1);
    insere_fim(&l, 4);
    mostra(&l);
    remove_valor(&l, 4);
    remove_valor(&l, 1);
    printf("Depois de remover 4 e 1:\n");
    mostra(&l);
    libera(&l);
    return 0;
}
