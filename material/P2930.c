// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2930 · ★★★ · A praça sem ruas
//
// O bairro tem as esquinas 0 a 5 com as ruas 0-1, 1-2, 2-0, 2-3, 3-4, 4-5,
// 5-2 (todos os graus pares) e acabou de ganhar a esquina 6, uma praça que
// ainda não tem rua nenhuma. O caminhão de lixo continua podendo passar por
// toda rua uma vez e voltar, mas o programa abaixo diz que não.
//
//   Saída que aparece:
//   Sem circuito: o bairro está partido
//
//   Saída esperada:
//   Tem circuito euleriano
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte-o.
//
// Dicas:
// 1. O teorema de Euler pede que as ARESTAS estejam num componente só.
//    Vértices de grau 0 não atrapalham nenhum circuito.
// 2. Na conferência da conexidade, ignore as esquinas com grau 0 (e comece a
//    DFS numa esquina com grau maior que 0).
// 3. Resposta esperada: a saída esperada acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 7

int rua[V][V];
bool visto[V];

void dfs(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (rua[u][v] && !visto[v]) dfs(v);
}

int main(void) {
    // o bairro ganhou a esquina 6 (praça nova), ainda sem rua nenhuma
    int r[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 2}};
    int grau[V] = {0};
    for (int k = 0; k < 7; k++) {
        rua[r[k][0]][r[k][1]] = rua[r[k][1]][r[k][0]] = 1;
        grau[r[k][0]]++, grau[r[k][1]]++;
    }
    dfs(0);
    for (int u = 0; u < V; u++)
        if (!visto[u]) {
            printf("Sem circuito: o bairro está partido\n");
            return 0;
        }
    for (int u = 0; u < V; u++)
        if (grau[u] % 2) {
            printf("Sem circuito: a esquina %d tem grau ímpar\n", u);
            return 0;
        }
    printf("Tem circuito euleriano\n");
    return 0;
}
