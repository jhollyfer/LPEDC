// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2016 · ★★☆ · O menor atraso da gráfica

#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct {
    const char *nome;
    int dur, prazo;
} Encomenda;

int por_prazo(const void *a, const void *b) {
    const Encomenda *x = a, *y = b;
    return x->prazo - y->prazo;
}

void simula(const char *titulo, const Encomenda e[]) {
    printf("%s:\n", titulo);
    int hora = 0, pior = 0;
    for (int i = 0; i < N; i++) {
        int ini = hora;
        hora += e[i].dur;
        int atraso = hora > e[i].prazo ? hora - e[i].prazo : 0;
        if (atraso > pior) {
            pior = atraso;
        }
        printf("  %s: %d a %d (prazo %d, atraso %d)\n", e[i].nome, ini, hora, e[i].prazo, atraso);
    }
    printf("  Maior atraso: %d h\n", pior);
}

int main(void) {
    Encomenda e[N] = {{"convites", 3, 6}, {"cardápios", 2, 4}, {"banner", 4, 10}, {"folhetos", 1, 3}, {"crachás", 2, 7}};
    simula("Ordem da tabela", e);
    qsort(e, N, sizeof e[0], por_prazo);
    simula("Prazo mais cedo primeiro", e);
    return 0;
}
