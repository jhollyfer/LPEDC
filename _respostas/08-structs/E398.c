// 0067 · Ponteiro para struct
// Exercício E398 · ★☆☆
//
// Resposta: mostra 2 e depois "12 12". gol_copia(casa) aumenta uma cópia,
// que some quando a função termina; só as duas chamadas gol(&casa) mudam o
// original. ptr aponta para casa, então ptr->gols += 10 leva casa.gols a 12,
// e (*ptr).gols é o mesmo campo.

#include <stdio.h>

typedef struct {
    int gols;
} Placar;

void gol_copia(Placar p) { p.gols++; }
void gol(Placar *p) { p->gols++; }

int main(void) {
    Placar casa = {0};
    gol_copia(casa);
    gol(&casa);
    gol(&casa);
    gol_copia(casa);
    printf("%d\n", casa.gols);

    Placar *ptr = &casa;
    ptr->gols += 10;
    printf("%d %d\n", casa.gols, (*ptr).gols);
    return 0;
}
