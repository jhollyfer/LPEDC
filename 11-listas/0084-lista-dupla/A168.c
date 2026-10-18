// A168 · O controle remoto: canal seguinte e canal anterior

#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista canais;
    lista_inicia(&canais);
    int numeros[] = {2, 4, 5, 7, 11, 13};
    for (int i = 0; i < 6; i++) lista_insere_fim(&canais, numeros[i]);

    No *atual = canais.inicio;           // a TV liga no primeiro canal
    const char *apertos = ">>><<>>>>>";  // > próximo, < anterior

    printf("liga no %d\n", atual->valor);
    for (int i = 0; apertos[i] != '\0'; i++) {
        if (apertos[i] == '>' && atual->prox != NULL) {
            atual = atual->prox;         // anda para frente (no 13, fica)
        } else if (apertos[i] == '<' && atual->ant != NULL) {
            atual = atual->ant;          // anda para trás: só na lista dupla
        }
        printf("%c canal %d\n", apertos[i], atual->valor);
    }

    lista_libera(&canais);
    return 0;
}
// Saída:
// liga no 2
// > canal 4
// > canal 5
// > canal 7
// < canal 5
// < canal 4
// > canal 5
// > canal 7
// > canal 11
// > canal 13
// > canal 13
