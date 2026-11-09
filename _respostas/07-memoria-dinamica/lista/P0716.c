// Lista · Módulo 07 · Memória dinâmica
// Exercício P0716 · ★★☆ · Recortar a imagem

#include <stdio.h>
#include <stdlib.h>

void liberar(char **m, int alt) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < alt; i++) {
        free(m[i]);
    }
    free(m);
}

char **recortar(const char **img, int l0, int c0, int alt, int larg) {
    char **m = malloc(alt * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < alt; i++) {
        m[i] = malloc(larg + 1);
        if (m[i] == NULL) {
            liberar(m, i);
            return NULL;
        }
        for (int j = 0; j < larg; j++) {
            m[i][j] = img[l0 + i][c0 + j];
        }
        m[i][larg] = '\0';
    }
    return m;
}

void mostrar(const char *titulo, char **m, int alt) {
    printf("%s\n", titulo);
    for (int i = 0; i < alt; i++) {
        printf("  %s\n", m[i]);
    }
}

int main(void) {
    const char *img[6] = {"..........",
                          "..####....",
                          ".#....#...",
                          ".#.##.#...",
                          "..####....",
                          ".........."};

    char **r = recortar(img, 1, 1, 4, 6);
    if (r == NULL) {
        return 1;
    }
    char **miolo = recortar((const char **) r, 1, 1, 2, 4);
    if (miolo == NULL) {
        liberar(r, 4);
        return 1;
    }
    mostrar("Recorte 4x6:", r, 4);
    mostrar("Miolo 2x4:", miolo, 2);
    liberar(miolo, 2);
    liberar(r, 4);
    return 0;
}
