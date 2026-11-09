// Lista · Módulo 07 · Memória dinâmica
// Exercício P0725 · ★★★ · Conserte a lista de convidados

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copia(const char *s) {
    char *c = malloc(strlen(s) + 1); // no heap: sobrevive ao return
    if (c != NULL) {
        strcpy(c, s);
    }
    return c;
}

int main(void) {
    const char *nomes[4] = {"Zefinha", "Tião", "Mariazinha", "Chico Bento"};
    int n = 4;
    char **lista = malloc(n * sizeof *lista); // n ponteiros, não n chars
    if (lista == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        lista[i] = copia(nomes[i]);
        if (lista[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(lista[j]);
            }
            free(lista);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, lista[i]);
    }
    printf("%d convidados\n", n);

    for (int i = 0; i < n; i++) {
        free(lista[i]); // primeiro os nomes...
    }
    free(lista);        // ...depois o vetor
    return 0;
}
