// 0047 · Lendo strings
// Exercício E281 · ★★★

#include <stdio.h>
#include <string.h>

#define MAX_ITENS 5
#define TAM_ITEM 16

// joga fora o resto da linha e devolve quantos caracteres havia
int descartar_linha(void) {
    int c;
    int jogados = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        jogados++;
    }
    return jogados;
}

int main(void) {
    char itens[MAX_ITENS][TAM_ITEM];
    int n = 0;

    while (n < MAX_ITENS) {
        printf("Item: ");
        if (fgets(itens[n], sizeof(itens[n]), stdin) == NULL) {
            break;
        }
        size_t pos = strcspn(itens[n], "\n");
        if (itens[n][pos] == '\n') {
            itens[n][pos] = '\0';
        } else if (descartar_linha() > 0) {
            // se a linha tinha exatamente 15 caracteres, só o '\n' sobrou
            printf("(cortado)\n");
        }
        if (strlen(itens[n]) == 0) {
            break;
        }
        n++;
    }

    printf("Lista com %d itens:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, itens[i]);
    }

    if (n > 0) {
        int menor = 0;
        for (int i = 1; i < n; i++) {
            if (strcmp(itens[i], itens[menor]) < 0) {
                menor = i;
            }
        }
        printf("Primeiro em ordem alfabética: %s\n", itens[menor]);
    }
    return 0;
}
