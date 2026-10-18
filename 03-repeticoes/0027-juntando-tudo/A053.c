// A053 · As 36 jogadas do primeiro lançamento, sem sortear

#include <stdio.h>

int main(void) {
    int natural = 0, craps = 0, ponto = 0;

    // em vez de sortear, passa por TODAS as combinações dos dois dados
    printf("d1\\d2  1  2  3  4  5  6\n");
    for (int d1 = 1; d1 <= 6; d1++) {
        printf("%5d", d1);
        for (int d2 = 1; d2 <= 6; d2++) {
            int soma = d1 + d2;
            printf("%3d", soma);
            switch (soma) {
            case 7:
            case 11:
                natural++;  // ganha de cara
                break;
            case 2:
            case 3:
            case 12:
                craps++;    // perde de cara
                break;
            default:
                ponto++;    // o jogo continua
            }
        }
        printf("\n");
    }

    int total = natural + craps + ponto;
    printf("Ganha de cara (7 ou 11):    %2d de %d (%.1f%%)\n",
           natural, total, 100.0 * natural / total);
    printf("Perde de cara (2, 3 ou 12): %2d de %d (%.1f%%)\n",
           craps, total, 100.0 * craps / total);
    printf("Vira ponto:                 %2d de %d (%.1f%%)\n",
           ponto, total, 100.0 * ponto / total);
    return 0;
}
// Saída:
// d1\d2  1  2  3  4  5  6
//     1  2  3  4  5  6  7
//     2  3  4  5  6  7  8
//     3  4  5  6  7  8  9
//     4  5  6  7  8  9 10
//     5  6  7  8  9 10 11
//     6  7  8  9 10 11 12
// Ganha de cara (7 ou 11):     8 de 36 (22.2%)
// Perde de cara (2, 3 ou 12):  4 de 36 (11.1%)
// Vira ponto:                 24 de 36 (66.7%)
