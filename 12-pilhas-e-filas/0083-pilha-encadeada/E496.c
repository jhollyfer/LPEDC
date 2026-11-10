// 0083 · Pilha encadeada
// Exercício E496 · ★★☆
//
// Pilha de pratos do restaurante, cada prato com um número, feita com nós
// alocados. Com os tipos abaixo, escreva bool poe_prato(Prato **topo, int numero)
// e bool tira_prato(Prato **topo, int *numero), que devolve o número e libera o
// nó. No main, ponha os pratos 10, 20 e 30 (nessa ordem) e tire todos mostrando
// cada um.
//
//   Saída esperada:
//   Tirou o prato 30
//   Tirou o prato 20
//   Tirou o prato 10
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct prato {
    int numero;
    struct prato *baixo;
} Prato;

int main(void) {

    return 0;
}
