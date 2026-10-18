// 0129 · Labirinto
// Exercício E769 · ★☆☆

#include <stdio.h>

#define L 6
#define C 10

char mapa[L][C + 1] = {
    "##########",
    "#....#...#",
    "#....#...#",
    "#..###...#",
    "#..#.....#",
    "##########",
};

int pasto(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C || mapa[l][c] != '.') {
        return 0;
    }
    mapa[l][c] = 'v';
    return 1 + pasto(l, c + 1) + pasto(l + 1, c) + pasto(l, c - 1) + pasto(l - 1, c);
}

int main(void) {
    int area = pasto(2, 3);
    for (int l = 0; l < L; l++) {
        printf("%s\n", mapa[l]);
    }
    printf("a vaca alcança %d casas\n", area);
    return 0;
}
