// 0024 · Laços aninhados
// Exercício E140 · ★☆☆
//
// Resposta: três linhas, "1", "2 4" e "3 6 9". O printf de dentro roda
// 1 + 2 + 3 = 6 vezes.

#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    return 0;
}
