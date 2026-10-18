// 0083 · Pilha encadeada
// Exercício E496 · ★★☆
//
// O erro era heap-use-after-free: "*numero = velho->numero" vinha depois
// do free(velho). Conserto: ler o valor antes do free.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct prato {
    int numero;
    struct prato *baixo;
} Prato;

bool poe_prato(Prato **topo, int numero) {
    Prato *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->numero = numero;
    novo->baixo = *topo;
    *topo = novo;
    return true;
}

bool tira_prato(Prato **topo, int *numero) {
    if (*topo == NULL) {
        return false;
    }
    Prato *velho = *topo;
    *topo = velho->baixo;
    *numero = velho->numero; // lê enquanto o nó ainda é seu
    free(velho);
    return true;
}

int main(void) {
    Prato *topo = NULL;
    for (int n = 10; n <= 30; n += 10) {
        poe_prato(&topo, n);
    }
    int numero;
    while (tira_prato(&topo, &numero)) {
        printf("Tirou o prato %d\n", numero);
    }
    return 0;
}
