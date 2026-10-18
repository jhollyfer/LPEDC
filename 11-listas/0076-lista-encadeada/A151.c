// A151 · Andando pelas setas: o terceiro nó e a lista vazia

#include <stdio.h>
#include "lista.h"

int main(void) {
    // temperaturas da semana em Cuiabá, lidas de segunda a domingo
    int temps[] = {31, 34, 29, 36, 33, 28, 35};
    No *semana = NULL;
    for (int i = 0; i < 7; i++) {
        semana = lista_insere_inicio(semana, temps[i]);
    }
    lista_imprime(semana); // domingo na frente: a ordem saiu invertida

    // não existe semana[2]: para chegar no 3º nó, siga duas setas
    No *p = semana;
    for (int passo = 0; passo < 2 && p != NULL; passo++) {
        p = p->prox;
    }
    if (p != NULL) printf("3º nó: %d (sexta-feira)\n", p->valor);

    // percorrer também serve para procurar o maior
    int maior = semana->valor;
    for (No *q = semana->prox; q != NULL; q = q->prox) {
        if (q->valor > maior) maior = q->valor;
    }
    printf("maior: %d\n", maior);

    // a lista vazia não é caso especial: o laço só não roda nenhuma vez
    No *vazia = NULL;
    printf("vazia tem %d nós: ", lista_tamanho(vazia));
    lista_imprime(vazia);
    lista_libera(vazia); // não faz nada, e não quebra

    lista_libera(semana);
    return 0;
}
// Saída:
// 35 -> 28 -> 33 -> 36 -> 29 -> 34 -> 31 -> NULL
// 3º nó: 33 (sexta-feira)
// maior: 36
// vazia tem 0 nós: NULL
