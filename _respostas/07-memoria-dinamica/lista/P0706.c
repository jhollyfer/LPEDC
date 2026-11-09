// Lista · Módulo 07 · Memória dinâmica
// Exercício P0706 · ★☆☆ · O cartão mascarado

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *mascarar(const char *num) {
    size_t tam = strlen(num);
    int total = 0;
    for (size_t i = 0; i < tam; i++) {
        if (isdigit((unsigned char) num[i])) {
            total++;
        }
    }
    char *m = malloc(tam + 1);
    if (m == NULL) {
        return NULL;
    }
    int k = 0;
    for (size_t i = 0; i < tam; i++) {
        if (isdigit((unsigned char) num[i])) {
            m[i] = (k < total - 4) ? '*' : num[i];
            k++;
        } else {
            m[i] = num[i];
        }
    }
    m[tam] = '\0';
    return m;
}

int main(void) {
    const char *cartoes[3] = {"4539 1488 0343 6467", "5162 3001 9925", "1234"};

    for (int i = 0; i < 3; i++) {
        char *m = mascarar(cartoes[i]);
        if (m == NULL) {
            return 1;
        }
        printf("%-20s -> %s\n", cartoes[i], m);
        free(m);
    }
    return 0;
}
