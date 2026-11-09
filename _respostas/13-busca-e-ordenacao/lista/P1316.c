// Lista · Módulo 13 · Busca e ordenação
// Exercício P1316 · ★★☆ · Classificação do concurso com desempate

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[12];
    int nota;
    int idade;
} Candidato;

// nota maior primeiro; empate: mais velho primeiro; empate: nome em ordem
int compara(const void *a, const void *b) {
    const Candidato *x = a, *y = b;
    if (x->nota != y->nota) {
        return (y->nota > x->nota) - (y->nota < x->nota);
    }
    if (x->idade != y->idade) {
        return (y->idade > x->idade) - (y->idade < x->idade);
    }
    return strcmp(x->nome, y->nome);
}

int main(void) {
    Candidato c[] = {
        {"Paulo", 82, 30}, {"Rita", 90, 25}, {"Lucas", 82, 41}, {"Ana", 82, 30},
        {"Bruna", 75, 52}, {"Igor", 90, 25}, {"Celia", 82, 41},
    };
    int n = 7;

    qsort(c, n, sizeof c[0], compara);
    for (int i = 0; i < n; i++) {
        printf("%dº %-6s nota %d, %d anos\n", i + 1, c[i].nome, c[i].nota, c[i].idade);
    }
    return 0;
}
