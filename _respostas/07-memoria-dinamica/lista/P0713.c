// Lista · Módulo 07 · Memória dinâmica
// Exercício P0713 · ★★☆ · Ler uma linha de qualquer tamanho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ler_linha(void) {
    size_t cap = 8;
    size_t n = 0;
    char *s = malloc(cap);
    if (s == NULL) {
        return NULL;
    }
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (n + 1 == cap) { // falta lugar para c e o '\0'
            char *novo = realloc(s, cap * 2);
            if (novo == NULL) {
                free(s);
                return NULL;
            }
            s = novo;
            cap *= 2;
            printf("(cresceu para %zu)\n", cap);
        }
        s[n++] = (char) c;
    }
    if (n == 0 && c == EOF) {
        free(s); // não havia linha nenhuma
        return NULL;
    }
    s[n] = '\0';
    return s;
}

int main(void) {
    char *linha = ler_linha();
    if (linha == NULL) {
        printf("Nada para ler\n");
        return 0;
    }
    printf("Lido: \"%s\" (%zu caracteres)\n", linha, strlen(linha));
    free(linha);
    return 0;
}
