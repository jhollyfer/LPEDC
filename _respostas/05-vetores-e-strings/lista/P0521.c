// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0521 · ★★★ · Quem ganhou o jogo da velha

#include <stdio.h>
#include <stdbool.h>

// recebe as linhas com 4 posições (3 letras + '\0'), como estão no main
char vencedor(char t[3][4]) {
    for (int i = 0; i < 3; i++) {
        if (t[i][0] != '.' && t[i][0] == t[i][1] && t[i][1] == t[i][2]) {
            return t[i][0]; // linha i
        }
        if (t[0][i] != '.' && t[0][i] == t[1][i] && t[1][i] == t[2][i]) {
            return t[0][i]; // coluna i
        }
    }
    if (t[1][1] != '.' && t[0][0] == t[1][1] && t[1][1] == t[2][2]) {
        return t[1][1]; // diagonal principal
    }
    if (t[1][1] != '.' && t[0][2] == t[1][1] && t[1][1] == t[2][0]) {
        return t[1][1]; // diagonal secundária
    }
    return '.';
}

bool cheio(char t[3][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (t[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

void julgar(char t[3][4]) {
    for (int i = 0; i < 3; i++) {
        printf("%c %c %c\n", t[i][0], t[i][1], t[i][2]);
    }
    char v = vencedor(t);
    if (v != '.') {
        printf("Vitória do %c\n", v);
    } else if (cheio(t)) {
        printf("Deu velha\n");
    } else {
        printf("Em andamento\n");
    }
}

int main(void) {
    char jogos[4][3][4] = {
        {"XOX", "OXO", "OOX"},
        {"OXX", "XOO", "XOX"},
        {"XX.", "OO.", "..."},
        {"XXO", "XOX", "OXX"},
    };

    for (int k = 0; k < 4; k++) {
        printf("Jogo %d:\n", k + 1);
        julgar(jogos[k]);
    }
    return 0;
}
