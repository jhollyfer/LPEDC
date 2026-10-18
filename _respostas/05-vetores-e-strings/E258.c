// 0043 · Juntando tudo
// Exercício E258 · ★★★

#include <stdio.h>
#include <string.h>

#define TAM_TEXTO 100

void comprimir(const char texto[], char saida[]) {
    int i = 0;
    int j = 0;
    while (texto[i] != '\0') {
        int conta = 1;
        while (conta < 9 && texto[i + conta] == texto[i]) {
            conta++;
        }
        saida[j++] = texto[i];
        saida[j++] = (char) ('0' + conta);
        i += conta;
    }
    saida[j] = '\0';
}

int main(void) {
    char texto[TAM_TEXTO];
    char saida[2 * TAM_TEXTO + 1];

    printf("Texto: ");
    if (fgets(texto, sizeof(texto), stdin) == NULL) {
        return 1;
    }
    texto[strcspn(texto, "\n")] = '\0';

    comprimir(texto, saida);
    size_t antes = strlen(texto);
    size_t depois = strlen(saida);
    printf("%s (%zu -> %zu)", saida, antes, depois);
    if (depois >= antes) {
        printf(": não compensa");
    }
    printf("\n");
    return 0;
}
