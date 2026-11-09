// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0517 · ★★☆ · Arrumando os espaços do endereço

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void normalizar(char s[]) {
    int k = 0;
    bool pendente = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            pendente = true; // decide depois
            continue;
        }
        if (pendente && k > 0 && s[i] != ',') {
            s[k++] = ' ';
        }
        pendente = false;
        s[k++] = s[i];
    }
    s[k] = '\0';
}

int main(void) {
    char end[] = "   Av.   Eduardo    Ribeiro ,  620   ";

    printf("Antes:  [%s] (%zu)\n", end, strlen(end));
    normalizar(end);
    printf("Depois: [%s] (%zu)\n", end, strlen(end));
    return 0;
}
