// Lista · Módulo 11 · Listas
// Exercício P1127 · ★★★ · Dividir a ciranda em duas rodas
//
// A ciranda da escola é uma lista circular guardada pelo ÚLTIMO nó. Ela
// ficou grande demais e precisa virar duas rodas: a primeira com a metade
// da frente (com n ímpar, ela fica com um a mais) e a segunda com o resto,
// cada uma circular de novo. Escreva
//
//   void divide(No *ultimo, No **ultimo1, No **ultimo2)
//
// que faz isso numa passada, só religando nós, com a técnica do lento e do
// rápido (o rápido anda dois passos por vez). Teste com as rodas 1..7 e
// 1..6, mostrando cada metade e confirmando que o último de cada uma aponta
// para o primeiro dela.
//
//   Saída esperada:
//   roda de 7: 1 2 3 4 5 6 7
//     metade 1: 1 2 3 4 (o 4 aponta para o 1)
//     metade 2: 5 6 7 (o 7 aponta para o 5)
//   roda de 6: 1 2 3 4 5 6
//     metade 1: 1 2 3 (o 3 aponta para o 1)
//     metade 2: 4 5 6 (o 6 aponta para o 4)
//
// Dicas:
// 1. Comece lento e rápido no primeiro (ultimo->prox). Avance enquanto
//    rapido->prox e rapido->prox->prox não forem o primeiro.
// 2. Com n par, o rápido para no penúltimo: dê mais um passo com ele. Agora
//    lento é o último da metade 1 e rápido é o último da metade 2.
// 3. Religue: rapido->prox = lento->prox (fecha a metade 2) e
//    lento->prox = primeiro (fecha a metade 1).
// 4. Resposta esperada: a saída acima. Com n = 1, a metade 2 fica vazia
//    (NULL); trate esse caso também.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No *insere_fim(No *ultimo, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    if (ultimo == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    return novo;
}

void libera(No *ultimo) {
    if (ultimo == NULL) {
        return;
    }
    No *p = ultimo->prox;
    ultimo->prox = NULL;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}

int main(void) {

    return 0;
}
