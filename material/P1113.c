// Lista · Módulo 11 · Listas
// Exercício P1113 · ★★☆ · Desengatar o k-ésimo vagão a partir do fim
//
// O trem é uma lista simples e você não sabe o tamanho dele. Escreva
//
//   No *remove_k_do_fim(No *inicio, int k, bool *ok)
//
// que tira o k-ésimo nó contando do FIM (k = 1 é o último), percorrendo a
// lista UMA vez só, e devolve o novo início (*ok diz se o nó existia).
// Monte o trem 10, 20, 30, 40, 50 e remova, nesta ordem, com k = 2, k = 4 e
// k = 5, mostrando o trem depois de cada tentativa.
//
//   Saída esperada:
//   trem:  10 -> 20 -> 30 -> 40 -> 50 -> NULL
//   k = 2: 10 -> 20 -> 30 -> 50 -> NULL
//   k = 4: 20 -> 30 -> 50 -> NULL
//   k = 5: não existe
//
// Dicas:
// 1. Dois ponteiros com distância k entre eles: primeiro avance "rapido" k
//    nós. Se a lista acabar antes, o k-ésimo do fim não existe.
// 2. Depois ande "lento" (com o anterior dele, "ant") e "rapido" juntos até
//    rapido == NULL. Nesse momento, lento é o k-ésimo do fim.
// 3. Se ant == NULL, o removido é o primeiro (foi o que aconteceu com k = 4
//    na lista de 4 vagões).
// 4. Resposta esperada: a saída acima. Uma passada, O(n), memória O(1).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
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

int main(void) {

    return 0;
}
