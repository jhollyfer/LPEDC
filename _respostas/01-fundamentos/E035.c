// 0006 · scanf
// Exercício E035 · ★★★

#include <stdio.h>

int main(void) {
    int a = 0, b = 0;
    int lidos = scanf("%d %d", &a, &b);
    printf("lidos=%d a=%d b=%d\n", lidos, a, b);
    return 0;
}
