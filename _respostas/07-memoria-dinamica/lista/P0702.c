// Lista · Módulo 07 · Memória dinâmica
// Exercício P0702 · ★☆☆ · Juntar nome e sobrenome no heap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *juntar(const char *a, const char *sep, const char *b, size_t *bytes) {
    *bytes = strlen(a) + strlen(sep) + strlen(b) + 1; // + 1 do '\0'
    char *novo = malloc(*bytes);
    if (novo == NULL) {
        return NULL;
    }
    strcpy(novo, a);
    strcat(novo, sep);
    strcat(novo, b);
    return novo;
}

int main(void) {
    size_t b1, b2;
    char *nome = juntar("Francisca", " ", "Pereira", &b1);
    char *local = juntar("Manaus", " - ", "AM", &b2);
    if (nome == NULL || local == NULL) {
        free(nome);
        free(local);
        return 1;
    }
    printf("\"%s\": strlen %zu, malloc de %zu bytes\n", nome, strlen(nome), b1);
    printf("\"%s\": strlen %zu, malloc de %zu bytes\n", local, strlen(local), b2);
    free(nome);
    free(local);
    return 0;
}
