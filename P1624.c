// Lista · Módulo 16 · Grafos
// Exercício P1624 · ★★★ · Mesmo tempo, menos baldeações
//
// O app de ônibus calcula o trajeto mais rápido do Terminal 1, no Centro, até
// a Ponta Negra (minutos, mão dupla, no esqueleto). Só que há DOIS trajetos de
// 40 minutos: um com 4 trechos (4 ônibus) e outro com 2. O Dijkstra comum
// fica com o que encontrar primeiro.
//
// Escreva o Dijkstra O(V²) com uma chave de DOIS critérios: compare primeiro
// o tempo e, no empate, o número de trechos. Mostre o trajeto do Dijkstra
// comum e o do Dijkstra com desempate, com tempo e trechos.
//
//   Saída esperada:
//   Comum: Terminal 1 -> Cachoeirinha -> Sao Jorge -> Dom Pedro -> Ponta Negra (40 min, 4 trechos)
//   Com desempate: Terminal 1 -> Alvorada -> Ponta Negra (40 min, 2 trechos)
//
// Dicas:
// 1. Guarde dist[v] e trechos[v]. Uma função melhor(t1, b1, t2, b2) devolve
//    true se t1 < t2, ou se t1 == t2 e b1 < b2.
// 2. Use essa função nos dois lugares: na escolha do próximo vértice e no
//    relaxamento (o candidato é dist[u] + w com trechos[u] + 1).
// 3. Funciona porque a chave (tempo, trechos) só cresce ao andar por uma
//    aresta de peso >= 0: a mesma condição que deixa o Dijkstra correto.
// 4. Faça uma função só com um parâmetro bool desempata, para não escrever o
//    Dijkstra duas vezes.
// 5. Resposta esperada: o comum vai pelo Sao Jorge e Dom Pedro (4 trechos); o
//    com desempate vai pelo Alvorada (2 trechos); os dois levam 40 min.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"Terminal 1", "Cachoeirinha", "Sao Jorge", "Dom Pedro",
                        "Alvorada", "Ponta Negra", "Compensa"};
int w[V][V];

int main(void) {
    int trechos[][3] = {{0, 1, 8}, {1, 2, 8}, {2, 3, 8}, {3, 5, 16},
                        {0, 4, 30}, {4, 5, 10}, {0, 6, 12}, {6, 5, 35}};
    for (int k = 0; k < 8; k++) w[trechos[k][0]][trechos[k][1]] = w[trechos[k][1]][trechos[k][0]] = trechos[k][2];

    return 0;
}
