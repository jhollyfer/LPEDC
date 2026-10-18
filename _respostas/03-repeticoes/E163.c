// 0028 · Break e continue
// Exercício E163 · ★☆☆

#include <stdio.h>

int main(void) {
    for (int andar = 1; andar <= 20; andar++) {
        if (andar == 13) {
            continue;
        }
        printf("%d ", andar);
    }
    printf("\n");
    return 0;
}
