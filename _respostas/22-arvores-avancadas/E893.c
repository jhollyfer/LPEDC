// 0149 · Juntando tudo
// Exercício E893 · ★★★

#include <stdio.h>
#include <string.h>
#include "corretor.h"

// mostra c se estiver no dicionário e ainda não tiver sido mostrada
void mostra(const NoC *d, const char *c, char vistas[][COR_MAX], int *qtd) {
    if (!cor_contem(d, c)) {
        return;
    }
    for (int i = 0; i < *qtd; i++) {
        if (strcmp(vistas[i], c) == 0) {
            return;
        }
    }
    if (*qtd < 10) {
        strcpy(vistas[(*qtd)++], c);
        printf(" %s", c);
    }
}

void sugere(const NoC *d, const char *palavra) {
    char c[COR_MAX + 1], vistas[10][COR_MAX];
    int n = (int)strlen(palavra), qtd = 0;
    printf("%s:", palavra);
    for (int i = 0; i < n; i++) { // tirar a letra i
        memcpy(c, palavra, i);
        strcpy(c + i, palavra + i + 1);
        mostra(d, c, vistas, &qtd);
    }
    for (int i = 0; i <= n; i++) { // pôr uma letra na posição i (até depois da última)
        for (char l = 'a'; l <= 'z'; l++) {
            memcpy(c, palavra, i);
            c[i] = l;
            strcpy(c + i + 1, palavra + i);
            mostra(d, c, vistas, &qtd);
        }
    }
    printf(qtd == 0 ? " nenhuma\n" : "\n");
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *testes[] = {"pasou", "baratoo", "barat", "cas"};
    for (int i = 0; i < 4; i++) {
        sugere(dic, testes[i]);
    }
    cor_libera(dic);
    return 0;
}
