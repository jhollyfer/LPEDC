// 0179 · Sondagem quadrática e dupla
// Exercício E1069 · ★☆☆

#include <stdio.h>
#include "sondagem.h"

int main(void) {
    const char *nomes[] = {"linear:    ", "quadrática:", "dupla:     "};
    int chaves[] = {44, 57};
    for (int c = 0; c < 2; c++) {
        printf("chave %d\n", chaves[c]);
        for (int modo = 0; modo < 3; modo++) {
            Sondagem *t = sd_cria(13, (ModoSondagem)modo);
            if (t == NULL) {
                return 1;
            }
            printf("  %s", nomes[modo]);
            for (int i = 0; i < 6; i++) {
                printf(" %2d", sd_posicao(t, chaves[c], i));
            }
            printf("\n");
            sd_libera(t);
        }
    }
    return 0;
}
