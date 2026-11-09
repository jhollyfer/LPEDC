// Lista · Módulo 06 · Ponteiros
// Exercício P0630 · ★★★ · O caça-palavras com ponteiros

#include <stdio.h>
#include <stdbool.h>

#define L 5
#define C 6

bool achar(char g[L][C + 1], const char *palavra, int *lin, int *col, int *dir,
           const int *dl, const int *dc) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            for (int d = 0; d < 8; d++) {
                int k = 0;
                const char *p = palavra;
                for (; *p != '\0'; p++, k++) {
                    int l = i + k * dl[d];
                    int c = j + k * dc[d];
                    if (l < 0 || l >= L || c < 0 || c >= C || g[l][c] != *p) {
                        break; // saiu da grade ou a letra não bate
                    }
                }
                if (*p == '\0') { // chegou ao fim da palavra: achou
                    *lin = i;
                    *col = j;
                    *dir = d;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void) {
    char g[L][C + 1] = {"IACAZP",
                        "CIMAXE",
                        "OLPAUQ",
                        "JANUEU",
                        "BURITI"};
    const char *palavras[5] = {"BURITI", "ACAI", "PEQUI", "TUPI", "CUPU"};
    int dl[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    const char *nomes[8] = {"->", "<-", "desce", "sobe", "desce ->", "desce <-",
                            "sobe ->", "sobe <-"};

    for (int k = 0; k < 5; k++) {
        int l, c, d;
        if (achar(g, palavras[k], &l, &c, &d, dl, dc)) {
            printf("%-6s linha %d, coluna %d, %s\n", palavras[k], l, c, nomes[d]);
        } else {
            printf("%-6s não está na grade\n", palavras[k]);
        }
    }
    return 0;
}
