// Lista · Módulo 11 · Listas
// Exercício P1112 · ★★☆ · O leitor de código de barras que repete
//
// O leitor do caixa às vezes registra o mesmo produto duas vezes. A lista
// de códigos lidos NÃO está em ordem: 7, 3, 7, 9, 3, 3, 1, 9. Escreva
//
//   int remove_repetidos(No *inicio)
//
// que deixa só a PRIMEIRA ocorrência de cada código, na ordem original, e
// devolve quantos nós tirou (liberando cada um). Não use vetor auxiliar.
//
//   Saída esperada:
//   antes:  7 -> 3 -> 7 -> 9 -> 3 -> 3 -> 1 -> 9 -> NULL
//   depois: 7 -> 3 -> 9 -> 1 -> NULL
//   4 leituras repetidas removidas
//
// Dicas:
// 1. Para cada nó atual, percorra o RESTO da lista com um ponteiro q que
//    olha sempre q->prox: se q->prox tem o mesmo valor do atual, desligue-o
//    (q->prox = q->prox->prox) e libere; senão, avance q.
// 2. Depois de remover, NÃO avance q: o novo q->prox ainda não foi olhado.
// 3. O primeiro nó nunca sai (ele é sempre a primeira ocorrência), por isso
//    a função não precisa devolver um novo início.
// 4. Custo: O(n²) comparações. Com a lista ordenada daria para fazer em
//    O(n), porque os repetidos ficariam lado a lado.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

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
    int lidos[8] = {7, 3, 7, 9, 3, 3, 1, 9};
    No *caixa = de_vetor(lidos, 8);
    printf("antes:  ");
    imprime(caixa);

    // escreva remove_repetidos acima do main e use-a aqui

    libera(caixa);
    return 0;
}
