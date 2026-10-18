// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E576 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[10];
    int nota;
    int ordem;     // posição original: o desempate que torna o resultado estável
} Aluno;

int compara(const void *a, const void *b) {
    const Aluno *x = a;
    const Aluno *y = b;
    if (x->nota != y->nota) {
        return (x->nota < y->nota) - (x->nota > y->nota); // nota decrescente
    }
    return (x->ordem > y->ordem) - (x->ordem < y->ordem); // quem veio antes
}

int main(void) {
    Aluno turma[] = {          // já em ordem alfabética
        {"Ana", 8, 0}, {"Bruno", 9, 0}, {"Caio", 8, 0}, {"Duda", 7, 0},
        {"Enzo", 9, 0}, {"Fabi", 8, 0}, {"Gui", 7, 0},
    };
    size_t n = sizeof turma / sizeof turma[0];

    for (size_t i = 0; i < n; i++) {
        turma[i].ordem = (int) i;
    }
    qsort(turma, n, sizeof turma[0], compara);
    for (size_t i = 0; i < n; i++) {
        printf("%d %s\n", turma[i].nota, turma[i].nome);
    }
    return 0;
}
