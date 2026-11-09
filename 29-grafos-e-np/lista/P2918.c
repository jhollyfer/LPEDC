// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2918 · ★★☆ · Clique pelo resolvedor de independente
//
// Agora o contrário do 0187: você só tem uma caixa-preta que acha o MAIOR
// CONJUNTO INDEPENDENTE (já pronta no esqueleto) e precisa achar a maior
// clique de uma rede de colaboração entre sete pesquisadores (0 a 6):
//
//   0-1, 0-2, 0-3, 1-2, 1-3, 2-3, 2-4, 3-4, 4-5, 5-6, 4-6
//
// Complete o main: monte o complemento, chame maior_independente nele e
// mostre a clique e o tamanho. Mostre também a menor cobertura de
// vértices do COMPLEMENTO (o resto dos vértices).
//
//   Saída esperada:
//   Maior clique: 0 1 2 3 (4)
//   Cobertura do complemento: 4 5 6 (3)
//
// Dicas:
// 1. comp[a][b] = a != b && !g[a][b]. Independente no complemento é clique em
//    G.
// 2. O bit v da máscara diz se v está no conjunto; o resto é todos & ~s.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o main):

#include <stdbool.h>
#include <stdio.h>

#define V 7

int g[V][V], comp[V][V];

// caixa-preta: maior conjunto independente por força bruta (máscara)
int maior_independente(int h[V][V]) {
    int melhor = 0, tam_melhor = 0;
    for (int m = 1; m < (1 << V); m++) {
        bool ok = true;
        int tam = 0;
        for (int a = 0; a < V; a++) {
            if (!(m >> a & 1)) continue;
            tam++;
            for (int b = a + 1; b < V; b++)
                if ((m >> b & 1) && h[a][b]) ok = false;
        }
        if (ok && tam > tam_melhor) melhor = m, tam_melhor = tam;
    }
    return melhor;
}

void mostra(const char *rotulo, int m) {
    int tam = 0;
    printf("%s:", rotulo);
    for (int v = 0; v < V; v++)
        if (m >> v & 1) printf(" %d", v), tam++;
    printf(" (%d)\n", tam);
}

int main(void) {
    int e[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {4, 6}};
    for (int k = 0; k < 11; k++) g[e[k][0]][e[k][1]] = g[e[k][1]][e[k][0]] = 1;

    return 0;
}
