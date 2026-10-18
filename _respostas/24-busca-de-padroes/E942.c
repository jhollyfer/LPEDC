// 0157 · Força bruta
// Exercício E942 · ★★★

#include <stdio.h>
#include <string.h>

#define LIN 5
#define COL 8

// a palavra aparece a partir de (l, c), andando dl linhas e dc colunas por letra?
int casa(const char grade[LIN][COL + 1], int l, int c, int dl, int dc,
         const char *palavra) {
    int m = (int) strlen(palavra);
    int ul = l + dl * (m - 1);          // onde cairia a última letra
    int uc = c + dc * (m - 1);
    if (ul >= LIN || uc >= COL) {
        return 0;                       // não cabe nessa direção
    }
    for (int j = 0; j < m; j++) {
        if (grade[l + dl * j][c + dc * j] != palavra[j]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    const char grade[LIN][COL + 1] = {
        "SOLXMARZ",
        "AQLUAPEO",
        "BMUSOLXR",
        "RAAIBZXA",
        "ARRCEUPS",
    };
    const char *palavras[] = {"SOL", "MAR", "LUA", "CEU", "RIO"};

    for (int k = 0; k < 5; k++) {
        int achou = 0;
        for (int l = 0; l < LIN; l++) {
            for (int c = 0; c < COL; c++) {
                if (casa(grade, l, c, 0, 1, palavras[k])) {
                    printf("%s: linha %d, coluna %d, horizontal\n", palavras[k], l, c);
                    achou = 1;
                }
                if (casa(grade, l, c, 1, 0, palavras[k])) {
                    printf("%s: linha %d, coluna %d, vertical\n", palavras[k], l, c);
                    achou = 1;
                }
            }
        }
        if (!achou) {
            printf("%s: não está na grade\n", palavras[k]);
        }
    }
    return 0;
}
