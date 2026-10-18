// A165 · Desfazer e refazer com duas pilhas

#include <stdio.h>
#include "pilha.h"

// esvazia uma pilha: uma edição nova apaga o que dava para refazer
void esvazia(Pilha *p) {
    int lixo;
    while (pilha_desempilha(p, &lixo)) {
    }
}

int main(void) {
    Pilha *desfazer = pilha_cria();
    if (desfazer == NULL) {
        return 1;
    }
    Pilha *refazer = pilha_cria();
    if (refazer == NULL) {
        pilha_libera(desfazer);
        return 1;
    }

    int temp = 22; // ar-condicionado da sala, em graus
    int ajustes[] = {20, 18, 24};
    for (int i = 0; i < 3; i++) {
        pilha_empilha(desfazer, temp); // guarda o valor antigo
        esvazia(refazer);
        temp = ajustes[i];
    }
    printf("Ajustado para %d\n", temp); // desfazer: topo -> 18 -> 20 -> 22

    for (int i = 0; i < 2; i++) { // Ctrl+Z duas vezes
        pilha_empilha(refazer, temp); // o atual vai para o refazer
        pilha_desempilha(desfazer, &temp);
        printf("Desfez: %d\n", temp);
    }

    pilha_empilha(desfazer, temp); // Ctrl+Y: o caminho inverso
    pilha_desempilha(refazer, &temp);
    printf("Refez: %d\n", temp);
    printf("Dá para refazer mais %d vez(es)\n", pilha_tamanho(refazer));

    pilha_empilha(desfazer, temp); // edição nova: o refazer perde o sentido
    esvazia(refazer);
    temp = 21;
    printf("Ajustado para %d; refazer agora tem %d\n", temp, pilha_tamanho(refazer));
    printf("Desfazer guarda %d valores\n", pilha_tamanho(desfazer));

    pilha_libera(desfazer);
    pilha_libera(refazer);
    return 0;
}
// Saída:
// Ajustado para 24
// Desfez: 18
// Desfez: 20
// Refez: 18
// Dá para refazer mais 1 vez(es)
// Ajustado para 21; refazer agora tem 0
// Desfazer guarda 3 valores
