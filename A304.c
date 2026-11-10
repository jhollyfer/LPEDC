// A304 · A árvore de MAIOR soma: o melhor sinal do Wi-Fi mesh

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 10

typedef struct {
    int a, b, sinal; // qualidade do sinal entre dois roteadores, de 0 a 100
} Link;

const char *pontos[V] = {"Sala", "Cozinha", "Quarto", "Escritório", "Varanda", "Garagem"};
int pai[V];

int acha(int v) {
    if (pai[v] != v) pai[v] = acha(pai[v]);
    return pai[v];
}

int do_maior(const void *p, const void *q) { // ordem DECRESCENTE
    const Link *x = p, *y = q;
    return y->sinal - x->sinal;
}

int main(void) {
    Link links[E] = {{0, 1, 92}, {0, 2, 70}, {0, 3, 85}, {1, 2, 40}, {1, 4, 66},
                     {2, 3, 88}, {3, 4, 35}, {4, 5, 58}, {1, 5, 61}, {2, 5, 20}};
    qsort(links, E, sizeof(Link), do_maior);

    for (int v = 0; v < V; v++) pai[v] = v;
    int soma = 0, pior = 100, usados = 0;
    for (int k = 0; k < E && usados < V - 1; k++) {
        int ra = acha(links[k].a), rb = acha(links[k].b);
        if (ra == rb) continue; // já tem caminho melhor entre os dois
        pai[rb] = ra;
        usados++;
        soma += links[k].sinal;
        if (links[k].sinal < pior) pior = links[k].sinal;
        printf("%s - %s: %d\n", pontos[links[k].a], pontos[links[k].b], links[k].sinal);
    }
    printf("Soma dos sinais: %d; elo mais fraco: %d\n", soma, pior);
    return 0;
}
// Saída:
// Sala - Cozinha: 92
// Quarto - Escritório: 88
// Sala - Escritório: 85
// Cozinha - Varanda: 66
// Cozinha - Garagem: 61
// Soma dos sinais: 392; elo mais fraco: 61
//
// Basta inverter a ordem do qsort. Bônus: o elo mais fraco desta árvore é o
// maior possível. Nenhuma outra árvore que liga a casa toda tem todos os
// links com sinal acima de 61.
