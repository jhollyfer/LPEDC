// 0048 · Ponteiros e strings
// Exercício E285 · ★★☆

#include <stdio.h>
#include <string.h>

void copia(char *destino, const char *origem) {
    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0';
}

// copia, devolve o caractere copiado e só depois avança os dois
void copia_classica(char *destino, const char *origem) {
    while ((*destino++ = *origem++) != '\0') {
    }
}

int main(void) {
    char destino[20];

    copia(destino, "Porto Alegre");
    printf("copia:          %s (%zu letras)\n", destino, strlen(destino));

    strcpy(destino, "XXXXXXXXXXXXXXXXXXX"); // 19 X: se o '\0' não vier, sobra X
    copia_classica(destino, "Porto Alegre");
    printf("copia_classica: %s (%zu letras)\n", destino, strlen(destino));
    return 0;
}
