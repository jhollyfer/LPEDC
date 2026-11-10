// 0187 · Reduções
// Exercício E1119 · ★★☆
//
// O shopping vai abrir um corredor temático e quer o MAIOR grupo de lojas
// sem concorrência entre si (um conjunto independente). Você só tem a
// função maior_clique, pronta, que devolve a maior clique de um grafo como
// máscara de bits. Complete o main: monte o complemento de concorre em g2,
// chame a caixa-preta e mostre as lojas escolhidas e quantas são.
//
// Lojas: Açaí, Bazar, Café, Doces, Ervas, Farmácia, Gelato (0 a 6).
// Concorrem: Açaí-Café, Açaí-Doces, Açaí-Gelato, Bazar-Ervas, Café-Gelato,
// Doces-Gelato, Ervas-Farmácia, Farmácia-Gelato.
//
//   Saída esperada:
//   Lojas no corredor: Bazar Café Doces Farmácia (4)
//
// Escreva sua resposta abaixo (complete o main):

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *lojas[V] = {"Açaí", "Bazar", "Café", "Doces", "Ervas", "Farmácia", "Gelato"};
int concorre[V][V]; // 1 = as duas vendem algo em comum
int g2[V][V];

// caixa-preta: maior clique por força bruta (máscara de bits)
int maior_clique(int g[V][V]) {
    int melhor = 0, tam_melhor = 0;
    for (int m = 1; m < (1 << V); m++) {
        bool ok = true;
        int tam = 0;
        for (int a = 0; a < V && ok; a++) {
            if (!(m >> a & 1)) continue;
            tam++;
            for (int b = a + 1; b < V; b++)
                if ((m >> b & 1) && !g[a][b]) ok = false;
        }
        if (ok && tam > tam_melhor) melhor = m, tam_melhor = tam;
    }
    return melhor;
}

int main(void) {
    int pares[][2] = {{0, 2}, {0, 3}, {0, 6}, {1, 4}, {2, 6}, {3, 6}, {4, 5}, {5, 6}};
    for (int k = 0; k < 8; k++) concorre[pares[k][0]][pares[k][1]] = concorre[pares[k][1]][pares[k][0]] = 1;

    return 0;
}
