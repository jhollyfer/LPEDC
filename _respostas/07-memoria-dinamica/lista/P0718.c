// Lista · Módulo 07 · Memória dinâmica
// Exercício P0718 · ★★☆ · Cópia rasa e cópia profunda

#include <stdio.h>
#include <stdlib.h>

void liberar(int **m, int l) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < l; i++) {
        free(m[i]);
    }
    free(m);
}

int **criar(int l, int c) {
    int **m = malloc(l * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < l; i++) {
        m[i] = malloc(c * sizeof *m[i]);
        if (m[i] == NULL) {
            liberar(m, i);
            return NULL;
        }
    }
    return m;
}

void mostrar(const char *nome, int **m) {
    printf("%-9s manhã %d %d %d | tarde %d %d %d\n", nome,
           m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2]);
}

int main(void) {
    int dados[2][3] = {{3, 4, 2}, {5, 1, 6}};
    int **m = criar(2, 3);
    int **profunda = criar(2, 3);
    int **rasa = malloc(2 * sizeof *rasa);
    if (m == NULL || profunda == NULL || rasa == NULL) {
        liberar(m, 2);
        liberar(profunda, 2);
        free(rasa);
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        rasa[i] = m[i]; // o mesmo endereço: a linha é compartilhada
        for (int j = 0; j < 3; j++) {
            m[i][j] = dados[i][j];
            profunda[i][j] = dados[i][j];
        }
    }

    m[0][1] = 9;
    mostrar("Original:", m);
    mostrar("Rasa:", rasa);
    mostrar("Profunda:", profunda);
    printf("Linha 0 da rasa é a de m? %s\n", rasa[0] == m[0] ? "sim" : "não");
    printf("Linha 0 da profunda é a de m? %s\n", profunda[0] == m[0] ? "sim" : "não");

    free(rasa); // só o vetor: as linhas são de m
    liberar(m, 2);
    liberar(profunda, 2);
    return 0;
}
