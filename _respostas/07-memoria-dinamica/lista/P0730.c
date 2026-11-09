// Lista · Módulo 07 · Memória dinâmica
// Exercício P0730 · ★★★ · O editor de linhas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool inserir(char ***doc, int *n, int *cap, int pos, const char *texto) {
    if (pos < 0 || pos > *n) {
        return false;
    }
    if (*n == *cap) {
        int nova = (*cap == 0) ? 2 : *cap * 2;
        char **novo = realloc(*doc, nova * sizeof *novo);
        if (novo == NULL) {
            return false;
        }
        *doc = novo;
        *cap = nova;
        printf("(capacidade %d)\n", nova);
    }
    char *copia = malloc(strlen(texto) + 1);
    if (copia == NULL) {
        return false;
    }
    strcpy(copia, texto);
    char **v = *doc;
    memmove(&v[pos + 1], &v[pos], (*n - pos) * sizeof *v); // empurra os ponteiros
    v[pos] = copia;
    (*n)++;
    return true;
}

void apagar(char **doc, int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        return;
    }
    free(doc[pos]); // a linha sai do heap antes de sair do vetor
    memmove(&doc[pos], &doc[pos + 1], (*n - pos - 1) * sizeof *doc);
    (*n)--;
}

int main(void) {
    char **doc = NULL;
    int n = 0, cap = 0;
    bool ok = inserir(&doc, &n, &cap, 0, "Ata da reunião do condomínio")
           && inserir(&doc, &n, &cap, 1, "Pauta: portão da garagem")
           && inserir(&doc, &n, &cap, 2, "Encerrada às 21h")
           && inserir(&doc, &n, &cap, 2, "Aprovado o conserto por R$ 850")
           && inserir(&doc, &n, &cap, 1, "Presentes: 14 moradores");
    if (ok) {
        apagar(doc, &n, 3);
        ok = inserir(&doc, &n, &cap, 3, "Aprovado o conserto por R$ 790");
    }
    if (ok) {
        for (int i = 0; i < n; i++) {
            printf("%d | %s\n", i + 1, doc[i]);
        }
        printf("%d linhas, capacidade %d\n", n, cap);
    }
    for (int i = 0; i < n; i++) {
        free(doc[i]);
    }
    free(doc);
    return ok ? 0 : 1;
}
