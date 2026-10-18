// 0008 · Conversão e cast
// Exercício E045 · ★★☆

#include <stdio.h>

int main(void) {
    int votos = 47;
    int total = 130;

    printf("Marta: %.2f%% dos votos\n", 100.0 * votos / total);
    printf("votos / total * 100 = %d\n", votos / total * 100); // 47 / 130 = 0
    printf("100 * votos / total = %d\n", 100 * votos / total); // 4700 / 130 = 36
    return 0;
}
