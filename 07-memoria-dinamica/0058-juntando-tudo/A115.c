// A115 · A agenda em que cada linha cresce sozinha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cópia de uma string num bloco do tamanho exato.
char *duplicar(const char *texto) {
    char *copia = malloc(strlen(texto) + 1);
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

// Põe um horário na linha do barbeiro b. Só ESSA linha cresce: as outras
// nem ficam sabendo. Devolve 0 se faltar memória.
int agendar(int **horarios, int *qtd, int *cap, int b, int hora) {
    if (qtd[b] == cap[b]) {
        int nova = cap[b] == 0 ? 1 : cap[b] * 2;
        int *maior = realloc(horarios[b], nova * sizeof *maior); // NULL na 1ª vez
        if (maior == NULL) {
            return 0;
        }
        horarios[b] = maior;
        cap[b] = nova;
    }
    horarios[b][qtd[b]] = hora;
    qtd[b]++;
    return 1;
}

void liberar(char **nomes, int **horarios, int *qtd, int *cap, int n) {
    for (int b = 0; b < n; b++) {
        free(nomes[b]);    // cada nome é um bloco
        free(horarios[b]); // cada linha também (free(NULL) não faz nada)
    }
    free(nomes);
    free(horarios);
    free(qtd);
    free(cap);
}

int main(void) {
    const char *equipe[] = {"Juca", "Neide", "Rafa"};
    int n = 3;

    // calloc: linhas começam NULL e contadores começam em 0
    char **nomes = calloc(n, sizeof *nomes);
    int **horarios = calloc(n, sizeof *horarios);
    int *qtd = calloc(n, sizeof *qtd);
    int *cap = calloc(n, sizeof *cap);
    if (nomes == NULL || horarios == NULL || qtd == NULL || cap == NULL) {
        liberar(nomes, horarios, qtd, cap, 0);
        return 1;
    }
    for (int b = 0; b < n; b++) {
        nomes[b] = duplicar(equipe[b]);
        if (nomes[b] == NULL) {
            liberar(nomes, horarios, qtd, cap, n);
            return 1;
        }
    }

    // pedidos do dia: barbeiro escolhido e horário
    int quem[] = {1, 0, 1, 1, 2, 1, 0};
    int hora[] = {9, 10, 11, 13, 14, 15, 16};
    for (int k = 0; k < 7; k++) {
        if (!agendar(horarios, qtd, cap, quem[k], hora[k])) {
            liberar(nomes, horarios, qtd, cap, n);
            return 1;
        }
    }

    for (int b = 0; b < n; b++) {
        printf("%-6s (%d de %d):", nomes[b], qtd[b], cap[b]);
        for (int j = 0; j < qtd[b]; j++) {
            printf(" %dh", horarios[b][j]);
        }
        printf("\n");
    }

    liberar(nomes, horarios, qtd, cap, n);
    return 0;
}
// Saída:
// Juca   (2 de 2): 10h 16h
// Neide  (4 de 4): 9h 11h 13h 15h
// Rafa   (1 de 1): 14h
//
// É uma matriz irregular que muda de forma enquanto o programa roda: a linha
// da Neide cresceu 1 -> 2 -> 4 e a do Rafa ficou com 1. No fim existem 10
// blocos (4 de controle, 3 nomes e 3 linhas), e liberar faz 10 free.
