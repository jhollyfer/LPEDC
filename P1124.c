// Lista · Módulo 11 · Listas
// Exercício P1124 · ★★★ · Inverter só um trecho da fila
//
// Na fila do embarque, as pessoas das posições 3 a 6 (contando de 1) são uma
// família que entrou na ordem errada. Escreva
//
//   No *inverte_trecho(No *inicio, int a, int b)
//
// que inverte só os nós das posições a até b (1 <= a <= b <= n), numa
// passada, só religando nós, e devolve o novo início (que muda quando a ==
// 1). Na fila 1..8, aplique, um depois do outro, os trechos (3, 6), (1, 2)
// e (7, 8).
//
//   Saída esperada:
//   fila:   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
//   (3, 6): 1 -> 2 -> 6 -> 5 -> 4 -> 3 -> 7 -> 8 -> NULL
//   (1, 2): 2 -> 1 -> 6 -> 5 -> 4 -> 3 -> 7 -> 8 -> NULL
//   (7, 8): 2 -> 1 -> 6 -> 5 -> 4 -> 3 -> 8 -> 7 -> NULL
//
// Dicas:
// 1. Ande até o nó ANTES do trecho (antes, que é NULL se a == 1). O primeiro
//    do trecho (prim) vai virar o último dele.
// 2. Inverta b - a + 1 nós como na inversão comum (ant, p, seg). No fim, p
//    aponta para o primeiro nó DEPOIS do trecho e ant para o novo primeiro.
// 3. Religue as pontas: prim->prox = p; e antes->prox = ant (ou, se antes
//    é NULL, o novo início é ant).
// 4. Resposta esperada: a saída acima.
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

    return 0;
}
