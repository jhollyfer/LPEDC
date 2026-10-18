// 0020 · While
// Exercício E115 · ★☆☆

#include <stdio.h>

int main(void) {
    int tempo = 5;

    while (tempo > 0) {
        printf("%d...\n", tempo);
        tempo--;
    }
    printf("Pi! Pi! Pi!\n");
    return 0;
}
