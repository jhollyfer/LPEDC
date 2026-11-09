// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2017 · ★★☆ · Os postos da BR-319

#include <stdio.h>

#define NP 11
#define TANQUE 250

int main(void) {
    const int posto[NP] = {90, 180, 240, 330, 420, 470, 560, 650, 700, 790, 880};
    int ultima = 0, i = -1, paradas = 0;
    while (880 - ultima > TANQUE) {
        int j = i;
        while (j + 1 < NP && posto[j + 1] - ultima <= TANQUE) {
            j++;
        }
        if (j == i) {
            printf("Impossível: trecho maior que %d km depois do km %d\n", TANQUE, ultima);
            return 0;
        }
        i = j;
        ultima = posto[i];
        paradas++;
        printf("Parada %d: km %d\n", paradas, ultima);
    }
    printf("Chegou a Porto Velho com %d paradas\n", paradas);
    return 0;
}
