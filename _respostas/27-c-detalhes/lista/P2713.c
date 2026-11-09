// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2713 · ★★☆ · Quem ganhou o jogo da velha

#include <stdio.h>

char trinca(char a, char b, char c) {
    return (a != '.' && a == b && b == c) ? a : 0;
}

char vencedor(char t[3][3]) {
    char v;
    for (int i = 0; i < 3; i++) {
        if ((v = trinca(t[i][0], t[i][1], t[i][2])) != 0) return v; // linha
        if ((v = trinca(t[0][i], t[1][i], t[2][i])) != 0) return v; // coluna
    }
    if ((v = trinca(t[0][0], t[1][1], t[2][2])) != 0) return v;
    if ((v = trinca(t[0][2], t[1][1], t[2][0])) != 0) return v;
    return '-';
}

int main(void) {
    char t1[3][3] = {{'X', 'O', '.'}, {'O', 'X', '.'}, {'.', 'O', 'X'}};
    char t2[3][3] = {{'X', 'O', 'X'}, {'X', 'O', 'O'}, {'O', 'X', 'X'}};
    printf("tabuleiro 1: vencedor %c\n", vencedor(t1));
    printf("tabuleiro 2: vencedor %c\n", vencedor(t2));
    return 0;
}
