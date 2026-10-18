// 0062 · Ponteiro para struct
// Exercício E368 · ★☆☆

#include <stdio.h>

typedef struct {
    int gols;
} Placar;

void gol_copia(Placar p) { p.gols++; } // aumenta uma cópia
void gol(Placar *p) { p->gols++; }     // aumenta o original

int main(void) {
    Placar casa = {0};

    gol_copia(casa);
    printf("depois de gol_copia: %d\n", casa.gols);
    gol(&casa);
    printf("depois de gol: %d\n", casa.gols);
    gol(&casa);
    printf("depois de gol: %d\n", casa.gols);
    gol_copia(casa);
    printf("depois de gol_copia: %d\n", casa.gols);

    Placar *ptr = &casa;
    ptr->gols += 10;
    printf("casa.gols = %d, (*ptr).gols = %d\n", casa.gols, (*ptr).gols);
    return 0;
}
