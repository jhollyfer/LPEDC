// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2315 · ★★☆ · O union-find que solta galhos
//
// Ache o bug. O parque estadual vai ligar seis pontos com passarelas
// (custo em R$ mil, mão dupla), gastando o mínimo. O Kruskal abaixo
// compila e roda, mas a saída tem um ciclo (Portão-Lago, Portão-Mirante e
// Lago-Mirante) e o Camping ficou de fora:
//
//   Saída que aparece:
//   Portão-Lago (1)
//   Portão-Mirante (2)
//   Lago-Mirante (3)
//   Mirante-Gruta (4)
//   Gruta-Cachoeira (5)
//   Total: R$ 15 mil
//
// O erro está numa linha só, na hora de juntar dois grupos. Conserte.
//
//   Saída esperada:
//   Portão-Lago (1)
//   Portão-Mirante (2)
//   Mirante-Gruta (4)
//   Gruta-Cachoeira (5)
//   Cachoeira-Camping (6)
//   Total: R$ 18 mil
//
// Dicas:
// 1. Siga à mão: depois de Portão-Lago, pai[Portão] = Lago. O que acontece
//    com pai[Portão] quando Portão-Mirante entra? Para onde foi o Lago?
// 2. Mudar o pai de um vértice que não é raiz arranca ele (e quem está
//    pendurado nele) do grupo antigo. Só a RAIZ pode ganhar pai novo.
// 3. Resposta esperada: troque a linha por pai[ra] = rb; total R$ 18 mil,
//    com Lago-Mirante recusada e Cachoeira-Camping aceita.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo;
} Aresta;

const char *pontos[V] = {"Portão", "Lago", "Mirante", "Gruta", "Cachoeira", "Camping"};
int pai[V];

int acha(int x) {
    while (pai[x] != x) x = pai[x];
    return x;
}

int compara(const void *p, const void *q) {
    return ((const Aresta *)p)->custo - ((const Aresta *)q)->custo;
}

int main(void) {
    Aresta trilhas[E] = {{0, 1, 1}, {0, 2, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5},
                         {4, 5, 6}, {1, 5, 7}, {0, 3, 8}, {2, 5, 9}};
    qsort(trilhas, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int total = 0, aceitas = 0;
    for (int i = 0; i < E && aceitas < V - 1; i++) {
        int ra = acha(trilhas[i].a), rb = acha(trilhas[i].b);
        if (ra == rb) continue;
        pai[trilhas[i].a] = trilhas[i].b;
        aceitas++;
        total += trilhas[i].custo;
        printf("%s-%s (%d)\n", pontos[trilhas[i].a], pontos[trilhas[i].b], trilhas[i].custo);
    }
    printf("Total: R$ %d mil\n", total);
    return 0;
}
