// 0057 · Erros de memória
// Exercício E341 · ★★★

#include <stdio.h>
#include <stdlib.h>

// Devolve 1 se deu certo, 0 se faltou memória.
int adicionar(int **v, int *qtd, int *cap, int matricula) {
    if (*qtd == *cap) {
        int *maior = realloc(*v, 2 * *cap * sizeof **v);
        if (maior == NULL) {
            return 0;
        }
        *v = maior; // o ponteiro do main recebe o endereço novo
        *cap *= 2;
    }
    (*v)[*qtd] = matricula;
    (*qtd)++;
    return 1;
}

int main(void) {
    int qtd = 0;
    int cap = 2;
    int *alunos = malloc(cap * sizeof *alunos);
    if (alunos == NULL) {
        return 1;
    }
    int chegadas[] = {11, 27, 35, 48};
    for (int i = 0; i < 4; i++) {
        if (!adicionar(&alunos, &qtd, &cap, chegadas[i])) {
            free(alunos);
            return 1;
        }
    }
    printf("Presentes:");
    for (int i = 0; i < qtd; i++) {
        printf(" %d", alunos[i]);
    }
    printf("\n");
    free(alunos);
    return 0;
}
