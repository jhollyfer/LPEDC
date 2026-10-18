// 0124 · Juntando tudo
// Exercício E739 · ★☆☆

#include <stdio.h>
#include "pix.h"

int main(void) {
    Pix v[8], aux[8];
    pix_gera(v, 8, 5);

    if (!pix_por_horario(v, aux, 8)) {
        return 1;
    }
    printf("linha do tempo:\n");
    for (int i = 0; i < 8; i++) {
        pix_mostra(&v[i]);
    }
    pix_por_valor(v, aux, 8);
    printf("menor: ");
    pix_mostra(&v[0]);
    printf("maior: ");
    pix_mostra(&v[7]);
    return 0;
}
