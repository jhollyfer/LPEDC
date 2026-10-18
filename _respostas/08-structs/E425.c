// 0071 · Juntando tudo: o cardápio
// Exercício E425 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { BAIXA, MEDIA, ALTA } Prioridade;

#define TRABALHO (1u << 0)
#define CASA     (1u << 1)
#define URGENTE  (1u << 2)

typedef struct {
    char titulo[24];
    Prioridade prioridade;
    int prazo;
    unsigned tags;
} Tarefa;

int comparar(const void *a, const void *b) {
    const Tarefa *x = a;
    const Tarefa *y = b;
    if (x->prioridade != y->prioridade) return (int)y->prioridade - (int)x->prioridade;
    if (x->prazo != y->prazo) return x->prazo - y->prazo;
    return strcmp(x->titulo, y->titulo);
}

void mostrar(const Tarefa *t) {
    const char *nomes[] = {"baixa", "média", "alta"};
    printf("[%s] dia %d: %s\n", nomes[t->prioridade], t->prazo, t->titulo);
}

int main(void) {
    const Tarefa modelo[] = {
        {"Pagar aluguel", ALTA, 5, CASA | URGENTE},
        {"Revisar PR", MEDIA, 3, TRABALHO},
        {"Comprar ração", BAIXA, 8, CASA},
        {"Deploy da API", ALTA, 2, TRABALHO | URGENTE},
        {"Reunião 1:1", MEDIA, 3, TRABALHO},
        {"Lavar o carro", BAIXA, 12, CASA},
    };
    int n = sizeof modelo / sizeof modelo[0];

    Tarefa *agenda = malloc(n * sizeof *agenda);
    if (agenda == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        agenda[i] = modelo[i];
    }

    qsort(agenda, n, sizeof *agenda, comparar);
    for (int i = 0; i < n; i++) {
        mostrar(&agenda[i]);
    }
    printf("Trabalho:\n");
    for (int i = 0; i < n; i++) {
        if ((agenda[i].tags & TRABALHO) != 0) {
            mostrar(&agenda[i]);
        }
    }

    free(agenda);
    return 0;
}
