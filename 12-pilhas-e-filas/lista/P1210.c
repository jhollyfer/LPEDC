// Lista · Módulo 12 · Pilhas e filas
// Exercício P1210 · ★☆☆ · Copiar a pilha sem virar de cabeça para baixo
//
// O caixa quer uma CÓPIA da pilha de comandas para conferir, sem mexer na
// original. Copiar desempilhando de uma e empilhando na outra inverte a
// ordem. Com uma pilha AUXILIAR dá certo. Usando só as operações da pilha
// encadeada abaixo (empilha, desempilha, vazia), escreva
//
//   No *copia(No **original)
//
// que devolve uma pilha nova com os mesmos itens na mesma ordem e deixa a
// original exatamente como estava. Depois, desempilhe a cópia toda e mostre
// que a original continua inteira.
//
//   Saída esperada:
//   original (topo primeiro): 30 20 10
//   cópia (topo primeiro):    30 20 10
//   desempilhando a cópia: 30 20 10
//   original depois:          30 20 10
//
// Dicas:
// 1. Passe tudo da original para a auxiliar (fica invertido). Depois, para
//    cada item que sai da auxiliar, empilhe-o na original E na cópia.
// 2. A função recebe No ** porque desempilha e empilha mudam o topo da
//    original.
// 3. Resposta esperada: a saída acima. Cada item é movido 3 vezes: O(n).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void empilha(No **topo, int x) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = *topo;
    *topo = novo;
}

bool desempilha(No **topo, int *x) {
    if (*topo == NULL) {
        return false;
    }
    No *velho = *topo;
    *x = velho->valor;
    *topo = velho->prox;
    free(velho);
    return true;
}

bool vazia(const No *topo) {
    return topo == NULL;
}

void mostra(const char *rotulo, const No *topo) {
    printf("%s", rotulo);
    for (const No *p = topo; p != NULL; p = p->prox) {
        printf(" %d", p->valor);
    }
    printf("\n");
}

int main(void) {
    No *original = NULL;
    empilha(&original, 10);
    empilha(&original, 20);
    empilha(&original, 30);
    mostra("original (topo primeiro):", original);

    // escreva copia acima do main e use-a aqui

    int x;
    while (desempilha(&original, &x)) {
    }
    return 0;
}
