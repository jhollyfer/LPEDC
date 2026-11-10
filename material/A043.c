// A043 · Postes e vãos: o erro por um na cerca

#include <stdio.h>

int main(void) {
    int comprimento = 30; // a cerca tem 30 metros
    int espaco = 5;       // um poste a cada 5 metros
    int postes = 0;
    int vaos = 0;

    // postes: do metro 0 ATÉ o metro 30, inclusive (<=)
    printf("Postes nos metros:");
    for (int metro = 0; metro <= comprimento; metro += espaco) {
        printf(" %d", metro);
        postes++;
    }
    printf("\n");

    // vãos: cada vão começa num poste, menos no último (<)
    for (int metro = 0; metro < comprimento; metro += espaco) {
        vaos++;
    }

    printf("Postes: %d | Vãos: %d\n", postes, vaos);
    printf("Pela conta: %d vãos, %d postes\n",
           comprimento / espaco, comprimento / espaco + 1);
    return 0;
}
// Saída:
// Postes nos metros: 0 5 10 15 20 25 30
// Postes: 7 | Vãos: 6
// Pela conta: 6 vãos, 7 postes
