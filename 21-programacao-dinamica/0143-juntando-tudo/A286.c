// A286 · O diff que percebe uma linha só alterada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linhas.h"

#define MAXL 100 // linhas por arquivo, neste exemplo
#define TAM 256

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

// distância de edição (assunto 0142) com duas linhas de tabela
int distancia(const char *a, const char *b) {
    int m = strlen(a), n = strlen(b);
    int ant[TAM + 1], at[TAM + 1];
    for (int j = 0; j <= n; j++) {
        ant[j] = j;
    }
    for (int i = 1; i <= m; i++) {
        at[0] = i;
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                at[j] = ant[j - 1];
            } else {
                at[j] = 1 + menor3(ant[j - 1], ant[j], at[j - 1]);
            }
        }
        memcpy(ant, at, (n + 1) * sizeof ant[0]);
    }
    return ant[n];
}

// "parecidas": a distância é no máximo um terço da linha mais comprida
int parecidas(const char *a, const char *b) {
    int maior = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    return 3 * distancia(a, b) <= maior;
}

int main(void) {
    const char *v1[] = {"segunda: feijoada", "terça: frango assado", "quarta: lasanha",
                        "quinta: peixe frito", "sexta: pizza"};
    const char *v2[] = {"segunda: feijoada", "terça: frango grelhado", "quarta: lasanha",
                        "quinta: strogonoff", "sexta: pizza", "sábado: churrasco"};
    grava_linhas("/tmp/cardapio-v1.txt", v1, 5);
    grava_linhas("/tmp/cardapio-v2.txt", v2, 6);

    int m = 0, n = 0;
    char **a = le_linhas("/tmp/cardapio-v1.txt", &m);
    char **b = le_linhas("/tmp/cardapio-v2.txt", &n);
    if (a == NULL || b == NULL || m > MAXL || n > MAXL) {
        libera_linhas(a, m);
        libera_linhas(b, n);
        return 1;
    }

    static int c[MAXL + 1][MAXL + 1]; // LCS dos sufixos, como no texto
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i][j] = 0;
            } else if (strcmp(a[i], b[j]) == 0) {
                c[i][j] = c[i + 1][j + 1] + 1;
            } else {
                c[i][j] = c[i + 1][j] >= c[i][j + 1] ? c[i + 1][j] : c[i][j + 1];
            }
        }
    }

    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(a[i], b[j]) == 0) {
            printf("  %s\n", a[i]);
            i++;
            j++;
        } else if (i < m && j < n && c[i + 1][j + 1] == c[i][j] && parecidas(a[i], b[j])) {
            // pular as duas não perde nada da LCS, e elas são parecidas:
            // em vez de "- a[i]" e "+ b[j]", é uma linha alterada
            printf("~ %s  ->  %s\n", a[i], b[j]);
            i++;
            j++;
        } else if (j == n || (i < m && c[i + 1][j] >= c[i][j + 1])) {
            printf("- %s\n", a[i++]);
        } else {
            printf("+ %s\n", b[j++]);
        }
    }

    libera_linhas(a, m);
    libera_linhas(b, n);
    return 0;
}
// Na saída, "peixe frito" e "strogonoff" são diferentes demais: viram - e +.
// Saída:
//   segunda: feijoada
// ~ terça: frango assado  ->  terça: frango grelhado
//   quarta: lasanha
// - quinta: peixe frito
// + quinta: strogonoff
//   sexta: pizza
// + sábado: churrasco
