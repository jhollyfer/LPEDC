// Lista · Módulo 06 · Ponteiros
// Exercício P0625 · ★★★ · Conserte a escala de folgas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(const char **a, const char **b) { // recebe o endereço das gavetas
    const char *aux = *a;
    *a = *b;
    *b = aux;
}

int compara(const void *a, const void *b) {
    return strcmp(*(const char **) a, *(const char **) b); // a gaveta guarda um ponteiro
}

void mostrar(const char *titulo, const char **v, int n) {
    printf("%s:", titulo);
    for (int i = 0; i < n; i++) {
        printf(" %s", v[i]);
    }
    printf("\n");
}

int main(void) {
    const char *equipe[5] = {"Joana", "Rui", "Mirela", "Edson", "Wellington"};

    troca(&equipe[0], &equipe[4]);
    mostrar("Trocados", equipe, 5);
    qsort(equipe, 5, sizeof equipe[0], compara);
    mostrar("Em ordem", equipe, 5);

    char cracha[16]; // "Wellington" tem 10 letras + '\0'
    strcpy(cracha, equipe[4]);
    printf("Crachá do último: %s\n", cracha);
    return 0;
}
