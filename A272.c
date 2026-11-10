// A272 · Juntar planilhas pelo menor custo: o mesmo guloso, sem árvore

#include <stdio.h>

// heap de mínimo de int, escrito aqui mesmo (bem menor que o do huffman.c)
typedef struct {
    int v[16];
    int n;
} Heap;

void poe(Heap *h, int x) {
    int i = h->n++;
    h->v[i] = x;
    while (i > 0 && h->v[i] < h->v[(i - 1) / 2]) {
        int t = h->v[i];
        h->v[i] = h->v[(i - 1) / 2];
        h->v[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

int tira(Heap *h) {
    int topo = h->v[0];
    h->v[0] = h->v[--h->n];
    int i = 0;
    while (2 * i + 1 < h->n) {
        int f = 2 * i + 1;
        if (f + 1 < h->n && h->v[f + 1] < h->v[f]) {
            f++;
        }
        if (h->v[i] <= h->v[f]) {
            break;
        }
        int t = h->v[i];
        h->v[i] = h->v[f];
        h->v[f] = t;
        i = f;
    }
    return topo;
}

int main(void) {
    // mil linhas de cada planilha de vendas, já ordenadas por data.
    // Juntar (intercalar) duas custa a soma das linhas das duas.
    int linhas[] = {12, 40, 7, 25, 18};
    int n = 5;

    // na ordem em que chegaram: junta a 1ª com a 2ª, o resultado com a 3ª...
    int acumulado = linhas[0], custo_ordem = 0;
    for (int i = 1; i < n; i++) {
        acumulado += linhas[i];
        custo_ordem += acumulado;
    }
    printf("Na ordem de chegada: %d mil linhas lidas\n", custo_ordem);

    // guloso de Huffman: sempre as duas MENORES
    Heap h = {.n = 0};
    for (int i = 0; i < n; i++) {
        poe(&h, linhas[i]);
    }
    int custo = 0;
    while (h.n > 1) {
        int a = tira(&h);
        int b = tira(&h);
        printf("  junta %2d + %2d = %3d\n", a, b, a + b);
        custo += a + b;
        poe(&h, a + b);
    }
    printf("As duas menores primeiro: %d mil linhas lidas\n", custo);
    // cada planilha é relida uma vez por junção de que participa: a
    // "profundidade" dela na árvore das junções. Exatamente a conta do Huffman.
    return 0;
}
// Saída:
// Na ordem de chegada: 297 mil linhas lidas
//   junta  7 + 12 =  19
//   junta 18 + 19 =  37
//   junta 25 + 37 =  62
//   junta 40 + 62 = 102
// As duas menores primeiro: 220 mil linhas lidas
