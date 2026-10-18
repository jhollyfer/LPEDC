// linhas.c · implementação de linhas.h
#include "linhas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHA 256 // maior linha aceita (o resto da linha vira outra linha)

char **le_linhas(const char *nome, int *n) {
    FILE *arq = fopen(nome, "r");
    if (arq == NULL) {
        perror(nome);
        return NULL;
    }
    int cap = 8;
    char **v = malloc(cap * sizeof *v);
    char buf[LINHA];
    *n = 0;
    while (v != NULL && fgets(buf, sizeof buf, arq) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';      // tira o '\n', se houver
        if (*n == cap) {                     // cheio: dobra (assunto 0055)
            char **novo = realloc(v, 2 * cap * sizeof *v);
            if (novo == NULL) {
                break;                       // sem memória: fica com o que leu
            }
            v = novo;
            cap *= 2;
        }
        v[*n] = malloc(strlen(buf) + 1);     // cada linha do tamanho exato
        if (v[*n] == NULL) {
            break;
        }
        strcpy(v[*n], buf);
        (*n)++;
    }
    fclose(arq);
    return v;
}

void libera_linhas(char **v, int n) {
    if (v == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
}

int grava_linhas(const char *nome, const char *linhas[], int n) {
    FILE *arq = fopen(nome, "w");
    if (arq == NULL) {
        perror(nome);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(arq, "%s\n", linhas[i]);
    }
    fclose(arq);
    return 0;
}
