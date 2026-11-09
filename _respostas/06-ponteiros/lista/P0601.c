// Lista · Módulo 06 · Ponteiros
// Exercício P0601 · ★☆☆ · O placar pelo ponteiro

#include <stdio.h>

int main(void) {
    char gols[] = "RPPRRPR";
    int remo = 0, paysandu = 0;

    for (int i = 0; gols[i] != '\0'; i++) {
        int *alvo = (gols[i] == 'R') ? &remo : &paysandu;
        (*alvo)++; // soma no time para onde alvo aponta
        printf("Gol %d (%s): Remo %d x %d Paysandu\n", i + 1,
               gols[i] == 'R' ? "Remo" : "Paysandu", remo, paysandu);
    }
    return 0;
}
