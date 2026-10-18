// A241 · Placas de carro, letra por letra

#include <stdio.h>
#include <string.h>

#define TAM 7 // placa no padrão Mercosul: ABC1D23

// counting sort estável dos ponteiros pela letra da posição pos
void passada(const char *v[], const char *aux[], int n, int pos) {
    int c[256] = {0};
    for (int i = 0; i < n; i++) {
        c[(unsigned char) v[i][pos]]++;
    }
    for (int x = 1; x < 256; x++) {
        c[x] += c[x - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        unsigned char x = (unsigned char) v[i][pos];
        aux[--c[x]] = v[i];
    }
    memcpy(v, aux, n * sizeof(const char *)); // copia os ponteiros de volta
}

int main(void) {
    const char *placas[] = {"RIO2A18", "BRA0S17", "RIO1B99", "SPX3C40", "BRA0S09", "MGA7E21"};
    const char *aux[6];
    int n = 6;

    for (int pos = TAM - 1; pos >= 0; pos--) { // da última letra para a primeira
        passada(placas, aux, n, pos);
        printf("posição %d:", pos);
        for (int i = 0; i < n; i++) {
            printf(" %s", placas[i]);
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// posição 6: SPX3C40 MGA7E21 BRA0S17 RIO2A18 RIO1B99 BRA0S09
// posição 5: BRA0S09 BRA0S17 RIO2A18 MGA7E21 SPX3C40 RIO1B99
// posição 4: RIO2A18 RIO1B99 SPX3C40 MGA7E21 BRA0S09 BRA0S17
// posição 3: BRA0S09 BRA0S17 RIO1B99 RIO2A18 SPX3C40 MGA7E21
// posição 2: BRA0S09 BRA0S17 MGA7E21 RIO1B99 RIO2A18 SPX3C40
// posição 1: MGA7E21 RIO1B99 RIO2A18 SPX3C40 BRA0S09 BRA0S17
// posição 0: BRA0S09 BRA0S17 MGA7E21 RIO1B99 RIO2A18 SPX3C40
//
// Sete passadas, uma por posição, sempre da direita para a esquerda. Repare
// em BRA0S09 e BRA0S17: só diferem na posição 5, e quem decidiu a ordem dos
// dois foi a passada da posição 5. As passadas seguintes os viram empatados
// e, por estabilidade, não mexeram. Para strings de tamanhos diferentes, o
// radix LSD não serve direto: seria preciso completar as curtas.
