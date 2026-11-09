// Lista · Módulo 11 · Listas
// Exercício P1108 · ★☆☆ · As senhas da farmácia e a memória
//
// O painel da farmácia guarda as senhas numa lista. O programa mostra a
// lista, chama (tira do início) duas senhas e libera o resto. A saída na
// tela parece certa, mas o AddressSanitizer reclama: há DOIS erros de
// propósito com a memória. Rode, leia o relatório (procure
// "heap-use-after-free" e "detected memory leaks") e conserte os dois.
//
//   Saída esperada:
//   Senhas: 41 -> 42 -> 43 -> 44 -> NULL
//   Chamou 41
//   Chamou 42
//   Senhas: 43 -> 44 -> NULL
//
// (e nenhum relatório do sanitizer depois da saída)
//
// Dicas:
// 1. Em libera: depois do free(p), o nó não é mais seu. Dá para ler p->prox?
// 2. Em chama: o nó tirado da lista ainda ocupa memória. Quem devolve?
// 3. Resposta esperada: em libera, guarde No *seguinte = p->prox ANTES do
//    free(p). Em chama, guarde o nó antigo, avance o início e dê free no
//    nó antigo. A saída fica igual à de cima, sem relatório.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No *insere_fim(No *inicio, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (inicio == NULL) {
        return novo;
    }
    No *p = inicio;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return inicio;
}

void imprime(const No *inicio) {
    printf("Senhas: ");
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

// tira a primeira senha e devolve o novo início
No *chama(No *inicio) {
    if (inicio == NULL) {
        return NULL;
    }
    printf("Chamou %d\n", inicio->valor);
    return inicio->prox;
}

void libera(No *inicio) {
    No *p = inicio;
    while (p != NULL) {
        free(p);
        p = p->prox;
    }
}

int main(void) {
    No *painel = NULL;
    for (int s = 41; s <= 44; s++) {
        painel = insere_fim(painel, s);
    }
    imprime(painel);
    painel = chama(painel);
    painel = chama(painel);
    imprime(painel);
    libera(painel);
    return 0;
}
