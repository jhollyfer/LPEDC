// 0048 · Ponteiros e strings
// Exercício E285 · ★★☆
//
// Resposta: na versão clássica, *destino++ = *origem++ copia um caractere
// e depois avança os dois ponteiros; o valor da atribuição é o caractere
// copiado, então o laço para logo depois de copiar o '\0' (que vale 0).

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

void copia_classica(char *destino, const char *origem) {
    while ((*destino++ = *origem++) != '\0') {
    }
}

int main(void) {
    char destino[20];

    copia(destino, "Porto Alegre");
    printf("Destino: %s (%zu letras)\n", destino, strlen(destino));
    copia_classica(destino, "Porto Alegre");
    printf("Destino: %s (%zu letras)\n", destino, strlen(destino));
    return 0;
}
