// 0156 · Juntando tudo: o assistente do calouro
// Exercício E935 · ★★★
//
// Ache o bug. Este planejador deveria dividir a grade do texto em
// semestres, cursando em cada um tudo o que já está liberado. Mas ele põe
// a grade inteira no 1º semestre, inclusive C junto com Lógica, que é
// pré-requisito dela:
//
//   Saída que aparece:
//   1º semestre (2 na fila): Lógica Cálculo C Estruturas Arquivos Grafos Projeto
//
//   Saída esperada:
//   1º semestre (2 na fila): Lógica Cálculo
//   2º semestre (1 na fila): C
//   3º semestre (2 na fila): Estruturas Arquivos
//   4º semestre (1 na fila): Grafos
//   5º semestre (1 na fila): Projeto
//
// O programa compila e roda sem erro. O problema é de lógica, numa linha.
// Ache, conserte e confira.
//
// Dicas:
// 1. Quando Lógica sai da fila, C fica liberada e entra no fim da fila. O
//    laço de dentro continua enquanto inicio < fim. O fim acabou de crescer:
//    o que acontece com C?
// 2. A variável fim_semestre guarda onde a fila terminava quando o semestre
//    começou. Quem entrou depois dessa posição foi liberado DURANTE o
//    semestre e só pode ser cursado no próximo.
// 3. Resposta esperada: o laço de dentro deve ser
//    "while (inicio < fim_semestre)". Consertado, mostra a saída esperada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 7

const char *disc[V] = {"Lógica", "Cálculo", "C", "Estruturas", "Arquivos", "Grafos", "Projeto"};
int antes[V][V];

int main(void) {
    int regras[][2] = {{0, 2}, {2, 3}, {2, 4}, {1, 5}, {3, 5}, {4, 6}, {5, 6}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int grau[V] = {0};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];

    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v;

    int semestre = 0;
    while (inicio < fim) {
        int fim_semestre = fim; // o semestre é quem já está liberado agora
        printf("%dº semestre (%d na fila):", ++semestre, fim_semestre - inicio);
        while (inicio < fim) {
            int u = fila[inicio++];
            printf(" %s", disc[u]);
            for (int v = 0; v < V; v++)
                if (antes[u][v] && --grau[v] == 0) fila[fim++] = v; // fica para depois
        }
        printf("\n");
    }
    return 0;
}
