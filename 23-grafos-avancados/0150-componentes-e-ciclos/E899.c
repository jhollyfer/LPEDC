// 0150 · Componentes e ciclos
// Exercício E899 · ★★★
//
// Ache o bug. Este programa confere se a grade de um curso tem pré-requisito
// circular (seta a -> b: a disciplina a vem antes de b). A grade 2024 não
// tem ciclo nenhum; a grade 2025 ganhou uma seta Grafos -> Cálculo e passou
// a ter. Mas o programa acusa ciclo nas duas:
//
//   Saída que aparece:
//   Grade 2024: pré-requisito circular
//   Grade 2025: pré-requisito circular
//
//   Saída esperada:
//   Grade 2024: sem ciclo
//   Grade 2025: pré-requisito circular
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte a
// DFS para que ela dê a saída esperada.
//
// Dicas:
// 1. Na grade 2024, siga a DFS a partir de Lógica: ela desce por C,
//    Estruturas, Grafos e Arquivos. Depois Lógica olha Estruturas, que já
//    foi visitada. Isso é ciclo?
// 2. "Já visitado" não quer dizer "está na pilha". Troque o bool por três
//    estados: branco (nunca visto), cinza (na pilha) e preto (terminado).
// 3. Resposta esperada: a saída esperada acima. Só é ciclo a seta para um
//    vértice cinza; ao terminar o laço dos vizinhos, pinte u de preto.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *disciplinas[V] = {"Lógica", "C", "Estruturas", "Arquivos", "Grafos", "Cálculo", "Discreta"};
int antes[V][V]; // antes[a][b] = 1: a é pré-requisito de b
bool visitado[V];

bool dfs(int u) {
    visitado[u] = true;
    for (int v = 0; v < V; v++) {
        if (!antes[u][v]) continue;
        if (visitado[v]) return true; // já vi: ciclo?
        if (dfs(v)) return true;
    }
    return false;
}

bool tem_ciclo(void) {
    for (int u = 0; u < V; u++) visitado[u] = false;
    for (int u = 0; u < V; u++)
        if (!visitado[u] && dfs(u)) return true;
    return false;
}

int main(void) {
    int grade[][2] = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {0, 2}, {5, 6}, {6, 4}};
    for (int k = 0; k < 7; k++) antes[grade[k][0]][grade[k][1]] = 1;
    printf("Grade 2024: %s\n", tem_ciclo() ? "pré-requisito circular" : "sem ciclo");

    antes[4][5] = 1; // Grafos -> Cálculo
    printf("Grade 2025: %s\n", tem_ciclo() ? "pré-requisito circular" : "sem ciclo");
    return 0;
}
