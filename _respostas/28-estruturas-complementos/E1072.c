// 0179 · Sondagem quadrática e dupla
// Exercício E1072 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include "sondagem.h"

int main(void) {
    Sondagem *t = sd_cria(7, SD_QUADRATICA);
    if (t == NULL) {
        return 1;
    }
    bool visitada[7] = {false};
    printf("sequência da chave 0:");
    for (int i = 0; i < 7; i++) {
        int j = sd_posicao(t, 0, i);
        visitada[j] = true;
        printf(" %d", j);
    }
    printf("\nnunca visitadas:");
    for (int j = 0; j < 7; j++) {
        if (!visitada[j]) {
            printf(" %d", j);
        }
    }
    printf("\n");
    int chaves[] = {0, 7, 14, 21, 28};
    for (int c = 0; c < 5; c++) {
        int pos = sd_insere(t, chaves[c], NULL);
        printf("insere %2d: posição %d\n", chaves[c], pos);
    }
    printf("tabela:");
    sd_mostra(t);
    printf("carga %.2f e a chave 28 ficou de fora\n", sd_carga(t));
    sd_libera(t);
    return 0;
}
