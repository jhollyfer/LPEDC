// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1715 · ★★☆ · O método do potencial no vetor que dobra

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int num, cap;
} Vetor;

int phi(const Vetor *v) { return 2 * v->num - v->cap; }

int insere(Vetor *v, int x) { // devolve o custo real
    int custo = 1;
    if (v->num == v->cap) {
        int nova = v->cap ? 2 * v->cap : 1;
        int *novo = malloc(nova * sizeof *novo);
        if (novo == NULL) exit(1);
        for (int i = 0; i < v->num; i++) { // cópia à mão: dá para contar
            novo[i] = v->item[i];
            custo++;
        }
        free(v->item);
        v->item = novo;
        v->cap = nova;
    }
    v->item[v->num++] = x;
    return custo;
}

int main(void) {
    Vetor v = {NULL, 0, 0};
    int soma_real = 0, soma_amort = 0;
    printf("num  cap  real  phi  amortizado\n");
    for (int i = 1; i <= 17; i++) {
        int antes = phi(&v);
        int c = insere(&v, 1000 + i); // número do pedido
        int amort = c + phi(&v) - antes;
        soma_real += c;
        soma_amort += amort;
        printf("%3d %4d %5d %4d %11d\n", v.num, v.cap, c, phi(&v), amort);
    }
    printf("Soma real: %d | soma amortizada: %d (3n = %d)\n", soma_real, soma_amort, 3 * 17);

    free(v.item);
    return 0;
}
