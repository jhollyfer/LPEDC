// 0059 · malloc e free
// Exercício E354 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *juntar(const char *a, const char *b) {
    char *novo = malloc(strlen(a) + 1 + strlen(b) + 1);
    if (novo == NULL) {
        return NULL;
    }
    strcpy(novo, a);
    strcat(novo, " ");
    strcat(novo, b);
    return novo;
}

int main(void) {
    char *parte = juntar("Maria", "Clara");
    if (parte == NULL) {
        return 1;
    }
    char *nome = juntar(parte, "Fonseca");
    free(parte); // o intermediário já foi usado: libera
    if (nome == NULL) {
        return 1;
    }
    printf("Crachá: %s (%zu caracteres)\n", nome, strlen(nome));
    free(nome);
    return 0;
}
// Saída:
// Crachá: Maria Clara Fonseca (19 caracteres)
