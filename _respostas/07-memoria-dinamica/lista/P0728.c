// Lista · Módulo 07 · Memória dinâmica
// Exercício P0728 · ★★★ · As palavras mais usadas do discurso

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char **palavras = NULL;
int *cont = NULL;
int n = 0, cap = 0;

bool contar(const char *p) {
    for (int k = 0; k < n; k++) {
        if (strcmp(palavras[k], p) == 0) {
            cont[k]++;
            return true;
        }
    }
    if (n == cap) {
        int nova = (cap == 0) ? 2 : cap * 2;
        char **np = realloc(palavras, nova * sizeof *np);
        if (np == NULL) {
            return false;
        }
        palavras = np; // já é seguro guardar: o bloco antigo foi trocado
        int *nc = realloc(cont, nova * sizeof *nc);
        if (nc == NULL) {
            return false;
        }
        cont = nc;
        cap = nova;
    }
    char *copia = malloc(strlen(p) + 1);
    if (copia == NULL) {
        return false;
    }
    strcpy(copia, p);
    palavras[n] = copia;
    cont[n] = 1;
    n++;
    return true;
}

void liberar_tudo(void) {
    for (int k = 0; k < n; k++) {
        free(palavras[k]);
    }
    free(palavras);
    free(cont);
}

int main(void) {
    const char *discurso = "Hoje a turma celebra. A turma estudou, a turma "
        "errou, a turma aprendeu. Hoje celebramos o estudo e o futuro; "
        "o futuro da turma comeca hoje!";
    char p[32];
    int j = 0;
    bool ok = true;

    for (const char *c = discurso; ok; c++) {
        if (isalpha((unsigned char) *c)) {
            if (j < 31) {
                p[j++] = (char) tolower((unsigned char) *c);
            }
            continue;
        }
        if (j >= 3) {
            p[j] = '\0';
            ok = contar(p);
        }
        j = 0;
        if (*c == '\0') {
            break;
        }
    }
    if (!ok) {
        liberar_tudo();
        return 1;
    }

    bool *escolhida = calloc(n, sizeof *escolhida);
    if (escolhida == NULL) {
        liberar_tudo();
        return 1;
    }
    printf("%d palavras distintas (capacidade %d)\n", n, cap);
    for (int r = 1; r <= 3 && r <= n; r++) {
        int m = -1;
        for (int k = 0; k < n; k++) {
            if (!escolhida[k] && (m < 0 || cont[k] > cont[m])) {
                m = k;
            }
        }
        escolhida[m] = true;
        printf("%dº %s (%d)\n", r, palavras[m], cont[m]);
    }
    free(escolhida);
    liberar_tudo();
    return 0;
}
