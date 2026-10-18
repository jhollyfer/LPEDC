// 0059 · malloc e free
// Exercício E350 · ★☆☆

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicar(const char *texto) {
    char *copia = malloc(strlen(texto) + 1); // + 1 para o '\0'
    if (copia == NULL) {
        return NULL;
    }
    strcpy(copia, texto);
    return copia;
}

int main(void) {
    const char *original = "coxinha";
    char *copia = duplicar(original);
    if (copia == NULL) {
        printf("duplicar ainda não foi feita\n");
        return 1;
    }
    for (int i = 0; copia[i] != '\0'; i++) {
        copia[i] = (char)toupper((unsigned char)copia[i]);
    }
    printf("Original: %s\n", original);
    printf("Cópia: %s\n", copia);
    free(copia);
    return 0;
}
// Saída:
// Original: coxinha
// Cópia: COXINHA
