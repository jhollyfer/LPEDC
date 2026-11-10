// Lista · Módulo 11 · Listas
// Exercício P1118 · ★★☆ · Desengatar o último vagão sem quebrar o trem
//
// Numa lista simples, tirar o ÚLTIMO nó exige achar o PENÚLTIMO. A função
// remove_ultimo abaixo tem DOIS erros de propósito: com 3 vagões o
// sanitizer já acusa "heap-use-after-free" na impressão, e com 1 vagão só
// ela derruba o programa. Conserte os dois para a saída ficar:
//
//   Saída esperada:
//   Trem: 1 -> 2 -> 3 -> NULL
//   Saiu 3: 1 -> 2 -> NULL
//   Saiu 2: 1 -> NULL
//   Saiu 1: NULL
//
// Dicas:
// 1. Depois do free(p->prox), para onde aponta o p->prox do penúltimo? E
//    quem imprime a lista vai seguir essa seta...
// 2. Com um nó só, p->prox->prox lê o prox de NULL. Esse caso precisa ser
//    tratado antes do laço, e nele o início muda (vira NULL).
// 3. Resposta esperada: trate inicio->prox == NULL à parte (guarde o valor,
//    libere o nó e devolva NULL) e, depois do free, faça p->prox = NULL.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

// monta uma lista com os n valores do vetor, na mesma ordem
No *de_vetor(const int v[], int n) {
    No *inicio = NULL;
    for (int i = n - 1; i >= 0; i--) {
        No *novo = malloc(sizeof *novo);
        if (novo == NULL) {
            fprintf(stderr, "sem memória\n");
            exit(1);
        }
        novo->valor = v[i];
        novo->prox = inicio;
        inicio = novo;
    }
    return inicio;
}

void imprime(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

void libera(No *inicio) {
    while (inicio != NULL) {
        No *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

// tira o último nó, guarda o valor dele e devolve o início
No *remove_ultimo(No *inicio, int *valor) {
    if (inicio == NULL) {
        return NULL;
    }
    No *p = inicio;
    while (p->prox->prox != NULL) { // para no penúltimo
        p = p->prox;
    }
    *valor = p->prox->valor;
    free(p->prox);
    return inicio;
}

int main(void) {
    int vagoes[3] = {1, 2, 3};
    No *trem = de_vetor(vagoes, 3);
    printf("Trem: ");
    imprime(trem);
    while (trem != NULL) {
        int v;
        trem = remove_ultimo(trem, &v);
        printf("Saiu %d: ", v);
        imprime(trem);
    }
    return 0;
}
