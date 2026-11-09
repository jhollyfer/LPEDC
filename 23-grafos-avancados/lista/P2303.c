// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2303 · ★☆☆ · Referência circular na planilha
//
// Na planilha do orçamento, a fórmula de uma célula usa o valor de outras
// (seta a -> b: a fórmula de a usa b). Na planilha de maio:
//
//   A1 -> B1, B1 -> C1, C1 -> B2, B2 -> D1, D1 -> B1, A2 -> C2
//
// O programa abaixo já tem a DFS de três cores pela metade. Complete a
// função visita(u): além de achar a seta que chega num CINZA, ela guarda
// em pai[] quem descobriu cada célula e, ao achar o ciclo, guarda ini (a
// célula cinza) e fim (quem apontou para ela). A função confere já usa
// ini, fim e pai[] para mostrar o ciclo.
//
//   Saída esperada:
//   Planilha de maio: referência circular B1 -> C1 -> B2 -> D1 -> B1
//   Planilha de junho: sem referência circular
//
// Dicas:
// 1. Pinte u de CINZA ao entrar e de PRETO ao terminar o laço dos vizinhos.
// 2. Vizinho BRANCO: pai[v] = u e desce; se a descida achou, devolva true.
//    Vizinho CINZA: ini = v, fim = u, devolva true. PRETO: ignore.
// 3. Resposta esperada: B1 -> C1 -> B2 -> D1 -> B1 em maio; em junho, sem
//    a seta D1 -> B1, nenhum ciclo.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 7
enum { BRANCO, CINZA, PRETO };

const char *celulas[V] = {"A1", "A2", "B1", "B2", "C1", "C2", "D1"};
int usa[V][V]; // usa[a][b] = 1: a fórmula de a usa o valor de b
int cor[V];
int pai[V];
int ini, fim; // a seta fim -> ini chegou num cinza

bool visita(int u) {
    (void)u; // apague esta linha e escreva a DFS

    return false;
}

void confere(const char *rotulo) {
    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++) {
        if (cor[u] == BRANCO && visita(u)) {
            int caminho[V], n = 0;
            for (int x = fim; x != ini; x = pai[x]) caminho[n++] = x;
            caminho[n++] = ini;
            printf("%s: referência circular", rotulo);
            for (int k = n - 1; k >= 0; k--) printf(" %s ->", celulas[caminho[k]]);
            printf(" %s\n", celulas[ini]);
            return;
        }
    }
    printf("%s: sem referência circular\n", rotulo);
}

int main(void) {
    int refs[][2] = {{0, 2}, {2, 4}, {4, 3}, {3, 6}, {6, 2}, {1, 5}};
    for (int k = 0; k < 6; k++) usa[refs[k][0]][refs[k][1]] = 1;
    confere("Planilha de maio");

    usa[6][2] = 0; // D1 deixou de usar B1
    confere("Planilha de junho");
    return 0;
}
