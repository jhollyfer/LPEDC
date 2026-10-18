// 0152 · Kruskal: árvore geradora mínima
// Exercício E908 · ★☆☆
//
// O campus vai ligar sete prédios com fibra óptica. O Kruskal abaixo está
// pronto, menos duas funções. Complete:
//
// - compara: o comparador do qsort, do trecho mais barato para o mais caro;
// - acha: o representante do grupo de x, com compressão de caminho.
//
//   Saída esperada:
//   Reitoria-Cantina: R$ 4 mil
//   Reitoria-Portaria: R$ 5 mil
//   Biblioteca-Cantina: R$ 6 mil
//   Biblioteca-Lab: R$ 7 mil
//   Auditório-Ginásio: R$ 8 mil
//   Cantina-Auditório: R$ 9 mil
//   Total: R$ 39 mil
//
// Dicas:
// 1. compara recebe dois const void *. Converta para const Aresta * e
//    devolva negativo, zero ou positivo: x->custo - y->custo.
// 2. acha: se pai[x] == x, x é a raiz. Senão, pai[x] = acha(pai[x]) e
//    devolva pai[x]. A atribuição é a compressão: x passa a apontar direto
//    para a raiz.
// 3. Resposta esperada: a saída acima. Os trechos de 10, 11 e 12 mil são
//    descartados (fechariam ciclo), e o laço para nas 6 fibras.
//
// Escreva sua resposta abaixo (complete compara e acha):

#include <stdio.h>
#include <stdlib.h>

#define V 7
#define E 11

typedef struct {
    int a, b, custo;
} Aresta;

const char *predios[V] = {"Reitoria", "Biblioteca", "Lab", "Ginásio", "Cantina", "Auditório", "Portaria"};
int pai[V];

int compara(const void *p, const void *q) {
    (void)p; // apague estas duas linhas
    (void)q;
    return 0;
}

int acha(int x) {
    return x; // troque pela versão com compressão de caminho
}

int main(void) {
    Aresta fibras[E] = {{0, 1, 12}, {0, 6, 5}, {1, 2, 7}, {2, 3, 15}, {1, 4, 6}, {4, 5, 9},
                        {5, 3, 8}, {2, 5, 10}, {6, 4, 11}, {3, 6, 20}, {0, 4, 4}};
    qsort(fibras, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int total = 0, usadas = 0;
    for (int k = 0; k < E && usadas < V - 1; k++) {
        int ra = acha(fibras[k].a), rb = acha(fibras[k].b);
        if (ra == rb) continue;
        pai[rb] = ra;
        usadas++;
        total += fibras[k].custo;
        printf("%s-%s: R$ %d mil\n", predios[fibras[k].a], predios[fibras[k].b], fibras[k].custo);
    }
    printf("Total: R$ %d mil\n", total);
    return 0;
}
