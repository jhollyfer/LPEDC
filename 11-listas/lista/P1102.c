// Lista · Módulo 11 · Listas
// Exercício P1102 · ★☆☆ · O itinerário do ônibus, parada por parada
//
// O itinerário da linha 640 é montado na ordem em que as paradas são
// cadastradas: 101, 205, 310, 412 e 520. Sem ponteiro para o último, cada
// inserção no FIM precisa andar a lista até o último nó. Escreva
//
//   No *insere_fim(No *inicio, int valor, int *visitados)
//
// que devolve o (possivelmente novo) início e soma em *visitados quantos nós
// percorreu para achar o último. Monte o itinerário, mostre-o, mostre o
// total de nós visitados e libere tudo.
//
//   Saída esperada:
//   101 -> 205 -> 310 -> 412 -> 520 -> NULL
//   Nós visitados: 10
//
// Dicas:
// 1. Lista vazia é caso especial: o novo nó vira o início.
// 2. Senão: p = inicio; while (p->prox != NULL) p = p->prox; e conte cada
//    nó por onde p passou (o próprio último incluído).
// 3. A k-ésima inserção visita k - 1 nós: 0 + 1 + 2 + 3 + 4 = 10. Para n
//    paradas, n (n - 1) / 2: montar a lista assim é O(n²). Um ponteiro para
//    o último deixa cada inserção O(1).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

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
