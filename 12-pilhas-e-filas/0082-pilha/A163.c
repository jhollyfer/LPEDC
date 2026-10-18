// A163 · As bordas da pilha: cheia e vazia

#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *cadeiras = pilha_cria(); // o depósito do salão empilha até 100
    if (cadeiras == NULL) {
        return 1;
    }

    // chegam 103 cadeiras numeradas: as 3 últimas não cabem (overflow)
    int recusadas = 0;
    for (int c = 1; c <= 103; c++) {
        if (!pilha_empilha(cadeiras, c)) {
            recusadas++;
        }
    }
    int topo = 0;
    pilha_topo(cadeiras, &topo);
    printf("Empilhadas: %d, recusadas: %d, no topo: %d\n", pilha_tamanho(cadeiras), recusadas, topo);

    // a festa usa todas: esvazia a pilha
    int cadeira = 0;
    int retiradas = 0;
    while (pilha_desempilha(cadeiras, &cadeira)) {
        retiradas++;
    }
    printf("Retiradas: %d, a última foi a %d\n", retiradas, cadeira);

    // mais uma retirada com a pilha vazia (underflow): devolve false e
    // não mexe na variável. O -1 serve de marcador para provar isso.
    cadeira = -1;
    if (!pilha_desempilha(cadeiras, &cadeira)) {
        printf("Pilha vazia: nada saiu, cadeira continua %d\n", cadeira);
    }
    if (!pilha_topo(cadeiras, &topo)) {
        printf("Topo também falha: vazia? %d\n", pilha_vazia(cadeiras));
    }

    pilha_libera(cadeiras);
    return 0;
}
// Saída:
// Empilhadas: 100, recusadas: 3, no topo: 100
// Retiradas: 100, a última foi a 1
// Pilha vazia: nada saiu, cadeira continua -1
// Topo também falha: vazia? 1
