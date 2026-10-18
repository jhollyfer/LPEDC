// 0005 · printf
// Exercício E026 · ★☆☆

#include <stdio.h>

int main(void) {
    printf("[%5d][%-5d][%05d][%+d]\n", 42, 42, 42, 42);
    printf("[%.1f][%.3f][%8.2f]\n", 3.14159, 3.14159, 3.14159);
    printf("[%c][%s][%6s][%-6s]\n", 'R', "Rio", "Rio", "Rio");
    printf("[%x][%X][%o]\n", 26, 26, 26);
    return 0;
}
