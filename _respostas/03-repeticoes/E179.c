// 0030 · Padrões de laço
// Exercício E179 · ★★★

#include <stdio.h>

int main(void) {
    int nota;
    int primeiro = -1, segundo = -1;

    for (int i = 1; i <= 8; i++) {
        printf("Nota %d: ", i);
        if (scanf("%d", &nota) != 1) {
            return 1;
        }
        if (nota > primeiro) {
            segundo = primeiro; // o campeão antigo desce um lugar
            primeiro = nota;
        } else if (nota > segundo) {
            segundo = nota;
        }
    }
    printf("1º lugar: %d\n", primeiro);
    printf("2º lugar: %d\n", segundo);
    return 0;
}
