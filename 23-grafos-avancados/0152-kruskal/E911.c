// 0152 · Kruskal: árvore geradora mínima
// Exercício E911 · ★★★
//
// Ache o bug. O parque de diversões vai ligar seis atrações com os trilhos
// de um trenzinho, gastando o mínimo (custos em R$ mil). O programa abaixo
// tem um erro de lógica numa linha só. Rode e repare: Entrada-Roda (7)
// entra, mas Entrada, Carrossel, Lago e Roda já estavam ligados, ou seja,
// fechou um ciclo. E a Montanha ficou sem trilho nenhum.
//
//   Saída que aparece:
//   Entrada-Carrossel (4)
//   Roda-Lago (5)
//   Carrossel-Lago (6)
//   Entrada-Roda (7)
//   Lago-Castelo (8)
//   Total: R$ 30 mil
//
//   Saída esperada:
//   Entrada-Carrossel (4)
//   Roda-Lago (5)
//   Carrossel-Lago (6)
//   Lago-Castelo (8)
//   Castelo-Montanha (9)
//   Total: R$ 32 mil
//
// Ache a linha, conserte e confira a saída.
//
// Dicas:
// 1. Desenhe o vetor pai[] depois de cada aresta aceita. Depois de
//    Roda-Lago, quem é o pai do Lago? E depois de Carrossel-Lago?
// 2. Quando o Lago troca de pai, a Roda, que estava pendurada nele pelo
//    caminho, perde a ligação com o grupo. A união tem que ligar as RAÍZES
//    dos dois grupos, não os vértices da aresta.
// 3. Resposta esperada: troque "pai[t[k].b] = t[k].a;" por
//    "pai[rb] = ra;". Consertado, mostra a saída esperada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo;
} Aresta;

const char *atracoes[V] = {"Entrada", "Carrossel", "Roda", "Lago", "Castelo", "Montanha"};
int pai[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

int compara(const void *p, const void *q) {
    const Aresta *x = p, *y = q;
    return x->custo - y->custo;
}

int main(void) {
    Aresta t[E] = {{0, 1, 4}, {2, 3, 5}, {1, 3, 6}, {0, 2, 7}, {3, 4, 8},
                   {4, 5, 9}, {2, 5, 10}, {1, 4, 11}, {0, 5, 12}};
    qsort(t, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int total = 0, usados = 0;
    for (int k = 0; k < E && usados < V - 1; k++) {
        int ra = acha(t[k].a), rb = acha(t[k].b);
        if (ra == rb) continue;
        pai[t[k].b] = t[k].a; // junta os dois grupos
        usados++;
        total += t[k].custo;
        printf("%s-%s (%d)\n", atracoes[t[k].a], atracoes[t[k].b], t[k].custo);
    }
    printf("Total: R$ %d mil\n", total);
    return 0;
}
