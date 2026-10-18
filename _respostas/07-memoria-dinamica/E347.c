// 0058 · Juntando tudo
// Exercício E347 · ★★★
//
// (a) copiar fazia malloc(strlen(s)), sem lugar para o '\0':
//     heap-buffer-overflow no strcpy.
// (b) o fim liberava só nomes: os 3 nomes vazavam (o LeakSanitizer lista
//     3 blocos). Agora há um free por nome antes do free(nomes).
// (c) nomes = realloc(nomes, ...) perdia o bloco antigo se o realloc
//     falhasse. Agora usa um temporário e libera tudo no caminho de erro.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copiar(const char *s) {
    char *c = malloc(strlen(s) + 1);
    if (c != NULL) {
        strcpy(c, s);
    }
    return c;
}

void liberar(char **nomes, int qtd) {
    for (int i = 0; i < qtd; i++) {
        free(nomes[i]);
    }
    free(nomes);
}

int main(void) {
    const char *quem[] = {"Cida", "Jorge", "Bia"};
    int deve[] = {12, 8, 20};
    int cap = 1;
    int qtd = 0;
    char **nomes = malloc(cap * sizeof *nomes);
    if (nomes == NULL) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (qtd == cap) {
            char **maior = realloc(nomes, 2 * cap * sizeof *nomes);
            if (maior == NULL) {
                liberar(nomes, qtd);
                return 1;
            }
            nomes = maior;
            cap *= 2;
        }
        nomes[qtd] = copiar(quem[i]);
        if (nomes[qtd] == NULL) {
            liberar(nomes, qtd);
            return 1;
        }
        qtd++;
    }
    for (int i = 0; i < qtd; i++) {
        printf("%s: R$ %d\n", nomes[i], deve[i]);
    }
    liberar(nomes, qtd);
    return 0;
}
// Saída:
// Cida: R$ 12
// Jorge: R$ 8
// Bia: R$ 20
