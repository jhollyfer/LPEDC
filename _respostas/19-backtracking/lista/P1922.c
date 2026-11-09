// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1922 · ★★★ · Palavras cruzadas 3 × 3

#include <stdio.h>
#include <string.h>

#define NP 12

const char *lista[NP] = {"ALA", "AMO", "ARO", "ASA", "MAL", "MAR",
                         "MAU", "OCA", "OLA", "RUA", "PAU", "SAL"};
int lin[3];
long testes = 0;

int eh_prefixo(const char *p, int tam) {
    for (int i = 0; i < NP; i++) {
        if (strncmp(lista[i], p, (size_t)tam) == 0) {
            return 1;
        }
    }
    return 0;
}

int colunas_ok(int k) {
    for (int c = 0; c < 3; c++) {
        char col[4];
        for (int l = 0; l <= k; l++) {
            col[l] = lista[lin[l]][c];
        }
        col[k + 1] = '\0';
        if (!eh_prefixo(col, k + 1)) {
            return 0;
        }
    }
    return 1;
}

int todas_diferentes(void) {
    char p[6][4];
    for (int l = 0; l < 3; l++) {
        strcpy(p[l], lista[lin[l]]);
    }
    for (int c = 0; c < 3; c++) {
        for (int l = 0; l < 3; l++) {
            p[3 + c][l] = lista[lin[l]][c];
        }
        p[3 + c][3] = '\0';
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (strcmp(p[i], p[j]) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void preenche(int k) {
    if (k == 3) {
        if (todas_diferentes()) {
            printf("%s / %s / %s\n", lista[lin[0]], lista[lin[1]], lista[lin[2]]);
        }
        return;
    }
    for (int i = 0; i < NP; i++) {
        testes++;
        lin[k] = i;
        if (colunas_ok(k)) {
            preenche(k + 1);
        }
    }
}

int main(void) {
    preenche(0);
    printf("Palavras testadas: %ld\n", testes);
    return 0;
}
