// A078 · O tabuleiro do jogo da velha

#include <stdio.h>
#include <stdbool.h>

#define N 3

// no parâmetro, só a 1ª dimensão pode ficar vazia: [][N]
// (sem const: com matriz, o const só é aceito sem aviso a partir do C23)
void desenhar(char t[][N], int linhas) {
    for (int l = 0; l < linhas; l++) {
        printf(" %c | %c | %c\n", t[l][0], t[l][1], t[l][2]);
        if (l < linhas - 1) {
            printf("---+---+---\n");
        }
    }
}

// a diagonal principal é onde linha == coluna
bool ganhou_na_diagonal(char t[][N], char jogador) {
    for (int i = 0; i < N; i++) {
        if (t[i][i] != jogador) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char tabuleiro[N][N] = {
        {'X', 'O', '.'},
        {'O', 'X', '.'},
        {'.', 'O', 'X'},
    };

    desenhar(tabuleiro, N);
    printf("X ganhou na diagonal? %s\n", ganhou_na_diagonal(tabuleiro, 'X') ? "sim" : "não");
    printf("A matriz ocupa %zu bytes; cada linha, %zu\n", sizeof(tabuleiro), sizeof(tabuleiro[0]));
    return 0;
}
// Saída:
//  X | O | .
// ---+---+---
//  O | X | .
// ---+---+---
//  . | O | X
// X ganhou na diagonal? sim
// A matriz ocupa 9 bytes; cada linha, 3
