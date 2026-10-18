// 0151 · Ordenação topológica
// Exercício E904 · ★★☆
//
// Este é o Kahn da obra do texto, agora com a duração de cada serviço em
// dias. Com equipes trabalhando em paralelo, um serviço começa no dia em
// que o ÚLTIMO dos que ele espera termina. Estenda o programa: mostre o
// dia de início e de fim de cada serviço, o prazo total e o caminho
// crítico (a corrente de serviços que, se atrasar um dia, atrasa a obra).
//
//   Saída esperada:
//   Fundação: dia 0 ao 10
//   Paredes: dia 10 ao 25
//   Elétrica: dia 25 ao 30
//   Hidráulica: dia 25 ao 31
//   Telhado: dia 25 ao 32
//   Piso: dia 31 ao 35
//   Reboco: dia 32 ao 40
//   Pintura: dia 40 ao 46
//   Obra pronta em 46 dias
//   Caminho crítico: Fundação -> Paredes -> Telhado -> Reboco -> Pintura
//
// Dicas:
// 1. Crie comeca[V] (zerado) e quem[V] (com -1). Ao tirar u da fila,
//    termina = comeca[u] + dias[u]. Para cada v com antes[u][v], se
//    termina > comeca[v], então comeca[v] = termina e quem[v] = u.
// 2. A ordem topológica garante que, quando v sai da fila, todos os que
//    ele espera já passaram: comeca[v] está pronto. O serviço que termina
//    por último dá o prazo; siga quem[] de trás para frente a partir dele.
// 3. Resposta esperada: a saída acima. O Reboco espera Telhado (32),
//    Elétrica (30) e Hidráulica (31): quem segura é o Telhado.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>

#define V 8

int main(void) {
    const char *tarefas[V] = {"Elétrica", "Fundação", "Hidráulica", "Paredes",
                              "Piso", "Pintura", "Reboco", "Telhado"};
    int dias[V] = {5, 10, 6, 15, 4, 6, 8, 7};
    int antes[V][V] = {0};
    int regras[][2] = {{1, 3}, {3, 7}, {3, 0}, {3, 2}, {7, 6},
                       {0, 6}, {2, 6}, {2, 4}, {6, 5}, {4, 5}};
    for (int k = 0; k < 10; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int grau[V] = {0};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];

    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v;

    (void)dias; // apague esta linha quando usar dias
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s\n", tarefas[u]);
        for (int v = 0; v < V; v++) {
            if (!antes[u][v]) continue;
            if (--grau[v] == 0) fila[fim++] = v;
        }
    }
    return 0;
}
